#ifndef RLEENCODER_HPP
#define RLEENCODER_HPP

#include <cstddef>
#include <cstdint>
namespace graph_storage {
namespace virtual_memory {

namespace rle {

// #define RLE_WORD_SIZE_16
// 16-bits run-length word allows for very long sequences,
// but is also very inefficient if the run-lengths are generally
// short. Byte-size words are used if this is not defined.
//
#ifdef RLE_WORD_SIZE_16
using RleWord = std::uint16_t;
constexpr RleWord max_run_length = RleWord(0xFFFF); // Max run length: 65535 => 4 bytes.
#else                                               // !RLE_WORD_SIZE_16
using RleWord = std::uint8_t;
constexpr RleWord max_run_length = RleWord(0xFF); // Max run length: 255 => 2 bytes.
#endif                                              // RLE_WORD_SIZE_16

} // namespace rle

class RleEncoder {
public:
    static std::size_t encode_value(const std::uint8_t *input, const int in_size_bytes, std::uint8_t *output,
                                    const int out_size_bytes) {
        if (input == nullptr || output == nullptr) {
            return -1;
        }
        if (in_size_bytes <= 0 || in_size_bytes <= 0) {
            return -1;
        }

        std::size_t bytes_written = 0;
        rle::RleWord rle_count = 0;
        std::uint8_t rle_byte = *input;

        for (int i = 0; i < in_size_bytes; ++i, ++rle_count) {
            const std::uint8_t b = *input++;

            // Output when we hit the end of a sequence or the max size of a RLE word:
            if (b != rle_byte || rle_count == rle::max_run_length) {
                if ((bytes_written + sizeof(rle::RleWord) + sizeof(std::uint8_t)) >
                    static_cast<unsigned>(out_size_bytes)) {
                    // Can't fit anymore data! Stop with an error.
                    return -1;
                }
                bytes_written += write_data(output, rle_count);
                bytes_written += write_data(output, rle_byte);
                rle_count = 0;
                rle_byte = b;
            }
        }

        // Residual count at the end:
        if (rle_count != 0) {
            if ((bytes_written + sizeof(rle::RleWord) + sizeof(std::uint8_t)) > static_cast<unsigned>(out_size_bytes)) {
                return -1; // No more space! Output not complete.
            }
            bytes_written += write_data(output, rle_count);
            bytes_written += write_data(output, rle_byte);
        }

        return bytes_written;
    }

    static std::size_t decode_value(const std::uint8_t *input, const int in_size_bytes, std::uint8_t *output,
                                    const int out_size_bytes) {
        if (input == nullptr || output == nullptr) {
            return -1;
        }
        if (in_size_bytes <= 0 || out_size_bytes <= 0) {
            return -1;
        }

        int bytes_written = 0;
        rle::RleWord rle_count = 0;
        std::uint8_t rle_byte = 0;

        for (int i = 0; i < in_size_bytes; i += sizeof(rle_count) + sizeof(rle_byte)) {
            read_data(input, rle_count);
            read_data(input, rle_byte);

            // Replicate the RLE packet.
            while (rle_count--) {
                *output++ = rle_byte;
                if (++bytes_written == out_size_bytes && rle_count != 0) {
                    // Reached end of output and we are not done yet, stop with an error.
                    return -1;
                }
            }
        }

        return bytes_written;
    }

private:
    template <typename T>
    static int write_data(std::uint8_t *&output, const T val) {
        *reinterpret_cast<T *>(output) = val;
        output += sizeof(T);
        return sizeof(T);
    }

    template <typename T>
    static void read_data(const std::uint8_t *&input, T &val) {
        val = *reinterpret_cast<const T *>(input);
        input += sizeof(T);
    }
};

} // namespace virtual_memory
} // namespace graph_storage

#endif

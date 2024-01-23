#include "gtest/gtest.h"
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <gtest/gtest-param-test.h>
#include <tuple>
#include <vector>

#include "virtual_memory/RleEncoder.hpp"

namespace graph_storage {
namespace virtual_memory {

// A binary dump of "lenna.tga", the classic Computer Graphics
// sample image. Size is 256x256 pixels, RGBA uncompressed.
// This is meant to stress test the algorithms, since the
// buffer is fairly large
#include "data/lenna_tga.hpp"

// 512 randomly shuffled byte values
#include "data/random_512.hpp"

// A couple strings:
static const std::uint8_t str0[] = "Hello world!";
static const std::uint8_t str1[] = "The Essential Feature;";
static const std::uint8_t str2[] = "Hello Dr. Chandra, my name is HAL-9000. I'm ready for my first lesson...";
static const std::uint8_t str3[] = "\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11";

class RleEncodingTestSuite : public testing::TestWithParam<std::tuple<const std::uint8_t *, const std::size_t>> {};

TEST_P(RleEncodingTestSuite, encode_and_decode_is_equal) {
    auto [sampleData, sampleSize] = GetParam();
    std::vector<std::uint8_t> compressedBuffer(sampleSize * 4, 0); // RLE might make things bigger.
    std::vector<std::uint8_t> uncompressedBuffer(sampleSize, 0);

    // Compress:
    const std::size_t compressedSize =
        RleEncoder::encode_value(sampleData, sampleSize, compressedBuffer.data(), compressedBuffer.size());

    std::cout << "RLE compressed size bytes   = " << compressedSize << "\n";
    std::cout << "RLE uncompressed size bytes = " << sampleSize << "\n";

    // Restore:
    const std::size_t uncompressedSize = RleEncoder::decode_value(compressedBuffer.data(), compressedSize,
                                                                  uncompressedBuffer.data(), uncompressedBuffer.size());

    ASSERT_EQ(uncompressedSize, sampleSize);
    ASSERT_EQ(std::memcmp(uncompressedBuffer.data(), sampleData, sampleSize), 0);
}

INSTANTIATE_TEST_SUITE_P(RleRandom512, RleEncodingTestSuite,
                         testing::Values(std::make_tuple(random512, sizeof(random512)),
                                         std::make_tuple(str0, sizeof(str0)), std::make_tuple(str1, sizeof(str1)),
                                         std::make_tuple(str2, sizeof(str2)), std::make_tuple(str3, sizeof(str3)),
                                         std::make_tuple(lennaTgaData, sizeof(lennaTgaData))));

} // namespace virtual_memory
} // namespace graph_storage

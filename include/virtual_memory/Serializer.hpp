#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "storage/FileInfo.hpp"
#include "storage/FileUtils.hpp"
#include <cstddef>

namespace graph_storage {
namespace virtual_memory {

using namespace storage;

class Serializer {
public:
    template <typename T>
    static std::size_t serialize_value(const T &value, FileInfo *file_info, std::size_t offset) {
        FileUtils::write_to_file(file_info, (uint8_t *)&value, sizeof(T), offset);
        return offset + sizeof(T);
    }

    template <typename T>
    static std::size_t deserialize_value(T &value, FileInfo *file_info, std::size_t offset) {
        FileUtils::write_to_file(file_info, (uint8_t *)&value, sizeof(T), offset);
        return offset + sizeof(T);
    }
};

} // namespace virtual_memory
} // namespace graph_storage

#endif
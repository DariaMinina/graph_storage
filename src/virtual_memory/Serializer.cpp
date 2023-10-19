
#include "virtual_memory/Serializer.hpp"
#include "storage/FileUtils.hpp"
#include <cstdint>
#include <string>

namespace graph_storage {
namespace virtual_memory {

template <>
std::size_t Serializer::serialize_value<std::string>(const std::string &value, FileInfo *file_info,
                                                     std::size_t offset) {
    auto value_length = value.length();
    FileUtils::write_to_file(file_info, (uint8_t *)&value_length, sizeof(value_length), offset);
    FileUtils::write_to_file(file_info, (uint8_t *)value.data(), value_length, offset + sizeof(value_length));
    return offset + sizeof(value_length) + value_length;
}

template <>
std::size_t Serializer::deserialize_value<std::string>(std::string &value, FileInfo *file_info, std::size_t offset) {
    std::size_t value_length = 0;
    offset = Serializer::deserialize_value<std::size_t>(value_length, file_info, offset);
    value.resize(value_length);
    FileUtils::read_from_file(file_info, (uint8_t *)value.data(), value_length, offset);
    return offset + value_length;
}

} // namespace virtual_memory
} // namespace graph_storage
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "storage/FileInfo.hpp"
#include "storage/FileUtils.hpp"
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

    template <typename A, typename B>
    static std::size_t serialize_unordered_map(const std::unordered_map<A, B> &values, FileInfo *file_info,
                                               std::size_t offset) {
        std::size_t map_size = values.size();
        offset = serialize_value<std::size_t>(map_size, file_info, offset);
        for (auto &value : values) {
            offset = serialize_value<A>(value.first, file_info, offset);
            offset = serialize_value<B>(value.second, file_info, offset);
        }
        return offset;
    }

    template <typename T>
    static std::size_t serialize_vector(const std::vector<T> &values, FileInfo *file_info, std::size_t offset) {
        std::size_t vector_size = values.size();
        offset = serialize_value<std::size_t>(vector_size, file_info, offset);
        for (auto &value : values) {
            offset = serialize_value(value, file_info, offset);
        }
        return offset;
    }

    template <typename A, typename B>
    static std::size_t deserialize_unordered_map(std::unordered_map<A, B> &values, FileInfo *file_info,
                                                 std::size_t offset) {
        std::size_t map_size;
        offset = deserialize_value<std::size_t>(map_size, file_info, offset);
        for (auto i = 0u; i < map_size; i++) {
            std::size_t label_id;
            std::size_t num_rels;
            offset = deserialize_value<A>(label_id, file_info, offset);
            offset = deserialize_value<B>(num_rels, file_info, offset);
            values.emplace(label_id, num_rels);
        }
        return offset;
    }

    template <typename T>
    static std::size_t deserialize_vector(std::vector<T> &values, FileInfo *file_info, std::size_t offset) {
        std::size_t vectorSize;
        offset = deserialize_value<std::size_t>(vectorSize, file_info, offset);
        values.resize(vectorSize);
        for (auto &value : values) {
            offset = deserialize_value<T>(value, file_info, offset);
        }
        return offset;
    }

    template <typename T>
    static std::size_t serialize_unordered_set(const std::unordered_set<T> &values, FileInfo *file_info,
                                               std::size_t offset) {
        std::size_t setSize = values.size();
        offset = serialize_value<std::size_t>(setSize, file_info, offset);
        for (auto &value : values) {
            offset = serialize_value<T>(value, file_info, offset);
        }
        return offset;
    }

    template <typename T>
    static std::size_t deserialize_unoredered_set(std::unordered_set<T> &values, FileInfo *file_info,
                                                  std::size_t offset) {
        std::size_t set_size;
        offset = deserialize_value<std::size_t>(set_size, file_info, offset);
        for (auto i = 0u; i < set_size; i++) {
            T value;
            offset = deserialize_value<T>(value, file_info, offset);
            values.insert(value);
        }
        return offset;
    }
};

} // namespace virtual_memory
} // namespace graph_storage

#endif

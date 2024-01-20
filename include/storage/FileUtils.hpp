#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include "storage/FileInfo.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <sys/stat.h>

namespace graph_storage {
namespace storage {

class FileUtils {
public:
    static std::unique_ptr<FileInfo> open_file(const std::string &path, const int32_t flags);
    static void close_file(int fd);

    static void read_from_file(FileInfo *file_info, void *buffer, uint64_t num_bytes, uint64_t position);
    static void write_to_file(FileInfo *file_info, void *buffer, uint64_t num_bytes, uint64_t offset);

    static inline int64_t get_file_size(int fd) {
        struct stat s;
        if (fstat(fd, &s) == -1) {
            return -1;
        }
        return s.st_size;
    }
};

} // namespace storage
} // namespace graph_storage

#endif

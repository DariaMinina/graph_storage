#ifndef FILE_INFO_HPP
#define FILE_INFO_HPP

#include <cstdint>
#include <string>
#include <unistd.h>

namespace graph_storage {
namespace storage {

struct FileInfo {
    FileInfo(std::string path, const int fd) : path{std::move(path)}, fd{fd} {}

    ~FileInfo() {
        if (fd != -1) {
            close(fd);
        }
    }

    const std::string path;
    const int fd;
};

} // namespace storage
} // namespace graph_storage

#endif
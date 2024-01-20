#include "storage/FileUtils.hpp"
#include "fmt/format.h"
#include "storage/FileInfo.hpp"
#include <cstdint>
#include <fcntl.h>
#include <memory>
#include <stdexcept>
#include <sys/types.h>
#include <unistd.h>

namespace graph_storage {
namespace storage {

std::unique_ptr<FileInfo> FileUtils::open_file(const std::string &path, const int flags) {
    int fd = open(path.c_str(), flags);
    if (fd == -1) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    return std::make_unique<FileInfo>(path, fd);
}

void FileUtils::close_file(int fd) {
    if (fd != -1) {
        close(fd);
    }
}

void FileUtils::write_to_file(FileInfo *file_info, void *buffer, uint64_t num_bytes, uint64_t offset) {
    int64_t file_size = get_file_size(file_info->fd);
    if (file_size == -1) {
        throw std::runtime_error(fmt::format("File {} not open.", file_info->path.c_str()));
    }
    uint64_t num_bytes_written = pwrite(file_info->fd, buffer, num_bytes, offset);
    if (num_bytes_written != num_bytes) {
        throw std::runtime_error(fmt::format("Cannot write to file. path: {} fileDescriptor: {} offsetToWrite: {} "
                                             "numBytesToWrite: {} numBytesWritten: {}",
                                             file_info->path.c_str(), file_info->fd, offset, num_bytes,
                                             num_bytes_written));
    }
}

void FileUtils::read_from_file(FileInfo *file_info, void *buffer, uint64_t num_bytes, uint64_t position) {
    ssize_t num_bytes_read = pread(file_info->fd, buffer, num_bytes, position);
    if (num_bytes_read != num_bytes && get_file_size(file_info->fd) != position + num_bytes_read) {
        throw std::runtime_error(fmt::format("Cannot read from file: {} fileDescriptor: {} "
                                             "numBytesRead: {} numBytesToRead: {} position: {}",
                                             file_info->path.c_str(), file_info->fd, num_bytes_read, num_bytes,
                                             position));
    }
}

} // namespace storage
} // namespace graph_storage

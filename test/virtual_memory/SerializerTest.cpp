#include "virtual_memory/Serializer.hpp"
#include "storage/FileInfo.hpp"
#include "storage/FileUtils.hpp"
#include "gtest/gtest.h"
#include <cstddef>
#include <cstdint>
#include <fcntl.h>

namespace graph_storage {

TEST(SerializationTest, intTest) {
    std::unique_ptr<storage::FileInfo> file =
        storage::FileUtils::open_file("./graph_storage-serialization.32", O_RDWR | O_CREAT);
    int32_t value_a = 32;
    std::size_t offset_a = virtual_memory::Serializer::serialize_value(value_a, file.get(), 0);

    int32_t value_b = 0;
    std::size_t offset_b = virtual_memory::Serializer::deserialize_value(value_b, file.get(), 0);
    EXPECT_EQ(value_a, value_b);
}

} // namespace graph_storage

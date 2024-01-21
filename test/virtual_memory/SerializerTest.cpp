#include "virtual_memory/Serializer.hpp"
#include "storage/FileInfo.hpp"
#include "storage/FileUtils.hpp"
#include "gtest/gtest.h"
// #include "Node.pb.h"
#include <cstddef>
#include <cstdint>
#include <fcntl.h>

namespace graph_storage {

TEST(SerializationTest, intTest) {
    std::unique_ptr<storage::FileInfo> file = storage::FileUtils::open_file("./graph_storage-serialization.32", O_RDWR);
    int32_t value_a = 32;
    std::size_t offset_a = virtual_memory::Serializer::serialize_value(value_a, file.get(), 0);

    int32_t value_b = 0;
    std::size_t offset_b = virtual_memory::Serializer::deserialize_value(value_b, file.get(), 0);
    EXPECT_EQ(value_a, value_b);
}

// TEST(SerializationTest, protobufTest) {
//     std::unique_ptr<storage::FileInfo> file =
//         storage::FileUtils::open_file("./graph_storage-serialization.32", O_RDWR);
//     graph::proto::Node node_a;
//     node_a.set_is_in_use("No");
//     node_a.set_id(0);
//     node_a.set_first_property_id(0);
//     node_a.set_first_relationship_id(0);
//     node_a.set_label("example");
//     node_a.set_remaining_byte("0");
//     std::size_t offset_a = virtual_memory::Serializer::serialize_value(node_a, file.get(), 0);
//
//     graph::proto::Node node_b;
//     int32_t value_b = 0;
//     std::size_t offset_b = virtual_memory::Serializer::deserialize_value(node_b, file.get(), 0);
//     EXPECT_EQ(node_a.id(), node_b.id());
//     EXPECT_EQ(node_a.is_in_use(), node_b.is_in_use());
//     EXPECT_EQ(node_a.first_property_id(), node_b.first_property_id());
//     EXPECT_EQ(node_a.first_relationship_id(), node_b.first_relationship_id());
//     EXPECT_EQ(node_a.label(), node_b.label());
//     EXPECT_EQ(node_a.remaining_byte(), node_b.remaining_byte());
// }

} // namespace graph_storage

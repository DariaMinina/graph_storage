#include "Node.pb.h"
#include "benchmark/benchmark.h"
#include "storage/FileInfo.hpp"
#include "storage/FileUtils.hpp"
#include "virtual_memory/Serializer.hpp"
#include <fcntl.h>
#include <memory>
#include <string>

using namespace graph_storage;

static void BM_SerializeInt(benchmark::State &state) {
    std::unique_ptr<storage::FileInfo> file = storage::FileUtils::open_file("./graph_storage-serialization.32", O_RDWR);
    int32_t value_a = 32;
    int32_t value_b = 0;

    for (auto _ : state) {
        std::size_t offset_b = virtual_memory::Serializer::deserialize_value(value_b, file.get(), 0);
        std::size_t offset_a = virtual_memory::Serializer::serialize_value(value_a, file.get(), 0);
    }
}

static void BM_SerializeNode(benchmark::State &state) {
    std::unique_ptr<storage::FileInfo> file =
        storage::FileUtils::open_file("./graph_storage-serialization.node", O_RDWR);
    graph::proto::Node node_a;
    node_a.set_is_in_use("No");
    node_a.set_id(0);
    node_a.set_first_property_id(0);
    node_a.set_first_relationship_id(0);
    node_a.set_label("example");
    node_a.set_remaining_byte("0");

    graph::proto::Node node_b;

    for (auto _ : state) {
        std::size_t offset_a = virtual_memory::Serializer::serialize_value(node_a, file.get(), 0);
        std::size_t offset_b = virtual_memory::Serializer::deserialize_value(node_b, file.get(), 0);
        // node_a.SerializeToFileDescriptor(file->fd);
        // node_b.ParseFromFileDescriptor(file->fd);
    }
}

BENCHMARK(BM_SerializeInt);
BENCHMARK(BM_SerializeNode);

BENCHMARK_MAIN();

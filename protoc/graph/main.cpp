#include "graph_classes.pb.h"
#include <fstream>

int main(int argc, char* argv[]) {
    Node node;
    node.set_is_in_use("1");
    node.set_id(1);
    node.set_first_relationship_id(1);
    node.set_first_property_id(1);
    node.set_label("Person");
    node.set_remaining_byte("0");
    std::ofstream ofs("graph.data",std::ios_base::out | std::ios_base::binary);
    node.SerializeToOstream(&ofs);
    return 0;
}

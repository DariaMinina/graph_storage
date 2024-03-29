#include "graph/Node.hpp"
#include <iostream>

using namespace graph_storage::graph;

Node::Node() {
    // std::cout << "Node Constructor: " << this << " " << toString() <<
    // std::endl;
}

Node::~Node() {
    // std::cout << "Node Destructor: " << this << std::endl;
}

Node::Node(const std::string &s) {
    // Ignore the name
}

std::string Node::to_string() const {
    std::stringstream s;
    s << "n" << this;
    return s.str();
}

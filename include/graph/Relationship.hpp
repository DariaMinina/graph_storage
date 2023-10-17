#include "Node.hpp"

namespace graph_storage {
namespace graph {

/**
 * Simple object to store pointers to two nodes
 * @see analyzer::Node
 * @see analyzer::Graph
 */
class Relationship {
  public:
    /// the Node* with the lowest memory address
    Node *first;
    /// the Node* with the lowest memory address
    Node *second;

    /**
     * creates an edge between start and end.  For undirected nodes, order does
     * not matter.
     */
    Relationship(Node *start, Node *end);
    /**
     * Make an edge with the given attributes.  This
     * edge only supports a weight (double in the string)
     */
    Relationship(Node *start, Node *end, const std::string &attrs);

    virtual ~Relationship(){};
    virtual Relationship *clone() const {
        return new Relationship(first, second);
    }
    /**
     * @param start
     * @param end
     * @return true if this edge has both start and end
     */
    virtual bool connects(Node *start, Node *end) const;
    /**
     * @return true if this node is in this edge
     */
    bool contains(Node *n) const { return ((first == n) || (second == n)); };
    /**
     * @return first if passed second, second if passed first, and 0 otherwise
     */
    Node *const &get_other_node(Node *start) const;
    /**
     * Returns the attributes of this edge.  Useful in EdgeFactories
     */
    virtual std::string get_attributes() const;
    virtual std::string to_string() const;

    virtual double get_weight() const;

    virtual bool operator<(const Relationship &a) const;
    virtual bool operator==(const Relationship &a) const;

  private:
    char start_node_id;
    char end_node_id;
    char relationship_type;
};

} // namespace graph
} // namespace graph_storage
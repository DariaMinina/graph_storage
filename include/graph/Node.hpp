#include <sstream>
#include <string>

namespace graph_storage {
namespace graph {

/**
 * Base node class.  Subclass this to make different types of nodes.
 * We usually work with pointers to nodes, so we don't have to store O(N^2)
 * copies of the data associated with each node.
 * @see analyzer::Network
 * @see analyzer::Edge
 */
class Node {
public:
    Node();
    /**
     * The basic node totally ignores this string, but subclasses might not
     */
    Node(const std::string &s);
    virtual ~Node();
    /**
     * @return a string suitable for printing
     */
    virtual std::string to_string() const;

private:
    char is_in_use;             // pointer isInUse
    int id;                     // ID of the node
    char first_relationship_id; // first relationship ID
    char first_property_id;     // first property ID
    std::string label;          // label store
    char remaining_byte;        // for future use
};

} // namespace graph
} // namespace graph_storage

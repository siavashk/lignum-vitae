#include "graphs.h"

using namespace lv;
using namespace boost;
namespace
{
    using VertexDescriptor = graph_traits<DirectedGraphType>::vertex_descriptor;
}

DirectedGraphType lv::makeDirectedGraphWithCycles()
{
    DirectedGraphType g;

    VertexDescriptor a = add_vertex(VertexPropertyType("a", white_color), g);
    VertexDescriptor b = add_vertex(VertexPropertyType("b", white_color), g);
    VertexDescriptor c = add_vertex(VertexPropertyType("c", white_color), g);
    VertexDescriptor d = add_vertex(VertexPropertyType("d", white_color), g);
    VertexDescriptor e = add_vertex(VertexPropertyType("e", white_color), g);

    add_edge(a, c, EdgePropertyType(1, black_color), g);
    add_edge(b, d, EdgePropertyType(1, black_color), g);
    add_edge(b, e, EdgePropertyType(2, black_color), g);
    add_edge(c, b, EdgePropertyType(5, black_color), g);
    add_edge(c, d, EdgePropertyType(10, black_color), g);
    add_edge(d, e, EdgePropertyType(4, black_color), g);
    add_edge(e, a, EdgePropertyType(3, black_color), g);
    add_edge(e, b, EdgePropertyType(7, black_color), g);

    return g;
}

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

    add_edge(a, c, g); add_edge(b, b, g); add_edge(b, d, g);
    add_edge(b, e, g); add_edge(c, b, g); add_edge(c, d, g);
    add_edge(d, e, g); add_edge(e, a, g); add_edge(e, b, g);

    return g;
}

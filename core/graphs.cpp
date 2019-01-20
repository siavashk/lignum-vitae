#include "graphs.h"

using namespace lv;
using Edge = std::pair<int, int>;
using VertexDescriptor = boost::graph_traits<DirectedGraphType>::vertex_descriptor;

DirectedGraphType lv::makeDirectedGraphWithCycles()
{
    DirectedGraphType graph;
    VertexDescriptor a = graph.add_vertex(); VertexDescriptor b = graph.add_vertex();
    VertexDescriptor c = graph.add_vertex(); VertexDescriptor d = graph.add_vertex();
    VertexDescriptor e = graph.add_vertex();

    graph.add_edge(a, c); graph.add_edge(b, b); graph.add_edge(b, d);
    graph.add_edge(b, e); graph.add_edge(c, b); graph.add_edge(c, d);
    graph.add_edge(d, e); graph.add_edge(e, a); graph.add_edge(e, b);

    return graph;
}

UndirectedGraphType lv::makeUndirectedTree()
{
    UndirectedGraphType graph;
    VertexDescriptor a = graph.add_vertex(); VertexDescriptor b = graph.add_vertex();
    VertexDescriptor c = graph.add_vertex(); VertexDescriptor d = graph.add_vertex();
    VertexDescriptor e = graph.add_vertex();
    
    graph.add_edge(a, b); graph.add_edge(a, c);
    graph.add_edge(b, d); graph.add_edge(b, e);
    
    return graph;
}

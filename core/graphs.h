#pragma once

namespace lv
{
    using DirectedGraphType = boost::directed_graph<>;
    using UndirectedGraphType = boost::undirected_graph<boost::no_property>;
    DirectedGraphType makeDirectedGraphWithCycles();
    UndirectedGraphType makeUndirectedTree();
}

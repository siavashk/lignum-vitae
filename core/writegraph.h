#pragma once

namespace lv
{
    using DirectedGraphType = boost::directed_graph<>;
    using UndirectedGraphType = boost::undirected_graph<boost::no_property>;
    template <typename T>
    void writeGraph(const T& graph, const char* filename)
    {
        std::ofstream dotFile(filename);
        write_graphviz(dotFile, graph);
    }
}

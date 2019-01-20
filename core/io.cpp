#include "io.h"

using namespace lv;
using namespace boost;

char* makeNodeLabels(const int numNodes)
{
    if (numNodes < 1 || numNodes > 26)
        throw std::overflow_error("Only [1-26] (inclusive) nodes are supported for labelling.");
    else
    {
        char* result = new char[numNodes];
        for (int i = 0; i < numNodes; i++)
            result[i] = (char)(97 + i);
        return result;
    }
}

void lv::writeGraph(const GraphType& graph, const char* filename)
{
    std::ofstream dotFile(filename);
    const char* name = makeNodeLabels(num_vertices(graph));
    write_graphviz(dotFile, graph, make_label_writer(name));
}

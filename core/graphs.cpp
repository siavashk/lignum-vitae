#include "graphs.h"

using namespace lv;
using Edge = std::pair<int, int>;

GraphType lv::makeDirectedGraphWithCycles()
{
    const int numNodes = 5;
    enum nodes { A, B, C, D, E };
    std::vector<Edge> edges = {
        Edge(A, C), Edge(B, B), Edge(B, D),
        Edge(B, E), Edge(C, B), Edge(C, D),
        Edge(D, E), Edge(E, A), Edge(E, B)
    };
    return GraphType(edges.begin(), edges.end(), numNodes);
}

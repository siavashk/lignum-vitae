#include <writegraph.h>
#include <graphs.h>

using namespace lv;

int main(int, char *[])
{
    DirectedGraphType graph = makeDirectedGraphWithCycles();
    writeGraph(graph, "graph.dot");

    return EXIT_SUCCESS;
}

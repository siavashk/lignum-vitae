#include <io.h>
#include <graphs.h>

using namespace lv;

int main(int, char *[])
{
    GraphType graph = makeDirectedGraphWithCycles();
    writeGraph(graph, "graph.dot");

    return EXIT_SUCCESS;
}

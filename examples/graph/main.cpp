#include <writegraph.h>
#include <graphs.h>

using namespace lv;

int main(int, char *[])
{
    DirectedGraphType directed = makeDirectedGraphWithCycles();
    writeGraph(directed, "directed.dot");
    
    UndirectedGraphType tree = makeUndirectedTree();
    writeGraph(tree, "tree.dot");

    return EXIT_SUCCESS;
}

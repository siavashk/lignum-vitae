#include <writegraph.h>
#include <graphs.h>

using namespace lv;

int main(int, char *[])
{
    DirectedGraphType directed = makeDirectedGraphWithCycles();
    writeGraph(directed, "directed.dot");

    return EXIT_SUCCESS;
}

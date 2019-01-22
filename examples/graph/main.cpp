#include <writegraph.h>
#include <graphs.h>

using namespace lv;

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        std::cerr << "Usage: " << argv[0] << " [filename]" << std::endl;
        return EXIT_FAILURE;
    }
    const char* name = argc > 1 ? argv[1] : "graph.dot";
    DirectedGraphType graph = makeDirectedGraphWithCycles();
    writeGraph(graph, name);

    return EXIT_SUCCESS;
}

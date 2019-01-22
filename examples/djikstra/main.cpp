#include <writegraph.h>
#include <graphs.h>

using namespace lv;

using VertexDescriptor = boost::graph_traits<DirectedGraphType>::vertex_descriptor;
using VertexIterator = boost::graph_traits<DirectedGraphType>::vertex_iterator;

VertexDescriptor getVertexDescriptorFromName(
    const DirectedGraphType& graph,
    const char* name
) {
    VertexIterator vi, vend;
    VertexDescriptor vertex;
    auto nameMap = boost::get(boost::vertex_name, graph);
    for (boost::tie(vi, vend) = boost::vertices(graph); vi != vend; vi++)
    {
        if (nameMap[*vi] == name)
            vertex = *vi;
    }
    return vertex;
}

std::vector<VertexDescriptor> getPath(
    const DirectedGraphType& graph,
    const std::vector<VertexDescriptor>& pMap,
    const VertexDescriptor& source,
    const VertexDescriptor& destination
) {
    std::vector<VertexDescriptor> path;
    VertexDescriptor current = destination;
    while (current != source)
    {
        path.push_back(current);
        current = pMap[current];
    }
    path.push_back(source);
    return path;
}

std::vector<VertexDescriptor> djikstra(
    const DirectedGraphType& graph,
    const char* sourceName,
    const char* destinationName
) {
    VertexDescriptor source = getVertexDescriptorFromName(graph, sourceName);
    VertexDescriptor destination = getVertexDescriptorFromName(graph, destinationName);
    
    const int numVertices = boost::num_vertices(graph);
    std::vector<int> distances(numVertices);
    std::vector<VertexDescriptor> pMap(numVertices);
    
    auto distanceMap = boost::predecessor_map(
        boost::make_iterator_property_map(pMap.begin(), boost::get(boost::vertex_index, graph))).distance_map(
        boost::make_iterator_property_map(distances.begin(), boost::get(boost::vertex_index, graph)));
    
    boost::dijkstra_shortest_paths(graph, source, distanceMap);
    return getPath(graph, pMap, source, destination);
}

void printPath(
    const DirectedGraphType& graph,
    const std::vector<VertexDescriptor>& path
) {
    auto nameMap = boost::get(boost::vertex_name, graph);
    std::cout << "The shortest path between " << nameMap[path.back()] << " and "
        << nameMap[path.front()] << " is: " << std::endl;
    for (auto it = path.rbegin(); it < path.rend(); ++it)
    {
        if (it == path.rend() - 1)
            std::cout << nameMap[*it] << std::endl;
        else
            std::cout << nameMap[*it] << " --> ";
    }
}

DirectedGraphType markPathAlongGraph(
    const DirectedGraphType& graph,
    const std::vector<VertexDescriptor>& path,
    const boost::default_color_type nodeColor,
    const boost::default_color_type edgeColor
) {
    DirectedGraphType marked;
    boost::copy_graph(graph, marked);
    
    auto nodeColorMap = boost::get(boost::vertex_color, marked);
    nodeColorMap[path.front()] = nodeColor;
    nodeColorMap[path.back()] = nodeColor;
    
    auto nodeIndexMap = boost::get(boost::vertex_index, marked);
    for (auto first = path.rbegin(); first < path.rend() - 1; ++first)
    {
        auto second = boost::next(first);
        VertexDescriptor from = nodeIndexMap[*first];
        VertexDescriptor to = nodeIndexMap[*second];
        auto edge = boost::edge(from, to, marked).first;
        boost::put(boost::edge_color, marked, edge, edgeColor);
    }
    return marked;
}

int main(int, char *[])
{
    DirectedGraphType graph = makeDirectedGraphWithCycles();
    auto path = djikstra(graph, "a", "d");
    printPath(graph, path);
    DirectedGraphType marked = markPathAlongGraph(graph, path, boost::gray_color, boost::red_color);
    writeGraph(marked, "marked.dot");
    return EXIT_SUCCESS;
}

#pragma once

namespace lv
{
    using VertexPropertyType = boost::property<boost::vertex_name_t, std::string,
        boost::property<boost::vertex_color_t, boost::default_color_type>>;

    using EdgePropertyType = boost::property<boost::edge_weight_t, int,
        boost::property<boost::edge_color_t, boost::default_color_type>>;

    using DirectedGraphType = boost::adjacency_list<boost::vecS, boost::vecS,
        boost::directedS, VertexPropertyType, EdgePropertyType>;

    using UndirectedGraphType = boost::adjacency_list<boost::vecS, boost::vecS,
        boost::undirectedS, VertexPropertyType, EdgePropertyType>;

    DirectedGraphType makeDirectedGraphWithCycles();
}

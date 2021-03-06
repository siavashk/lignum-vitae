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

    inline const char* colorToString(boost::default_color_type color)
    {
        switch(color)
        {
            case boost::default_color_type::red_color: return "red";
            case boost::default_color_type::green_color: return "green";
            case boost::default_color_type::gray_color: return "gray";
            case boost::default_color_type::white_color: return "white";
            case boost::default_color_type::black_color: return "black";
        }
        return ""; //Unknown
    }
    
    struct GraphPropertyWriter
    {
        void operator()(std::ostream& out) const
        {
            out << "rankdir=\"LR\"" << std::endl;
        }
    };

    template <typename T>
    class VertexWriter
    {
    public:
        VertexWriter(const T& graph) : graph_(graph) {}
        template <typename Vertex>
        void operator()(std::ostream& out, const Vertex& v) const
        {
            auto nameMap = get(boost::vertex_name, graph_);
            auto colorMap = get(boost::vertex_color, graph_);
            out << "[label=\"" << nameMap[v] << "\", style=filled, fillcolor=\"" << colorToString(colorMap[v]) << "\"]";
        }
    private:
        T graph_;
    };
    
    template <typename T>
    class EdgeWriter
    {
    public:
        EdgeWriter(const T& graph) : graph_(graph) {}
        template <typename Edge>
        void operator()(std::ostream& out, const Edge& e) const
        {
            auto weightMap = get(boost::edge_weight, graph_);
            auto colorMap = get(boost::edge_color, graph_);
            out << "[label=\"" << weightMap[e] << "\", color=\"" << colorToString(colorMap[e]) << "\"]";
        }
    private:
        T graph_;
    };

    template <typename T>
    void writeGraph(const T& graph, const char* filename)
    {
        std::ofstream dotFile(filename);
        write_graphviz(dotFile, graph, VertexWriter<T>(graph), EdgeWriter<T>(graph), GraphPropertyWriter());
    }
}

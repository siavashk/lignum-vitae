#pragma once

namespace lv
{
    using GraphType = boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS>;
    GraphType makeDirectedGraphWithCycles();
}

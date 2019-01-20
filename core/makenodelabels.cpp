#include "makenodelabels.h"

char* lv::makeNodeLabels(const int numNodes)
{
    if (numNodes < 1 || numNodes > 26)
        throw std::overflow_error("Only [1-26] (inclusive) nodes are supported for labelling.");
    else
    {
        char* result = new char[numNodes];
        for (int i = 0; i < numNodes; i++)
            result[i] = (char)(97 + i);
        return result;
    }
}

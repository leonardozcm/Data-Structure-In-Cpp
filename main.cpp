


#include "Graph/Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph<int> graph;
    graph.Link(0, 1).Link(0, 3)
            .Link(1, 3).Link(1, 5)
            .Link(2, 0).Link(2, 5)
            .Link(3, 2).Link(3, 5).Link(3, 6).Link(3, 4)
            .Link(4, 6)
            .Link(6, 5);
    graph.FindShortestWayUnweighted(2,4);
    return 0;
}

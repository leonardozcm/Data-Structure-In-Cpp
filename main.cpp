


#include "Graph/Graph.h"
#include "List/list.h"
#include <iostream>

using namespace std;

int main() {
    Graph<int> graph;
    graph.Link(0, 1, 2).Link(0, 3, 1)
            .Link(1, 3, 3).Link(1, 4, 10)
            .Link(2, 0, 4).Link(2, 5, 5)
            .Link(3, 2, 2).Link(3, 5, 8).Link(3, 6, 4).Link(3, 4, 2)
            .Link(4, 6, 6)
            .Link(6, 5, 1);
    graph.Dijkstra(0, 6);
}

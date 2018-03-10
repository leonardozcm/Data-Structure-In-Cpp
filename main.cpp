


#include "Graph/Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph<int> graph;
    graph.Link(1, 3)
            .Link(1, 4)
            .Link(2, 1)
            .Link(3, 4);
    graph.TopSort();
    return 0;
}

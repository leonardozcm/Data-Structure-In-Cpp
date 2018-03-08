


#include "Graph/Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph<int > graph;
    list<pair<Vertex, double >> link_list;
    link_list.emplace_back(0,1);
    link_list.emplace_back(2,4);
    graph.Add(1,link_list,2141);
    return 0;
}

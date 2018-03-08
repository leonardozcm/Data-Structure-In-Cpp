


#include "Graph/Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph<int > graph;
    List<pair<Vertex, double >> link_list;
    link_list.add(pair<Vertex, double>(0,1));
    graph.Add(1,link_list,214321);
    return 0;
}

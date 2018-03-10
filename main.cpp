


#include "Graph/Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph<int > graph;
    list<pair<Vertex, double >> link_list;
    link_list.emplace_back(1,1);
    link_list.emplace_back(2,1);
    graph.Add(0,link_list,0);
    list<pair<Vertex, double >> link_list1;
    link_list1.emplace_back(3,1);
    link_list1.emplace_back(4,1);
    graph.Add(1,link_list1,0);
    list<pair<Vertex, double >> link_list2;
    link_list2.emplace_back(1,1);
    graph.Add(2,link_list2,0);
    list<pair<Vertex, double >> link_list3;
    link_list3.emplace_back(4,1);
    graph.Add(3,link_list3,0);
    graph.TopSort();
  /*  link_list.empty();
    link_list.emplace_back(3,1);
    link_list.emplace_back(5,1);
    graph.Add(1,link_list,0);
    link_list.empty();
    link_list.emplace_back(5,1);
    graph.Add(2,link_list,0);
    link_list.empty();
    link_list.emplace_back(2,1);
    graph.Add(3,link_list,0);
    link_list.empty();
    link_list.emplace_back(4,1);
    graph.Add(5,link_list,0);
    graph.TopSort();*/
    return 0;
}

//
// Created by leonardo on 18-3-5.
//

#ifndef DATASTRUCTURESINCPP_GRAPH_H
#define DATASTRUCTURESINCPP_GRAPH_H

#include <stack>
#include <map>
#include <vector>
#include <cstdio>
#include "../List/list.h"

using namespace std;
#define MaxVertex 10
typedef int Vertex;


template<class T>
class Graph {
public:
    class GraphNode {
    public:
        Vertex v{};
        double weight{};

        GraphNode() = default;

        explicit GraphNode(Vertex vertex) {
            GraphNode(vertex, 1);
        }

        GraphNode(Vertex vertex, double weight) {
            v = vertex;
            this->weight = weight;
        }

    };

    Graph();

    void Add(Vertex ver, List<pair<Vertex, double >> &link_list, T t);

    void PutIntoStack();

    void TopSort();


private:
    vector<List<GraphNode>> vertex_vector;
    stack<Vertex> InDegreeZero;
    map<Vertex, T> keyMap;
    int InDegree[MaxVertex]{};

};

template<class T>
Graph<T>::Graph() {
    for (auto &i : InDegree) {
        i = 0;
    }
}

template<class T>
void Graph<T>::Add(Vertex ver, List<pair<Vertex, double >> &link_list, T t) {
    keyMap.insert(pair<Vertex, T>(ver, t));
    List<GraphNode> add_list;
    List<pair<Vertex, double >>::Node *tmp;
/*
    {
        GraphNode graphNode(1,1);        add_list.push_back(graphNode);
    }
*/
    for (tmp = link_list.FindByPos(0); tmp; tmp = tmp->next) {
        InDegree[tmp->t.first]++;
        GraphNode graphNode(tmp->t.first, tmp->t.second);
        add_list.add(graphNode);
    }
    vertex_vector[ver] = add_list;
    /*  typename list<Graph<T>::GraphNode>::iterator itor;
      for (itor = link_list.begin(); itor != link_list.end(); itor++) {
          InDegree[(*itor).v]++;
      }
      vertex_vector[ver] = link_list;*/
}

template<class T>
void Graph<T>::PutIntoStack() {
    for (auto &i:InDegree) {
        if (!i) {
            InDegreeZero.push(i);
        }
    }
}

template<class T>
void Graph<T>::TopSort() {
    Vertex v;
    GraphNode *itor;
    PutIntoStack();
    int counter = 0;
    while (!InDegreeZero.empty()) {
        counter++;
        v = InDegreeZero.top();
        InDegreeZero.pop();
        printf("%d -> ", v);
        itor = vertex_vector[v].begin();
        for (; itor != vertex_vector[v].end(); itor++) {
            if (--InDegree[(*itor).v] == 0)
                InDegreeZero.push((*itor).v);
        }
    }
    if (counter != MaxVertex) {
        printf("Graph has a circle.\n");
    }
}

#endif //DATASTRUCTURESINCPP_GRAPH_H

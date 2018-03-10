//
// Created by leonardo on 18-3-5.
//

#ifndef DATASTRUCTURESINCPP_GRAPH_H
#define DATASTRUCTURESINCPP_GRAPH_H

#include <stack>
#include <map>
#include <cstdio>
#include <list>

using namespace std;
#define MaxVertex 5
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

    void Add(Vertex ver, list<pair<Vertex, double >> &link_list, T t);

    void PutIntoStack();

    void TopSort();

    void Link(Vertex startVertex, Vertex pointVertex, double weight);

    void Link(Vertex startVertex, Vertex pointVertex);

    void DoubleLink(Vertex startVertex, Vertex, double weight);

    void DoubleLink(Vertex startVertex, Vertex pointVertex);

private:
    list<GraphNode> vertex_vector[MaxVertex];
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
void Graph<T>::Add(Vertex ver, list<pair<Vertex, double >> &link_list, T t) {
    keyMap.insert(pair<Vertex, T>(ver, t));
    list<GraphNode> add_list;
    for (auto itor : link_list) {
        InDegree[itor.first]++;
        GraphNode graphNode(itor.first, itor.second);
        add_list.push_back(graphNode);
    }


    vertex_vector[ver] = add_list;
    auto itor = link_list.begin();
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
    PutIntoStack();
    int counter = 0;
    while (!InDegreeZero.empty()) {
        counter++;
        v = InDegreeZero.top();
        InDegreeZero.pop();
        printf("%d -> ", v);
        for (auto itor:vertex_vector[v]) {
            if (--InDegree[itor.v] == 0)
                InDegreeZero.push(itor.v);
        }
    }
    if (counter != MaxVertex) {
        printf("Graph has a circle.\n");
    }
}

#endif //DATASTRUCTURESINCPP_GRAPH_H

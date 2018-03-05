//
// Created by leonardo on 18-3-5.
//

#ifndef DATASTRUCTURESINCPP_GRAPH_H
#define DATASTRUCTURESINCPP_GRAPH_H

#include "../List/list.h"
#include "../Queue/queue.h"
#include "../HashMap/HashMap.h"
#include <hash_map>

#define MaxVertex 10
typedef int Vertex;


template<class T>
class Graph {
public:
    class GraphNode {
    public:
        Vertex v;
        double weight;

        explicit GraphNode(Vertex v) : v(v) {
            weight = 0;
        }

        GraphNode(Vertex v, double weight) : v(v), weight(weight) {}
    };

    void Add(Vertex vertex,List<pair<T, double>> ConnectingVertexList);

    void TopSort();

    Vertex FindNewVertexOfIndegreeZero();
private:
    List<List<Vertex >> vertexlist;
    int InDegree<MaxVertex>;
    Queue<Vertex> EmptyVertexQueue;

};

template<class T>
void Graph<T>::Add(Vertex vertex, List<pair<T, double>> ConnectingVertexList) {

}

template<class T>
void Graph<T>::TopSort() {

}

template<class T>
Vertex Graph<T>::FindNewVertexOfIndegreeZero() {
    return 0;
}


#endif //DATASTRUCTURESINCPP_GRAPH_H

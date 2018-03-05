//
// Created by leonardo on 18-3-5.
//

#ifndef DATASTRUCTURESINCPP_GRAPH_H
#define DATASTRUCTURESINCPP_GRAPH_H

#include "../List/list.h"
#include "../HashMap/HashMap.h"
#include "../Stack/stack.h"

#define MaxVertex 10
typedef int Vertex;


template<class T>
class Graph {
public:
    class GraphNode {
    public:
        T t;
        Vertex v;
        double weight;

        explicit GraphNode(Vertex v) : v(v) {
            weight = 0;
        }

        GraphNode(T t, Vertex v) : v(v), t(t) {
            weight = 0;
        }

        GraphNode(T t, Vertex v, double weight) : v(v), t(t), weight(weight) {}
    };

    typedef GraphNode *PtrToGraphNode;

    Graph();

    void Add(Vertex vertex, List<List<GraphNode >> ConnectingVertexList);

    void TopSort();

    Vertex FindNewVertexOfIndegreeZero();

private:
    List<List<GraphNode >> vertexlist;
    int InDegree[MaxVertex];
    Stack<GraphNode> EmptyVertexStack;
    HashMap<Vertex> KeyMap;
};


template<class T>
void Graph<T>::TopSort() {

}

template<class T>
Vertex Graph<T>::FindNewVertexOfIndegreeZero() {
     if(EmptyVertexStack.TopAndPop()){
         return EmptyVertexStack.TopAndPop()->t.v;
     };
    return -1;
}

template<class T>
Graph<T>::Graph() {
    for (int i = 0; i < MaxVertex; ++i) {
        GraphNode graphNode(i);
        List<GraphNode> list;
        list.add(graphNode);
        vertexlist.add(list);
        InDegree[i] = 0;
        EmptyVertexStack.Push(graphNode);
    }
}

template<class T>
void Graph<T>::Add(Vertex vertex, List<List<Graph::GraphNode>> ConnectingVertexList) {

}


#endif //DATASTRUCTURESINCPP_GRAPH_H

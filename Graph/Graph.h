//
// Created by leonardo on 18-3-5.
//

#ifndef DATASTRUCTURESINCPP_GRAPH_H
#define DATASTRUCTURESINCPP_GRAPH_H

#include <stack>
#include <map>
#include <cstdio>
#include <list>
#include <queue>
#include "../Heap/Heap.h"

using namespace std;

#define MaxVertex 20

#define UnUsed (-1)
#define StartNodeHasNoHead (-1)
#define Infinity 32767
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

    class PathNode {
    public:
        Vertex thisVertex;
        Vertex Last;
        double distance;

        PathNode() = default;

        PathNode(Vertex thisVertex, Vertex Last, double distance) : thisVertex(thisVertex), Last(Last),
                                                                    distance(distance) {}

        PathNode(Vertex Last, double distance) : Last(Last), distance(distance) {}

        bool operator<(const PathNode &rhs) const {
            return distance < rhs.distance;
        }

        bool operator>(const PathNode &rhs) const {
            return rhs < *this;
        }

        bool operator<=(const PathNode &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const PathNode &rhs) const {
            return !(*this < rhs);
        }

        bool operator==(const PathNode &rhs) const {
            return distance == rhs.distance;
        }

        bool operator!=(const PathNode &rhs) const {
            return !(rhs == *this);
        }

    };

    typedef PathNode *PtrToPathNode;

    Graph();

    void TopSort();

    void Add(Vertex ver, list<pair<Vertex, double >> &link_list, T t);

    Graph<T> &Link(Vertex startVertex, Vertex pointVertex, double weight);

    Graph<T> &Link(Vertex startVertex, Vertex pointVertex) {
        return Link(startVertex, pointVertex, 1);
    };

    Graph<T> &DoubleLink(Vertex startVertex, Vertex pointVertex, double weight);

    Graph<T> &DoubleLink(Vertex startVertex, Vertex pointVertex) {
        return DoubleLink(startVertex, pointVertex, 1);
    };

    double FindShortestWayUnweighted(Vertex startVertex, Vertex endVertex);

    double Dijkstra(Vertex startVertex, Vertex endVertex);

private:
    int unusedVex = 0;


    list<GraphNode> vertex_vector[MaxVertex];
    stack<Vertex> InDegreeZero{};
    map<Vertex, T> keyMap{};
    int InDegree[MaxVertex]{};

    void PutIntoStack();

    void SetUsed(Vertex vertex) {
        if (InDegree[vertex] == UnUsed) {
            InDegree[vertex] = 0;
        }
    }
};


/**
 *
 * @tparam T 储存在node里面的数据类型
 * @param ver 起始的顶点
 * @param link_list ：Vertex 指向的顶点，weight为权重,link_list为这样一个链表
 * @param t 储存在node里面的数据
 */
template<class T>
void Graph<T>::Add(Vertex ver, list<pair<Vertex, double >> &link_list, T t) {
    keyMap.insert(pair<Vertex, T>(ver, t));
    list<GraphNode> add_list;
    SetUsed(ver);
    for (auto itor : link_list) {
        SetUsed(itor.first);
        InDegree[itor.first]++;
        GraphNode graphNode(itor.first, itor.second);
        add_list.push_back(graphNode);
    }


    vertex_vector[ver] = add_list;
}

template<class T>
void Graph<T>::PutIntoStack() {
    for (int i = 0; i < MaxVertex; i++) {
        if (!InDegree[i]) {
            InDegreeZero.push(i);
        }
        if (InDegree[i] == UnUsed) { unusedVex++; }
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
        if (counter == MaxVertex - unusedVex) {
            printf("%d \nThe way ends.", v);
        } else { printf("%d -> ", v); }

        for (auto itor:vertex_vector[v]) {
            if (--InDegree[itor.v] == 0)
                InDegreeZero.push(itor.v);
        }
    }

    if (counter != MaxVertex - unusedVex) {
        printf("Graph has a circle.\n");
    }
}

/**
 * 以添加指向性向量的形式链接两顶点
 * @tparam T 测试阶段没写
 * @param startVertex 起始点
 * @param pointVertex 指向点
 * @param weight 权重
 * @return 链式操作
 */
template<class T>
Graph<T> &Graph<T>::Link(Vertex startVertex, Vertex pointVertex, double weight) {
    GraphNode graphNode(pointVertex, weight);
    vertex_vector[startVertex].push_back(graphNode);
    SetUsed(startVertex);
    SetUsed(pointVertex);
    InDegree[pointVertex]++;
    return *this;
}

/*
 * 同上
 */
template<class T>
Graph<T> &Graph<T>::DoubleLink(Vertex startVertex, Vertex pointVertex, double weight) {
    SetUsed(startVertex);
    SetUsed(pointVertex);
    GraphNode graphNode(pointVertex, weight);
    vertex_vector[startVertex].push_back(graphNode);
    GraphNode graphNode1(startVertex, weight);
    vertex_vector[pointVertex].push_back(graphNode1);
    InDegree[pointVertex]++;
    InDegree[startVertex]++;
    return *this;
}

/**
 *
 * @tparam T
 * @param startVertex
 * @param endVertex
 * @return 返回最短路径长并打印路径
 */
template<class T>
double Graph<T>::FindShortestWayUnweighted(Vertex startVertex, Vertex endVertex) {
    PathNode pathNode_list[MaxVertex];
    for (auto &i : pathNode_list) {
        i.Last = StartNodeHasNoHead;
        i.distance = Infinity;
    }

    pathNode_list[startVertex].distance = 0;
    queue<Vertex> vertex_queue;
    vertex_queue.push(startVertex);
    Vertex tmp;
    while (!vertex_queue.empty()) {
        tmp = vertex_queue.front();
        vertex_queue.pop();
        for (auto itor:vertex_vector[tmp]) {
            if (pathNode_list[itor.v].distance == Infinity) {
                pathNode_list[itor.v].distance = pathNode_list[tmp].distance + 1;
                pathNode_list[itor.v].Last = tmp;
                vertex_queue.push(itor.v);
            }
            if (itor.v == endVertex) {
                auto Pathtmp = itor.v;
                while (Pathtmp != StartNodeHasNoHead) {
                    printf("%d <-", Pathtmp);
                    Pathtmp = pathNode_list[Pathtmp].Last;
                }
                return pathNode_list[itor.v].distance;
            }
        }

    }

    return -1;
}

template<class T>
double Graph<T>::Dijkstra(Vertex startVertex, Vertex endVertex) {
    PathNode pathNode_list[MaxVertex];
    int num = 0;
    for (auto &i : pathNode_list) {
        i.thisVertex = num++;
        i.Last = StartNodeHasNoHead;
        i.distance = Infinity;
    }

    Heap<PathNode> distanceheap;
    PathNode pathNode(startVertex, StartNodeHasNoHead, 0);
    distanceheap.insert(pathNode);
    pathNode_list[startVertex].distance = 0;
    Vertex tmp, link_tmp;
    tmp = startVertex;
    while (!distanceheap.empty()) {

        for (auto itor:vertex_vector[tmp]) {
            if (pathNode_list[itor.v].distance == Infinity) {
                pathNode_list[itor.v].distance = pathNode_list[tmp].distance + itor.weight;
                pathNode_list[itor.v].Last = tmp;
                distanceheap.insert(pathNode_list[itor.v]);
            } else if (pathNode_list[itor.v].distance > pathNode_list[tmp].distance + itor.weight) {
                pathNode_list[itor.v].distance = pathNode_list[tmp].distance + itor.weight;
                pathNode_list[itor.v].Last = tmp;
            }

        }
        tmp = distanceheap.findMin().thisVertex;
        distanceheap.DeleteMin();


    }
    int Pathtmp = endVertex;
    while (Pathtmp != StartNodeHasNoHead) {
        printf("%d <-", Pathtmp);
        Pathtmp = pathNode_list[Pathtmp].Last;
    }

    return pathNode_list[endVertex].distance;
}

template<class T>
Graph<T>::Graph() {
    for (auto &i : InDegree) {
        i = UnUsed;
    }
}


#endif //DATASTRUCTURESINCPP_GRAPH_H

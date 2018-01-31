//
// Created by leonardo on 18-1-28.
//

#ifndef DATASTRUCTURESINCPP_TREE_H
#define DATASTRUCTURESINCPP_TREE_H

#include <iostream>

using std::iostream;

template<typename T>
class BiTree {
public:
    class Node {
    public:
        T t;
        Node *Left;
        Node *Right;

        Node(T myt) {
            t = myt;
            Left = Right = nullptr;
        }
    };

    typedef Node *PtrToNode;
    typedef PtrToNode Tree;

    BiTree(Node *myroot) {
        root = myroot;
    };

    PtrToNode findtoPtr(T t);

    PtrToNode findMintoPtr();

    PtrToNode findMaxtoPtr();

    void insert(T t);

    void Delete(T t);

    void clear();

    bool operator<(Node node1, Node node2);

    bool operator>(Node node1, Node node2);

    bool operator==(Node node1, Node node2);

    T findmin();

    T findmax();

private:
    Tree root;

    void insert(T t, PtrToNode ptrToNode);

    PtrToNode findtoPtr(T t, PtrToNode ptrToNode);
};

template<typename T>
BiTree::PtrToNode BiTree<T>::findtoPtr(T t) {
    return findtoPtr(t, root);
}

template<typename T>
BiTree::PtrToNode BiTree<T>::findMintoPtr() {
    return nullptr;
}

template<typename T>
BiTree::PtrToNode BiTree<T>::findMaxtoPtr() {
    return nullptr;
}

template<typename T>
void BiTree<T>::insert(T t) {

    if (root == nullptr) {
        auto *mpNode = new Node(t);
        root = mpNode;
    } else {
        insert(t, root);
    }
}

template<typename T>
void BiTree<T>::Delete(T t) {

}

template<typename T>
bool BiTree<T>::operator<(BiTree::Node node1, BiTree::Node node2) {
    return node1.t < node2.t;
}

template<typename T>
T BiTree<T>::findmin() {
    return nullptr;
}

template<typename T>
T BiTree<T>::findmax() {
    return nullptr;
}

template<typename T>
void BiTree<T>::clear() {

}

template<typename T>
bool BiTree<T>::operator>(BiTree::Node node1, BiTree::Node node2) {
    return node1.t > node2.t;
}

template<typename T>
bool BiTree<T>::operator==(BiTree::Node node1, BiTree::Node node2) {
    return node1.t == node2.t;
}

template<typename T>
void BiTree<T>::insert(T t, BiTree::PtrToNode ptrToNode) {

    if (t < ptrToNode->t) {
        if (ptrToNode->Left == nullptr) {
            auto *mpNode = new Node(t);
            ptrToNode->Left = mpNode;
        } else {
            insert(t, ptrToNode->Left);
        }
    } else if (t > ptrToNode->t) {
        if (ptrToNode->Right == nullptr) {
            auto *mpNode = new Node(t);
            ptrToNode->Right = mpNode;
        } else {
            insert(t, ptrToNode->Right);
        }
    }
}

template<typename T>
BiTree::PtrToNode BiTree<T>::findtoPtr(T t, BiTree::PtrToNode ptrToNode) {
    if (t == ptrToNode->t) {
        return ptrToNode;
    } else if (t < ptrToNode->t){
        if(ptrToNode->Left == nullptr){
            return nullptr;
        } else{
            findtoPtr(t,ptrToNode->Left);
        }
    } else if (t>ptrToNode->t){
        if(ptrToNode->Right== nullptr){
            return nullptr;
        } else{
            findtoPtr(t,ptrToNode->Right);
        }
    }
        return nullptr;
}


#endif //DATASTRUCTURESINCPP_TREE_H

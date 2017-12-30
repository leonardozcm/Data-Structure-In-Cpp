//
// Created by leonardo on 17-12-30.
//

#ifndef DATASTRUCTURESINCPP_DOUBLELINKLIST_H
#define DATASTRUCTURESINCPP_DOUBLELINKLIST_H

#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkList {
public:
    const string OutOfBoundary = "Error: Index Out of Boundary";
    const string NoNext = "Error: There is no next elements to exchange";
    const string PositivePosition = "Error: position must be positive!";
    const string RemoveIllegal = "Error: Remove item out of bounds!";

    class Node {
    public:
        T t;
        Node *next;
        Node *previous;

        Node(T myt) {
            t = myt;
            previous = nullptr;
            next = nullptr;
        }
    };

    typedef Node *PtrToNode;
    typedef PtrToNode Position;

    DoubleLinkList() {
        head = nullptr;
    };

    bool isEmpty();

    bool isLast(Position position);

    void InsertHead(T t);

    void Insert(T t, int pos);

    void removeByEle(T t);

    void removeByPos(int pos);

    Position FindPervious(T t);

    T get(int pos);

    int Length();

    int FindByEle(T t);

    Position FindByPos(int pos);

    void add(T t);

    void Print();

    void swapWithNext(int frontOne);

    void Eroor(string msg);

    ~DoubleLinkList() {
        Node *temp;
        for (int i = 0; i < length; ++i) {
            temp = head;
            head = head->next;
            delete temp;
        }
    };

private:


    Node *head;
    int length = 0;


};

template<typename T>
bool DoubleLinkList<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
bool DoubleLinkList<T>::isLast(DoubleLinkList::Position position) {
    return position->next == nullptr;
}

template<typename T>
void DoubleLinkList<T>::InsertHead(T t) {
    auto *mynode = new Node(t);
    head = mynode;
    length++;
}

template<typename T>
void DoubleLinkList<T>::Insert(T t, int pos) {
    if (pos == 0) {
        InsertHead(t);
    } else if (pos > length) {
        Eroor(OutOfBoundary);
    } else{
        PtrToNode ptrToNode=FindByPos(pos-1);
        auto *tmp =new Node(t);
        tmp->previous=ptrToNode;
        tmp->next=ptrToNode->next;
        ptrToNode->next->previous=tmp;
        ptrToNode->next=tmp;
    }
}

template<typename T>
void DoubleLinkList<T>::removeByEle(T t) {


}


#endif //DATASTRUCTURESINCPP_DOUBLELINKLIST_H

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

        explicit Node(T myt) {
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

    void removeByPos(int pos);

    T get(int pos);

    int Length();

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
    } else {
        PtrToNode ptrToNode = FindByPos(pos - 1);
        auto *tmp = new Node(t);
        tmp->previous = ptrToNode;
        tmp->next = ptrToNode->next;
        if(ptrToNode->next!= nullptr){
            ptrToNode->next->previous = tmp;
        }
        ptrToNode->next = tmp;
        length++;
    }
}

template<typename T>
void DoubleLinkList<T>::removeByPos(int pos) {
    if (pos < 0) {
        Eroor(PositivePosition);
    } else if (pos == 0) {
        PtrToNode tmp = head->next;
        tmp->previous = nullptr;
        delete head;
        head = tmp;
        length--;
    } else {
        PtrToNode tmp = FindByPos(pos);
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        delete tmp;
        length--;
    }
}

template<typename T>
T DoubleLinkList<T>::get(int pos) {
    return FindByPos(pos)->t;
}

template<typename T>
int DoubleLinkList<T>::Length() {
    return length;
}

template<typename T>
typename DoubleLinkList<T>::Position DoubleLinkList<T>::FindByPos(int pos) {
    PtrToNode tmp = nullptr;
    if (pos < 0) {
        Eroor(PositivePosition);
    } else {
        tmp = head;
        for (int i = 0; i < pos; ++i) {
            tmp = tmp->next;
        }
        return tmp;
    }
    return nullptr;
}

template<typename T>
void DoubleLinkList<T>::add(T t) {
    Insert(t, length);
}

template<typename T>
void DoubleLinkList<T>::Print() {
    printf("[");
    PtrToNode iterator = head;
    while (iterator != nullptr) {
        if (iterator->next == nullptr) {
            cout << iterator->t;
        } else {
            cout << iterator->t << ",";
        }
        iterator = iterator->next;
    }
    printf("]\n");
}

template<typename T>
void DoubleLinkList<T>::swapWithNext(int frontOne) {
    if (frontOne < 0 || frontOne >= length - 1) {
        Eroor(OutOfBoundary);
    } else if (frontOne == 0) {
        PtrToNode tmp = head->next;
        head->next = tmp->next;
        head->previous = head;
        tmp->next = head;
        tmp->previous = nullptr;
        head = tmp;
    } else {
        PtrToNode start = FindByPos(frontOne - 1);
        PtrToNode front = start->next;
        PtrToNode behind = front->next;

        start->next = behind;
        behind->next->previous = front;

        front->next = behind->next;
        front->previous = behind;
        behind->previous = start;
        behind->next = front;
    }
}

template<typename T>
void DoubleLinkList<T>::Eroor(string msg) {
    cout << msg << endl;
}


#endif //DATASTRUCTURESINCPP_DOUBLELINKLIST_H

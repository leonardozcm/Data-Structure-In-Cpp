//
// Created by leonardo on 17-12-23.
//

#ifndef DATASTRUCTURESINCPP_LIST_H
#define DATASTRUCTURESINCPP_LIST_H

#include <malloc.h>

template<typename T>
class List {
public:
    class Node {
    public:
        T t;
        Node *next;

        Node(T myt) {
            t = myt;
            next = nullptr;
        }
    };

    typedef Node *PtrToNode;
    typedef PtrToNode Position;

    List() {
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

    ~List() {
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
bool List<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
bool List<T>::isLast(typename List<T>::Position position) {
    return position->next == nullptr;
}

template<typename T>
void List<T>::InsertHead(T t) {
    Node *mhead = new Node(t);
    mhead->next = head;
    head = mhead;
}

template<typename T>
void List<T>::Insert(T t, int pos) {
    if (pos <= 0) {
        InsertHead(t);
    } else {
        typename List<T>::Position previous = FindByPos(pos - 1);
        typename List<T>::Position pnext = previous->next;
        Node *mpNode = new Node(t);
        previous->next = mpNode;
        mpNode->next = pnext;
    }
    length++;
}


template<typename T>
typename List<T>::Position List<T>::FindPervious(T myt) {
    Position p;
    p = head;
    while (p->next != nullptr && p->next->t != myt) {
        p = p->next;
    }
    return p;
}

template<typename T>
void List<T>::removeByEle(T t) {
    List<T>::Position p, TmpCell;


    if (head->t == t) {
        typename List<T>::Position Tmpcell = head;
        head = head->next;
        free(Tmpcell);
    } else {
        p = FindPervious(t);

        if (!isLast(p)) {
            TmpCell = p->next;
            p->next = TmpCell->next;
            free(TmpCell);
            length--;
        }
    }
    length--;
}

template<typename T>
void List<T>::removeByPos(int pos) {
    if (pos < 0) {
        printf("Error: position must be positive!");
    } else if (pos == 0) {
        typename List<T>::Position Tmpcell = head;
        head = head->next;
        free(Tmpcell);
        length--;
    } else if (pos < length - 1) {
        typename List<T>::Position mprevious = FindByPos(pos - 1);
        typename List<T>::Position TmpCell = mprevious->next;
        mprevious->next = TmpCell->next;
        free(TmpCell);
        length--;
    } else {
        printf("Error: Remove item out of bounds!");
    }


}

template<typename T>
T List<T>::get(int pos) {
    return FindByPos(pos)->t;
}

template<typename T>
int List<T>::Length() {
    return length;
}

template<typename T>
int List<T>::FindByEle(T t) {
    typename List<T>::Position position;
    position = head;

    int pos = 0;
    while (position != nullptr) {
        if (position->t == t) {
            return pos;
        }
        pos++;
        position = position->next;
    }
    return -1;
}

template<typename T>
typename List<T>::Position List<T>::FindByPos(int pos) {
    Position position = head;
    int i = 0;

    if (pos < 0) {
        return nullptr;
    }

    while (position->next != nullptr && i++ != pos) {
        position = position->next;
    }
    return position;
}

template<typename T>
void List<T>::add(T t) {
    Insert(t, length);
}


#endif //DATASTRUCTURESINCPP_LIST_H

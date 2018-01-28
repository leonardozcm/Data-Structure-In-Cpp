//
// Created by leonardo on 17-12-23.
//

#ifndef DATASTRUCTURESINCPP_LIST_H
#define DATASTRUCTURESINCPP_LIST_H

#include <iostream>

using namespace std;

template<typename T>
class List {
public:
    const string OutOfBoundary = "Error: Index Out of Boundary";
    const string NoNext = "Error: There is no next elements to exchange";
    const string PositivePosition = "Error: position must be positive!";
    const string RemoveIllegal = "Error: Remove item out of bounds!";

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

    void Print();

    void PrintLots(List<int> list);

    void swapWithNext(int frontOne);

    void Eroor(string msg);

    void Clear();

    List<T>& operator=(List<T> obj);

    ~List() {
        Clear();
        cout<<"析构被调用"<<endl;
    }

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
    auto *mhead = new Node(t);
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
        auto *mpNode = new Node(t);
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
        Eroor(PositivePosition);
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
        Eroor(RemoveIllegal);
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

template<typename T>
void List<T>::Print() {
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
void List<T>::PrintLots(List<int> list) {
    /*
    PtrToNode iterator = list.head;
    printf("[");
    while (iterator != nullptr) {
        if (iterator->next == nullptr) {
            cout<<get(iterator->t);
        } else {
            cout<<get(iterator->t)<<",";
        }
        iterator = iterator->next;
    }
    printf("]\n");
*/
    printf("[");
    for (int i = 0; i < list.Length() - 1; ++i) {
        cout << get(list.get(i)) << ",";
    }
    cout << get(list.get(list.Length() - 1)) << "]" << endl;
}

template<typename T>
void List<T>::swapWithNext(int frontOne) {
    if (frontOne < 0 || frontOne >= length - 1) {
        Eroor(OutOfBoundary);
    } else if (frontOne == 0) {
        PtrToNode tmp = head->next;
        head->next = tmp->next;
        head = tmp;
    } else {
        PtrToNode start = FindByPos(frontOne - 1);
        PtrToNode front = start->next;
        PtrToNode behind = front->next;

        start->next = behind;
        front->next = behind->next;
        behind->next = front;
    }


}

template<typename T>
void List<T>::Eroor(const string msg) {
    cout << msg << endl;
}

template<typename T>
void List<T>::Clear() {
    Node *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template<typename T>
List<T>& List<T>::operator=(List<T> obj) {
    Clear();
    PtrToNode objtmp = obj.head;
    PtrToNode dirtmp = head;
    if (objtmp->t != NULL)
        dirtmp->t = objtmp->t;
    while (objtmp != nullptr) {
        this->add(objtmp->t);
        objtmp = objtmp->next;
    }
    return *this;
}


#endif //DATASTRUCTURESINCPP_LIST_H

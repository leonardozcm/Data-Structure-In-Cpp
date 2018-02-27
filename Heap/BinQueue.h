//
// Created by leonardo on 18-2-26.
//

#ifndef DATASTRUCTURESINCPP_BINQUEUE_H
#define DATASTRUCTURESINCPP_BINQUEUE_H

#include <iostream>

#define Maxtrees 11 //1024个节点
#define Capacity 1024

using namespace std;

template<typename T>
class BinQueue {
public:
    BinQueue() {
        Currentsize = 0;
        for (int i = 0; i < Maxtrees; ++i) {
            TheTree[i] = nullptr;
        }
    };

    class BinNode {
    public:
        T t;
        BinNode *LeftChild;
        BinNode *NextSilbling;

        explicit BinNode(T myt) {
            t = myt;
            LeftChild = NextSilbling = nullptr;
        };
    };

    typedef BinNode *BinTree;

    BinTree CombineTrees(BinTree T1, BinTree T2);

    void Merge(BinQueue H);

    T DeleteMin();

    bool isEmpty();

    void insert(T t);

private:
    int Currentsize;
    BinTree TheTree[Maxtrees];


    void Error();
};

template<typename T>
void BinQueue<T>::Merge(BinQueue H) {
    BinTree T1, T2, Carry;
    T1 = T2 = Carry = nullptr;
    int i, j;

    if (Currentsize + H.Currentsize > Capacity) {
        Error();
        return;
    }

    Currentsize += H.Currentsize;
    for (i = 0; i < Maxtrees; ++i) {
        T1 = TheTree[i];
        T2 = H.TheTree[i];
        switch (!!T1 + 2 * !!T2 + 4 * !!Carry) {
            case 0:
            case 1:
                break;
            case 2:
                TheTree[i] = T2;
                H.TheTree[i] = T1;
                break;
            case 3:
                Carry = CombineTrees(T1, T2);
                TheTree[i] = H.TheTree[i] = nullptr;
                break;
            case 4:
                TheTree[i] = Carry;
                Carry = nullptr;
                break;
            case 5:
                Carry = CombineTrees(T1, Carry);
                TheTree[i] = nullptr;
                break;
            case 6:
                TheTree[i] = CombineTrees(T2, Carry);
                H.TheTree[i] = nullptr;
                break;
            case 7:
                TheTree[i] = Carry;
                Carry = CombineTrees(T1, T2);
                H.TheTree[i] = nullptr;
                break;
        }
    }

}

template<typename T>
T BinQueue<T>::DeleteMin() {
    int i, j;
    bool isFirst = true;
    int MinTree = 0;
    BinQueue<T> deletedQueue;
    BinNode *deletedTree, *oldRoot;
    T MinItem;

    if (isEmpty()) {
        Error();
    }

    for (i = 0; i < Maxtrees; ++i) {
        if (TheTree[i]) {
            if (isFirst) {
                MinItem = TheTree[i]->t;
                isFirst = false;
            }
            if (TheTree[i]->t < MinItem) {
                MinItem = TheTree[i]->t;
                MinTree = i;
            }
        }
    }

    oldRoot = TheTree[MinTree];
    deletedTree = oldRoot->LeftChild;
    delete oldRoot;

    deletedQueue.Currentsize = (1 << MinTree) - 1;
    for (j = MinTree - 1; j >= 0; j--) {
        deletedQueue.TheTree[j] = deletedTree;
        deletedTree = deletedTree->NextSilbling;
        deletedQueue.TheTree[j]->NextSilbling = nullptr;
    }
    TheTree[MinTree] = nullptr;
    Currentsize -= deletedQueue.Currentsize + 1;

    Merge(deletedQueue);
    return MinItem;
}

template<typename T>
typename BinQueue<T>::BinTree BinQueue<T>::CombineTrees(BinQueue::BinTree T1, BinQueue::BinTree T2) {
    if (T2) {
        if (T1->t > T2->t)
            return CombineTrees(T2, T1);
        if (T1->LeftChild)
            T2->NextSilbling = T1->LeftChild;
        else
            T2->NextSilbling = nullptr;
        T1->LeftChild = T2;

    }
    return T1;
}

template<typename T>
void BinQueue<T>::Error() {

}

template<typename T>
bool BinQueue<T>::isEmpty() {
    return !Currentsize;
}

template<typename T>
void BinQueue<T>::insert(T t) {
//todo insert();
}


#endif //DATASTRUCTURESINCPP_BINQUEUE_H

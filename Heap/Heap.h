//
// Created by leonardo on 18-2-19.
//

#ifndef DATASTRUCTURESINCPP_HEAP_H
#define DATASTRUCTURESINCPP_HEAP_H


#include <iostream>

#define MaxIndex 13

using namespace std;

template<typename T>
class Heap {
public:

    void insert(T t);

    void Delete(T t);

    void DeleteMin();

    T findMin();

    void print();

    bool IsFull();

private:
    T heap[MaxIndex];

    int size = 0;
};

template<typename T>
void Heap<T>::insert(T t) {
    if (IsFull()) {
        return;
    }
    int i = 0;
    if (size) {
        for (i = ++size - 1; heap[i / 2] > t; i /= 2)
            heap[i] = heap[i / 2];

    } else {
        size++;
    }
    heap[i] = t;
}

template<typename T>
void Heap<T>::Delete(T t) {

}

template<typename T>
T Heap<T>::findMin() {
    return heap[0];
}

template<typename T>
bool Heap<T>::IsFull() {
    return size == MaxIndex - 1;
}

template<typename T>
void Heap<T>::DeleteMin() {
    int i, child;
    T MinElement, LastElement;

    if (!size) {
        return;
    }
    LastElement = heap[size - 1];

    for (i = 0; (i + 1) * 2 <= size; i = child) {
        child = 2 * i;
        if (LastElement < heap[2 * i + 1] && LastElement < heap[2 * i + 2]) {
            heap[i] = LastElement;
        }
        if (heap[2 * i + 1] < heap[2 * i + 2]) {
            heap[i] = heap[2 * i + 1];
            child = child + 1;
        } else {
            heap[i] = heap[2 * i + 2];
            child = child + 2;
        }

    }
    heap[i] = LastElement;
    size--;
}

template<typename T>
void Heap<T>::print() {
    for (int i = 0; i < size; ++i) {
        cout << heap[i] << "," ;
    }
}


#endif //DATASTRUCTURESINCPP_HEAP_H

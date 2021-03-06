//
// Created by leonardo on 17-12-29.
//

#ifndef DATASTRUCTURESINCPP_QUEUE_H
#define DATASTRUCTURESINCPP_QUEUE_H

template<typename T>
class Queue {
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

    Queue() {
        head = rear = nullptr;
        length = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(T t);

    void destroy() {
        if (!isEmpty()) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            if (isEmpty()) {
                rear = nullptr;
            }
        }
    }

    T dequeue();

    T getHead();

    T getRear();

    Queue<T> &operator=(Queue<T> obj);

    void Clear();

    ~Queue() {
        Clear();
    }

private:
    PtrToNode head;
    PtrToNode rear;
    int length;
};

template<typename T>
void Queue<T>::enqueue(T t) {
    auto *ptrnode = new Node(t);
    if (rear != nullptr) {
        rear->next = ptrnode;
        rear = ptrnode;
    } else {
        head = rear = ptrnode;
    }
    length++;
}

template<typename T>
T Queue<T>::getHead() {
    if (!isEmpty()) {
        return head->t;
    }
}

template<typename T>
T Queue<T>::getRear() {
    if (!isEmpty()) {
        return rear->t;
    }
}

template<typename T>
void Queue<T>::Clear() {
    Node *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template<typename T>
Queue<T> &Queue<T>::operator=(Queue<T> obj) {
    Clear();
    PtrToNode objtmp = obj.head;
    while (objtmp != nullptr) {
        this->enqueue(objtmp->t);
        objtmp = objtmp->next;
    }
    return *this;
}

template<typename T>
T Queue<T>::dequeue() {
    T t = getHead();
    head = head->next;
    return t;
}

#endif //DATASTRUCTURESINCPP_QUEUE_H

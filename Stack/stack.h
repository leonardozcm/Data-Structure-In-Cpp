//
// Created by leonardo on 17-12-27.
//

#ifndef DATASTRUCTURESINCPP_STACK_H
#define DATASTRUCTURESINCPP_STACK_Hop

template<typename T>
class Stack {
public:
    class Node {
    public:
        Node *next;
        T t;

        Node(T myt) {
            t = myt;
            next = nullptr;
        }
    };

    typedef Node *PtrToNode;

    Stack();

    virtual ~Stack();

    bool isEmpty();

    // Stack CreateStack();
    //void DisposeStack();
    void MakeEmpty();

    void Push(T t);

    T Top();

    void Pop();

    T TopAndPop();

    int count();

private:
    PtrToNode top;
    int counts = 0;
};

template<typename T>
bool Stack<T>::isEmpty() {
    return counts == 0;
}


template<typename T>
int Stack<T>::count() {
    return counts;
}

template<typename T>
void Stack<T>::MakeEmpty() {
    if (top != nullptr) {
        while (!isEmpty()) {
            Pop();
        }
    }
    counts=0;
}

template<typename T>
void Stack<T>::Push(T myt) {
    Node *tmp = new Node(myt);
    if (isEmpty()) {
        top = tmp;
        counts++;
    } else {
        tmp->next = top;
        top = tmp;
        counts++;
    }
}

template<typename T>
T Stack<T>::Top() {
    if (isEmpty()) {
        return NULL;
    } else {
        return top->t;
    }

}

template<typename T>
void Stack<T>::Pop() {
    PtrToNode firstcell;

    if (!isEmpty()) {
        firstcell = top;
        top = top->next;
        delete firstcell;
        counts--;
    }
}

template<typename T>
T Stack<T>::TopAndPop() {
    return nullptr;
}

template<typename T>
Stack<T>::Stack() { top = nullptr; }

template<typename T>
Stack<T>::~Stack() {
    PtrToNode temp;
    for (int i = 0; i < counts; ++i) {
        temp = top;
        top = top->next;
        delete temp;
    }
}


#endif //DATASTRUCTURESINCPP_STACK_H

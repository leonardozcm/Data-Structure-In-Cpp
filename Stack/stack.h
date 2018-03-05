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

        explicit Node(T myt) {
            t = myt;
            next = nullptr;
        }
    };

    typedef Node *PtrToNode;

    Stack();

    bool isEmpty();

    void MakeEmpty();

    void Push(T t);

    PtrToNode Top();

    void Pop();

    PtrToNode TopAndPop();

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
    counts = 0;
}

template<typename T>
void Stack<T>::Push(T myt) {
    auto *tmp = new Node(myt);
    if (isEmpty()) {
        top = tmp;
        counts++;
    } else {
        tmp->next = top;
        top = tmp;
        counts++;
    }
}

/*template<typename T>
 Stack<T>::Top() {
    if (isEmpty()) {
        return nullptr;
    } else {
        return top->t;
    }

}*/

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
Stack<T>::Stack() { top = nullptr; }

template<typename T>
typename Stack<T>::PtrToNode Stack<T>::Top() {
        return top;
}

template<typename T>
typename Stack<T>::PtrToNode Stack<T>::TopAndPop() {
    PtrToNode  ptrToNode=Top();
    Pop();
    return ptrToNode;
}


#endif //DATASTRUCTURESINCPP_STACK_H

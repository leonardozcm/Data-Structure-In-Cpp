//
// Created by leonardo on 17-12-29.
//

#ifndef DATASTRUCTURESINCPP_QUEUE_H
#define DATASTRUCTURESINCPP_QUEUE_H

template <typename T>
class Queue{
public:
    class Node{
    public:
        T t;
        Node *next;

        Node(T myt){
            t=myt;
            next= nullptr;
        }
    };

    typedef Node *PtrToNode;

    Queue(){
        head = rear = nullptr;
        length = 0;
    }

    ~Queue(){
        Node *temp;
        while (head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool isEmpty(){
        return head== nullptr;
    }

    void enqueue(T t);

    void dequeue(){
        if(!isEmpty()){
            Node *tmp=head;
            head = head->next;
            delete tmp;
            if(isEmpty()){
                rear = nullptr;
            }
        }
    }

    T getHead();

    T getRear();

private:
    PtrToNode head;
    PtrToNode rear;
    int length;
};

template<typename T>
void Queue<T>::enqueue(T t) {
    Node *ptrnode =new Node(t);
    if(rear!= nullptr){
        rear->next=ptrnode;
        rear = ptrnode;
    } else{
        head = rear = ptrnode;
    }
    length++;
    /*ptrnode->next=head;
    head = ptrnode;
    length++;
    if(length ==1){
        rear = ptrnode;
    }*/
}

template<typename T>
T Queue<T>::getHead() {
    if(!isEmpty()){
        return head->t;
    }
}

template<typename T>
T Queue<T>::getRear() {
    if(!isEmpty()){
        return rear->t;
    }
}

#endif //DATASTRUCTURESINCPP_QUEUE_H

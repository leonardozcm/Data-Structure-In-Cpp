//
// Created by leonardo on 18-2-4.
//

#ifndef DATASTRUCTURESINCPP_AVLTREE_H
#define DATASTRUCTURESINCPP_AVLTREE_H

#include <iostream>

using namespace std;

template<typename T>
class AVLTree {
public:
    class AVLNode {
    public:
        int bf;//平衡因子：-1,0,1.其值为右子树的高度减去左子树的高度
        T t;
        AVLNode *Left;
        AVLNode *Right;
        AVLNode *Parent;

        AVLNode(T myT) {
            bf = 0;
            t = myT;
            Left = Right = Parent = nullptr;
        }
    };

    typedef AVLNode *PtrToNode;
    typedef PtrToNode Tree;

    void insert(T t);

    void Delete(T t);

    void print();

    void singleRotateWithLeft(PtrToNode ptrToNode);

    void doubleRotateWithLeft(PtrToNode ptrToNode);

    void singleRotateWithRight(PtrToNode ptrToNode);

    void doubleRotateWithRight(PtrToNode ptrToNode);


private:
    Tree root;

    void print(PtrToNode ptrToNode, int spacenum);

    void insert(T t, PtrToNode ptrToNode);

    PtrToNode findtoPtr(T t, PtrToNode ptrToNode);

    void space(int num);

    void clear(PtrToNode ptrToNode);

};

template<typename T>
void AVLTree<T>::insert(T t) {

}

template<typename T>
void AVLTree<T>::Delete(T t) {

}

template<typename T>
void AVLTree<T>::print() {
    print(root, 0);
}

template<typename T>
void AVLTree<T>::clear(AVLTree::PtrToNode ptrToNode) {

}

template<typename T>
void AVLTree<T>::space(int num) {
    for (int i = 0; i < num; i++)
        cout << ' ';
}

template<typename T>
AVLTree::PtrToNode AVLTree<T>::findtoPtr(T t, AVLTree::PtrToNode ptrToNode) {
    return nullptr;
}

template<typename T>
void AVLTree<T>::insert(T t, AVLTree::PtrToNode ptrToNode) {

}

template<typename T>
void AVLTree<T>::print(AVLTree::PtrToNode ptrToNode, int spacenum) {
    if (ptrToNode == nullptr)return;
    print(ptrToNode->Right, spacenum + 2);
    space(spacenum);
    cout << ptrToNode->t << endl;
    print(ptrToNode->Left, spacenum + 2);
}

template<typename T>
void AVLTree<T>::singleRotateWithLeft(AVLTree::PtrToNode ptrToNode) {

}

template<typename T>
void AVLTree<T>::doubleRotateWithLeft(AVLTree::PtrToNode ptrToNode) {

}

template<typename T>
void AVLTree<T>::singleRotateWithRight(AVLTree::PtrToNode ptrToNode) {

}

template<typename T>
void AVLTree<T>::doubleRotateWithRight(AVLTree::PtrToNode ptrToNode) {

}

template<typename T>
void AVLTree<T>::insert(T t) {

}


#endif //DATASTRUCTURESINCPP_AVLTREE_H

//
// Created by leonardo on 18-1-28.
//

#ifndef DATASTRUCTURESINCPP_TREE_H
#define DATASTRUCTURESINCPP_TREE_H

#include <iostream>

using namespace std;

template<typename T>
class BiTree {
public:
    int trueDeleteMode = 1;
    int fakeDeleteMode = 0;

    class Node {
    public:
        T t;
        bool isDelete;
        Node *Left;
        Node *Right;

        Node() {

        }

        Node(T myt) {
            t = myt;
            Left = Right = nullptr;
            isDelete = false;
        }

        bool operator<(const Node &node1) const;

        bool operator>(const Node &node1) const;

        bool operator==(const Node &node1) const;
    };

    typedef Node *PtrToNode;
    typedef PtrToNode Tree;

    PtrToNode findtoPtr(T t);

    PtrToNode findMintoPtr();

    PtrToNode findMaxtoPtr();

    void insert(T t);

    void Delete(T t);

    void clear();

    T findmin();

    T findmax();

    void print();

    ~BiTree() {
        clear();
    }

private:
    Tree root = nullptr;

    void insert(T t, PtrToNode ptrToNode);

    PtrToNode findtoPtr(T t, PtrToNode ptrToNode);

    PtrToNode findParents(T t, PtrToNode ptrToNode);

    PtrToNode findMintoPtr(PtrToNode ptrToNode);

    void space(int num);

    void print(PtrToNode ptrToNode, int spacenum);

    void clear(PtrToNode ptrToNode);

};

template<typename T>
bool BiTree<T>::Node::operator<(const BiTree::Node &node1) const {
    return this->t < node1.t;
}

template<typename T>
bool BiTree<T>::Node::operator>(const BiTree::Node &node1) const {
    return this->t > node1.t;
}

template<typename T>
bool BiTree<T>::Node::operator==(const BiTree::Node &node1) const {
    return this->t == node1.t;
}

template<typename T>
typename BiTree<T>::PtrToNode BiTree<T>::findtoPtr(T t) {
    return findtoPtr(t, root);
}

template<typename T>
typename BiTree<T>::PtrToNode BiTree<T>::findMintoPtr() {
    findMintoPtr(root);
}

template<typename T>
typename BiTree<T>::PtrToNode BiTree<T>::findMaxtoPtr() {
    PtrToNode tmp = root;
    if (root != nullptr) {
        while (tmp->Right) {
            tmp = tmp->Right;
        }
    }
    return tmp;
}

template<typename T>
void BiTree<T>::insert(T t) {

    if (root == nullptr) {
        auto *mpNode = new Node(t);
        root = mpNode;
    } else {
        insert(t, root);
    }
}

template<typename T>
T BiTree<T>::findmin() {
    return findMintoPtr()->t;
}

template<typename T>
T BiTree<T>::findmax() {
    return findMaxtoPtr()->t;
}

template<typename T>
void BiTree<T>::clear() {
    if (root != nullptr) {
        clear(root->Right);
        clear(root->Left);
    }
}

template<typename T>
void BiTree<T>::insert(T t, BiTree::PtrToNode ptrToNode) {

    if (t < ptrToNode->t) {
        if (ptrToNode->Left == nullptr) {
            auto *mpNode = new Node(t);
            ptrToNode->Left = mpNode;
        } else {
            insert(t, ptrToNode->Left);
        }
    } else if (t > ptrToNode->t) {
        if (ptrToNode->Right == nullptr) {
            auto *mpNode = new Node(t);
            ptrToNode->Right = mpNode;
        } else {
            insert(t, ptrToNode->Right);
        }
    }
}

template<typename T>
typename BiTree<T>::PtrToNode BiTree<T>::findtoPtr(T t, BiTree::PtrToNode ptrToNode) {
    if (t == ptrToNode->t) {
        return ptrToNode;
    } else if (t < ptrToNode->t) {
        if (ptrToNode->Left == nullptr) {
            return nullptr;
        } else {
            return findtoPtr(t, ptrToNode->Left);
        }
    } else if (t > ptrToNode->t) {
        if (ptrToNode->Right == nullptr) {
            return nullptr;
        } else {
            return findtoPtr(t, ptrToNode->Right);
        }
    }
    return nullptr;
}

template<typename T>
void BiTree<T>::Delete(T t) {
    PtrToNode tmp = findtoPtr(t);
    if (tmp != nullptr) {
        PtrToNode minInRight = findMintoPtr(tmp->Right);
        if (minInRight != nullptr) {
            tmp->t = minInRight->t;
            PtrToNode minParent = findParents(minInRight->t, tmp->Right);
            if (minParent != nullptr) {
                minParent->Left = minInRight->Right;
            }
            delete minInRight;

        } else {
            PtrToNode tmpParent = findParents(t, root);
            if (t < tmpParent->t) {
                tmpParent->Left = tmp->Left;
            } else {
                tmpParent->Right = tmp->Left;
            }
        }

    }
}

template<typename T>
typename BiTree<T>::PtrToNode BiTree<T>::findParents(T t, BiTree::PtrToNode ptrToNode) {
    if (t < ptrToNode->t) {
        if (ptrToNode->Left && t == ptrToNode->Left->t) {
            return ptrToNode;
        } else {
            return findParents(t, ptrToNode->Left);
        }
    } else if (t > ptrToNode->t) {
        if (ptrToNode->Right && t == ptrToNode->Right->t) {
            return ptrToNode;
        } else {
            return findParents(t, ptrToNode->Right);
        }
    }
    return nullptr;
}

template<typename T>
typename BiTree<T>::PtrToNode BiTree<T>::findMintoPtr(BiTree::PtrToNode ptrToNode) {
    PtrToNode tmp = ptrToNode;
    if (tmp != nullptr) {
        while (tmp->Left) {
            tmp = tmp->Left;
        }
    }
    return tmp;
}

template<typename T>
void BiTree<T>::print() {
    print(root, 0);
}

template<typename T>
void BiTree<T>::space(int num) {
    for (int i = 0; i < num; i++)
        cout << ' ';
}

template<typename T>
void BiTree<T>::print(BiTree::PtrToNode ptrToNode, int spacenum) {
    if (ptrToNode == nullptr)return;
    print(ptrToNode->Right, spacenum + 2);
    space(spacenum);
    cout << ptrToNode->t << endl;
    print(ptrToNode->Left, spacenum + 2);
}

template<typename T>
void BiTree<T>::clear(BiTree::PtrToNode ptrToNode) {
    if (ptrToNode != nullptr) {
        clear(ptrToNode->Left);
        clear(ptrToNode->Right);
        delete ptrToNode;
    }
}

#endif //DATASTRUCTURESINCPP_TREE_H

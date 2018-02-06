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

    void test(T t);

private:
    Tree root = nullptr;

    void print(PtrToNode ptrToNode, int spacenum);

    void insert(T t, PtrToNode ptrToNode);

    PtrToNode findtoPtr(T t, PtrToNode ptrToNode);

    void space(int num);

    void clear(PtrToNode ptrToNode);

    PtrToNode insertOperatTo_bf(PtrToNode ptrToNode);

};

template<typename T>
void AVLTree<T>::insert(T t) {
    if (root == nullptr) {
        auto *mpNode = new AVLNode(t);
        root = mpNode;
    } else {
        insert(t, root);
    }
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
    if (ptrToNode != nullptr) {
        clear(ptrToNode->Left);
        clear(ptrToNode->Right);
        delete ptrToNode;
    }
}

template<typename T>
void AVLTree<T>::space(int num) {
    for (int i = 0; i < num; i++)
        cout << ' ';
}

template<typename T>
typename AVLTree<T>::PtrToNode AVLTree<T>::findtoPtr(T t, AVLTree::PtrToNode ptrToNode) {
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
void AVLTree<T>::print(AVLTree::PtrToNode ptrToNode, int spacenum) {
    if (ptrToNode == nullptr)return;
    print(ptrToNode->Right, spacenum + 2);
    space(spacenum);
    cout << ptrToNode->t << endl;
    print(ptrToNode->Left, spacenum + 2);
}

template<typename T>
void AVLTree<T>::singleRotateWithLeft(AVLTree::PtrToNode ptrToNode) {
    PtrToNode root_parent = ptrToNode->Parent;
    PtrToNode right_son_left_leaves = ptrToNode->Right->Left;
    if (root_parent != nullptr) {

        if (root_parent->Left == ptrToNode) {
            root_parent->Left = ptrToNode->Right;
        } else {
            root_parent->Right = ptrToNode->Right;
        }
        ptrToNode->Right->Parent = root_parent;
        ptrToNode->Right->Left = ptrToNode;
        ptrToNode->Parent = ptrToNode->Right;
        ptrToNode->Right = right_son_left_leaves;
        right_son_left_leaves->Parent = ptrToNode;
    } else {

    }
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

/**
 *
 * @tparam T
 * @param ptrToNode 加入的新leaf
 * @return 最近的需要调整的结点
 */
template<typename T>
typename AVLTree<T>::PtrToNode AVLTree<T>::insertOperatTo_bf(AVLTree::PtrToNode ptrToNode) {
    PtrToNode tmpOfParent = ptrToNode->Parent;
    if (tmpOfParent) {
        if (tmpOfParent->Left == ptrToNode)//操作节点为左叶子
        {
            tmpOfParent->bf--;
        } else {
            tmpOfParent->bf++;
        }
        cout << "插入的节点：" << tmpOfParent->t << "，平衡因子：" << tmpOfParent->bf << endl;
        if (tmpOfParent->bf == 0) {
            return nullptr;
        }

        insertOperatTo_bf(tmpOfParent);
    }
}

template<typename T>
void AVLTree<T>::test(T t) {
    singleRotateWithLeft(findtoPtr(t, root));

}

template<typename T>
void AVLTree<T>::insert(T t, PtrToNode ptrToNode) {
    if (t < ptrToNode->t) {
        if (ptrToNode->Left == nullptr) {
            auto *mpNode = new AVLNode(t);
            ptrToNode->Left = mpNode;
            mpNode->Parent = ptrToNode;
            insertOperatTo_bf(mpNode);
            cout << "根节点：" << root->t << "，平衡因子：" << root->bf << endl;
        } else {
            insert(t, ptrToNode->Left);
        }
    } else if (t > ptrToNode->t) {
        if (ptrToNode->Right == nullptr) {
            auto *mpNode = new AVLNode(t);
            ptrToNode->Right = mpNode;
            mpNode->Parent = ptrToNode;
            insertOperatTo_bf(mpNode);
            cout << "根的节点：" << root->t << "，平衡因子：" << root->bf << endl;
        } else {
            insert(t, ptrToNode->Right);
        }
    }
}


#endif //DATASTRUCTURESINCPP_AVLTREE_H

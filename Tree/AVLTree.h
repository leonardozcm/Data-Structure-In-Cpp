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

        explicit AVLNode(T myT);
    };

    typedef AVLNode *PtrToNode;
    typedef PtrToNode Tree;

    void insert(T t);

    void Delete(T t);

    void print();

    void singleRotateWithLeft(PtrToNode ptrToNode);

    void doubleRotateWithLeft_Right(PtrToNode ptrToNode);

    void singleRotateWithRight(PtrToNode ptrToNode);

    void doubleRotateWithRight_Left(PtrToNode ptrToNode);

private:
    int left = 0;
    int right = 1;

    Tree root = nullptr;

    void print(PtrToNode ptrToNode, int spacenum);

    void insert(T t, PtrToNode ptrToNode);

    PtrToNode findtoPtr(T t, PtrToNode ptrToNode);

    void space(int num);

    void clear(PtrToNode ptrToNode);

    void insertOperateTo_bf(PtrToNode ptrToNode);

    void deleteOperateTo_bf(PtrToNode ptrToNode, int dir);

    PtrToNode findMinToPtr(PtrToNode ptrToNode);

};

template<typename T>
AVLTree<T>::AVLNode::AVLNode(T myT) {
    bf = 0;
    t = myT;
    Left = Right = Parent = nullptr;
}

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
    PtrToNode tmp = findtoPtr(t, root);
    if (tmp != nullptr) {
        PtrToNode minInRight = findMinToPtr(tmp->Right);
        if (minInRight != nullptr) {
            tmp->t = minInRight->t;
            PtrToNode minParent = minInRight->Parent;
            if (minParent != nullptr) {
                minParent->Left = minInRight->Right;
            }
            deleteOperateTo_bf(minParent,left);
            delete minInRight;

        } else {
            PtrToNode tmpParent = findtoPtr(t, root)->Parent;
            if (t < tmpParent->t) {
                tmpParent->Left = tmp->Left;
                deleteOperateTo_bf(tmpParent,left);
            } else {
                tmpParent->Right = tmp->Left;
                deleteOperateTo_bf(tmpParent,right);
            }

        }
    }

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
        if (right_son_left_leaves != nullptr) {
            right_son_left_leaves->Parent = ptrToNode;
        }
    } else {
        root = ptrToNode->Right;
        ptrToNode->Right->Left = ptrToNode;
        ptrToNode->Right->Parent = nullptr;
        ptrToNode->Parent = ptrToNode->Right;
        ptrToNode->Right = right_son_left_leaves;
        if (right_son_left_leaves != nullptr) {
            right_son_left_leaves->Parent = ptrToNode;
        }
    }
    ptrToNode->bf = ptrToNode->Parent->bf = 0;

}

template<typename T>
void AVLTree<T>::doubleRotateWithLeft_Right(AVLTree::PtrToNode ptrToNode) {
    singleRotateWithLeft(ptrToNode->Left);
    singleRotateWithRight(ptrToNode);
}

template<typename T>
void AVLTree<T>::singleRotateWithRight(AVLTree::PtrToNode ptrToNode) {
    PtrToNode root_parent = ptrToNode->Parent;
    PtrToNode left_son_right_leaves = ptrToNode->Left->Right;
    if (root_parent != nullptr) {
        if (root_parent->Left == ptrToNode) {
            root_parent->Left = ptrToNode->Left;
        } else {
            root_parent->Right = ptrToNode->Left;
        }
        ptrToNode->Left->Parent = root_parent;
        ptrToNode->Left->Right = ptrToNode;
        ptrToNode->Parent = ptrToNode->Left;
        ptrToNode->Left = left_son_right_leaves;
        if (left_son_right_leaves != nullptr) {
            left_son_right_leaves->Parent = ptrToNode;
        }
    } else {
        root = ptrToNode->Left;
        ptrToNode->Left->Right = ptrToNode;
        ptrToNode->Left->Parent = nullptr;
        ptrToNode->Parent = ptrToNode->Left;
        ptrToNode->Left = left_son_right_leaves;
        if (left_son_right_leaves != nullptr) {
            left_son_right_leaves->Parent = ptrToNode;
        }
    }
    ptrToNode->bf = ptrToNode->Parent->bf = 0;

}

template<typename T>
void AVLTree<T>::doubleRotateWithRight_Left(AVLTree::PtrToNode ptrToNode) {
    singleRotateWithRight(ptrToNode->Right);
    singleRotateWithLeft(ptrToNode);
}

/**
 *
 * @tparam T
 * @param ptrToNode 加入的新leaf
 * @return 最近的需要调整的结点
 */
template<typename T>
void AVLTree<T>::insertOperateTo_bf(AVLTree::PtrToNode ptrToNode) {
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
            return;
        }
        if (tmpOfParent->bf == -2) {
            if (tmpOfParent->Left->bf == -1) {
                singleRotateWithRight(tmpOfParent);
            } else if (tmpOfParent->Left->bf == 1) {
                doubleRotateWithLeft_Right(tmpOfParent);
            }
        } else if (tmpOfParent->bf == 2) {
            if (tmpOfParent->Right->bf == 1) {
                singleRotateWithLeft(tmpOfParent);
            } else if (tmpOfParent->Right->bf == -1) {
                doubleRotateWithRight_Left(tmpOfParent);
            }
        } else {
            insertOperateTo_bf(tmpOfParent);
        }
    }
}

template<typename T>
void AVLTree<T>::deleteOperateTo_bf(AVLTree::PtrToNode ptrToNode, int dir) {
    if (dir == left) {
        ptrToNode->bf++;
    } else if (dir == right) {
        ptrToNode->bf--;
    }
    if (ptrToNode->bf == 0) {
        return;
    } else if (ptrToNode->bf == -2) {
        if (ptrToNode->Left->bf == -1) {
            singleRotateWithRight(ptrToNode);
        } else if (ptrToNode->Left->bf == 1) {
            doubleRotateWithLeft_Right(ptrToNode);
        }
    } else if (ptrToNode->bf == 2) {
        if (ptrToNode->Right->bf == 1) {
            singleRotateWithLeft(ptrToNode);
        } else if (ptrToNode->Right->bf == -1) {
            doubleRotateWithRight_Left(ptrToNode);
        }
    } else {
        if (ptrToNode->Parent) {
            if (ptrToNode->Parent->Right == ptrToNode) {
                deleteOperateTo_bf(ptrToNode->Parent, right);
            } else {
                deleteOperateTo_bf(ptrToNode->Parent, left);
            }
        }
    }
}


template<typename T>
void AVLTree<T>::insert(T t, PtrToNode ptrToNode) {
    if (t < ptrToNode->t) {
        if (ptrToNode->Left == nullptr) {
            auto *mpNode = new AVLNode(t);
            ptrToNode->Left = mpNode;
            mpNode->Parent = ptrToNode;
            insertOperateTo_bf(mpNode);
        } else {
            insert(t, ptrToNode->Left);
        }
    } else if (t > ptrToNode->t) {
        if (ptrToNode->Right == nullptr) {
            auto *mpNode = new AVLNode(t);
            ptrToNode->Right = mpNode;
            mpNode->Parent = ptrToNode;
            insertOperateTo_bf(mpNode);
        } else {
            insert(t, ptrToNode->Right);
        }
    }
}

template<typename T>
typename AVLTree<T>::PtrToNode AVLTree<T>::findMinToPtr(AVLTree::PtrToNode ptrToNode) {
    PtrToNode tmp = ptrToNode;
    if (tmp != nullptr) {
        while (tmp->Left) {
            tmp = tmp->Left;
        }
    }
    return tmp;
}


#endif //DATASTRUCTURESINCPP_AVLTREE_H

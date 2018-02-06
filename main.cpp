#include <iostream>
#include "Stack/stack.h"
#include "List/list.h"
#include "Tree/AVLTree.h"

using std::iostream;

bool isStringLegal(string str);

List<int> intersect(List<int> &list1, List<int> &list2);

int main() {
    AVLTree<int> tree;
    int a[] = {4,2,6,1,3,5,7,16,15,14,13};
    for (int i = 0; i < 11; ++i) {
        tree.insert(a[i]);
    }
    tree.insert(15);
    tree.print();
    return 0;
}

/**
 * 判断代码块是否有未闭合的括号
 * @param str
 * @return
 */
bool isStringLegal(string str) {
    string::iterator itstr = str.begin();
    Stack<char> stack;
    for (; itstr != str.end(); itstr++) {
        if (*itstr == '{' || *itstr == '[' || *itstr == '(') {
            stack.Push(*itstr);
        } else if (*itstr == '}') {

            if (stack.Top() != '{') {
                return false;
            } else {
                stack.Pop();
            }

        } else if (*itstr == ']') {

            if (stack.Top() != '[') {
                return false;
            } else {
                stack.Pop();
            }

        } else if (*itstr == '(') {

            if (stack.Top() != ')') {
                return false;
            } else {
                stack.Pop();
            }

        }
    }

    return stack.isEmpty();
};

/**
 * 对排好序的链表取交集
 * @param list1
 * @param list2
 * @return
 */
List<int> intersect(List<int> &list1, List<int> &list2) {
    List<int> result;
    List<int>::PtrToNode L1, L2;

    L1 = list1.FindByPos(0);
    L2 = list2.FindByPos(0);

    while (L1 != nullptr && L2 != nullptr) {
        if (L1->t < L2->t) {
            L1 = L1->next;
        } else if (L1->t > L2->t) {
            L2 = L2->next;
        } else {
            result.add(L1->t);
            L1 = L1->next;
            L2 = L2->next;
        }
    }
    cout << "intersect被调用完毕" << endl;
    return result;
};
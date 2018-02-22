#include <iostream>
#include "Stack/stack.h"
#include "List/list.h"
#include "HashMap/HashMap.h"
#include "HashMap/OaHashMap.h"
#include "Heap/Heap.h"

using std::iostream;

bool isStringLegal(string str);

List<int> intersect(List<int> &list1, List<int> &list2);

int main() {
    Heap<int> heap;
    heap.insert(13);
    heap.insert(14);
    heap.insert(16);
    heap.insert(19);
    heap.insert(21);
    heap.insert(19);
    heap.insert(68);
    heap.insert(65);
    heap.insert(26);
    heap.insert(32);
    heap.insert(31);
    heap.DeleteMin();
    heap.print();

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
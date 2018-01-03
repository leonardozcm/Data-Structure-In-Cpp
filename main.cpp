#include <iostream>
#include "Stack/stack.h"
#include "List/list.h"

using namespace std;

bool isStringLegal(string str);

List<int> intersect(List<int> list1, List<int> list2);

int main() {
    List<int> list1;
    list1.add(0);
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(5);
    List<int> list2;
    list2.add(2);
    list2.add(2);
    list2.add(5);
    List<int> result = intersect(list1, list2);
    result.Print();
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

List<int> intersect(List<int> list1, List<int> list2) {
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
    return result;
};
#include <iostream>
#include "Stack/stack.h"
#include "Queue/queue.h"
#include "List/list.h"
#include "List/doublelinklist.h"

using namespace std;

bool isStringLegal(string str);

int main() {
    DoubleLinkList<int> list;
    list.add(0);
    list.add(2);
    list.add(3);
    list.swapWithNext(0);
    list.Print();

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
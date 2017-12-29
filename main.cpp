#include <iostream>
#include "Stack/stack.h"
#include "Queue/queue.h"

using namespace std;

bool isStringLegal(string str);

int main() {
   Queue<int> queue;
    queue.enqueue(56);
    queue.enqueue(89);
    queue.enqueue(78);
    queue.dequeue();
    cout<<queue.getHead()<<endl;
    cout<<queue.getRear()<<endl;
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
#include <iostream>
#include "Stack/stack.h"

using namespace std;

int main() {
    Stack<int> stack;
    stack.Push(36);
    stack.Push(87);
    cout<<stack.Top()<<endl;
    return 0;
}
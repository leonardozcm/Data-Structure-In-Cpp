#include <iostream>
#include "Stack/stack.h"
using namespace std;

bool isStringLegal(string str);

int main() {
    string testcodes;
    cin>>testcodes;
    cout<<isStringLegal(testcodes)<<endl;
    return 0;
}
/**
 * 判断代码块是否有未闭合的括号
 * @param str
 * @return
 */
bool isStringLegal(string str){
    string::iterator itstr = str.begin();
    Stack<char> stack;
    for (;itstr != str.end();itstr++){
        if(*itstr == '{'||*itstr == '['||*itstr == '('){
            stack.Push(*itstr);
        } else if(*itstr == '}'){

            if(stack.Top() != '{'){
                return false;
            } else{
                stack.Pop();
            }

        }else if(*itstr == ']'){

            if(stack.Top() != '['){
                return false;
            } else{
                stack.Pop();
            }

        }else if(*itstr == '('){

            if(stack.Top() != ')'){
                return false;
            } else{
                stack.Pop();
            }

        }
    }

    return stack.isEmpty();
};
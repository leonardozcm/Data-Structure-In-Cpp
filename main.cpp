#include <iostream>
#include "List/list.h"
using namespace std;

int main() {
    List< int > list;
    cout<< list.Length()<<endl;
    list.Insert(987,0);
    list.Insert(866,1);
    list.add(45);
    list.Insert(67,3);
    cout<< list.Length()<<endl;
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
    cout << list.get(2)<<endl;
    return 0;
}
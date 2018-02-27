

#include "Heap/BinQueue.h"

int main() {
    BinQueue<int> binQueue1;
    binQueue1.insert(16);
    binQueue1.insert(18);
    binQueue1.insert(12);
    binQueue1.insert(51);
    binQueue1.insert(24);
    binQueue1.insert(65);
    cout << binQueue1.DeleteMin() << endl;

}




#include "Graph/Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph<int >::GraphNode graphNode(0, 1);
    cout << graphNode.weight << endl;
    return 0;
}

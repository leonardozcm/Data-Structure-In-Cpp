//
// Created by leonardo on 18-2-28.
//

#include "DisjSet.h"

DisjSet::DisjSet() {
    for (int i = 0; i < NumSet; ++i) {
        disjSet[i] = -1;
    }
}

void DisjSet::SetUnion(int Root1, int Root2) {
    if (disjSet[Root2] < disjSet[Root1])
        disjSet[Root1] = Root2;
    else {
        if (disjSet[Root1] == disjSet[Root2])
            disjSet[Root1]--;
        disjSet[Root2] = Root1;
    }


}

int DisjSet::Find(int X) {
    if(disjSet[X]<=0)
        return 0;
    else
        return Find(disjSet[X]);
}

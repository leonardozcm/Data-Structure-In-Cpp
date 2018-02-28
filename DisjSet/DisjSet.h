//
// Created by leonardo on 18-2-28.
//

#ifndef DATASTRUCTURESINCPP_DISJSET_H
#define DATASTRUCTURESINCPP_DISJSET_H

#define NumSet 10

class DisjSet {
public:
    void SetUnion(int Root1, int Root2);

    int Find(int X);

    DisjSet();

private:
    int disjSet[NumSet];

};


#endif //DATASTRUCTURESINCPP_DISJSET_H

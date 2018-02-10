//
// Created by leonardo on 18-2-9.
//

#ifndef DATASTRUCTURESINCPP_HASHMAP_H
#define DATASTRUCTURESINCPP_HASHMAP_H

#include <cstring>
#include "../List/list.h"
#include <exception>

#define MaxIndex 10
typedef unsigned int Index;

/*
 * Using separate chaining.
 */
template<typename T>
class HashMap {
public:
    void insert(const char *Key, T t);

    void Delete(const char *Key);

    T find(const char *Key);

    virtual ~HashMap();

private:
    List<pair<const char *, T>> indexList[MaxIndex];

    Index Hash(const char *Key);

    int findToPos(const char *Key);
};

template<typename T>
Index HashMap<T>::Hash(const char *Key) {
    unsigned int HashVal = 0;
    while (*Key != '\0')
        HashVal += (HashVal << 5) + *Key++;

    return HashVal % MaxIndex;

}

template<typename T>
HashMap<T>::~HashMap() {
    indexList->Clear();
}

template<typename T>
void HashMap<T>::insert(const char *Key, T t) {
    pair<const char *, T> pair(Key, t);
    indexList[Hash(Key)].add(pair);
}

template<typename T>
void HashMap<T>::Delete(const char *Key) {
    indexList[Hash(Key)].removeByPos(findToPos(Key));
}

template<typename T>
T HashMap<T>::find(const char *Key) {
    auto *ptrToNode = indexList[Hash(Key)].FindByPos(0);
    while (ptrToNode &&
            !strcmp(ptrToNode->t.first, Key)) {
        ptrToNode = ptrToNode->next;
    }
    if (ptrToNode) {
        return ptrToNode->t.second;
    }
}

template<typename T>
int HashMap<T>::findToPos(const char *Key) {
    auto list = indexList[Hash(Key)];
    auto *ptrToNode = list.FindByPos(0);
    int pos = 1;
    while (ptrToNode && !strcmp(ptrToNode->t.first, Key)) {
        ptrToNode = ptrToNode->next;
        pos++;
    }
    if (ptrToNode == nullptr) {
        return -1;
    } else {
        return pos;
    }
}


#endif //DATASTRUCTURESINCPP_HASHMAP_H

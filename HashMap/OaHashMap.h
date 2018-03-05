//
// Created by leonardo on 18-2-11.
//

#ifndef DATASTRUCTURESINCPP_OAHASHMAP_H
#define DATASTRUCTURESINCPP_OAHASHMAP_H

#define MaxIndex 10

#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned int Index;
enum KingOfEntry {
    Legitimate, Empty, Delete
};

/*
 * Using Open addressing hashing.
 */
template<typename T>
class OaHashMap {
public:
    OaHashMap();

    class Elment {
    public:
        std::pair<const char *, T> pair;
        enum KingOfEntry Info;

        Elment() {
            Info = Empty;
        }
    };

    void insert(const char *Key, T t);

    void Delete(const char *Key);

    T find(const char *Key);

private:
    Elment indexArray[MaxIndex];

    int findToIndex(const char *Key);

    Index Hash(const char *Key);
};

template<typename T>
void OaHashMap<T>::insert(const char *Key, T t) {
    int index = Hash(Key);
    int i = 0;
    Elment elment;
    elment.pair.first = Key;
    elment.pair.second = t;
    while (indexArray[index].Info != Empty) {
        index += 2 * ++i - 1;
        if (i >= MaxIndex / 2) {
            cout << "Half of storage is filled,Can't insert more." << endl;
            return;
        }
        if (index >= MaxIndex) {
            index -= MaxIndex;
        }
    }
    elment.Info = Legitimate;
    indexArray[index] = elment;
}

template<typename T>
void OaHashMap<T>::Delete(const char *Key) {
    int index = find(Key);
    indexArray[index].Info = (KingOfEntry) Delete;
}

template<typename T>
T OaHashMap<T>::find(const char *Key) {
    return indexArray[findToIndex(Key)].pair.second;
}

template<typename T>
Index OaHashMap<T>::Hash(const char *Key) {
    unsigned int HashVal = 0;
    int i = 1;
    while (*Key != '\0')
        HashVal += (HashVal << 5) + *Key++;
    return HashVal % MaxIndex;

}

template<typename T>
OaHashMap<T>::OaHashMap() {
    for (auto &i : indexArray) {
        Elment elment;
        i = elment;
    }
}

template<typename T>
int OaHashMap<T>::findToIndex(const char *Key) {
    int index = Hash(Key);
    int i = 0;
    while (indexArray[index].Info != Empty
           && strcmp(indexArray[index].pair.first, Key)) {
        index += 2 * ++i - 1;
        if (index >= MaxIndex) {
            index -= MaxIndex;
        }
    }
    return index;
}


#endif //DATASTRUCTURESINCPP_OAHASHMAP_H

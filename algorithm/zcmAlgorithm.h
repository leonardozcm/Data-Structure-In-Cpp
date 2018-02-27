//
// Created by leonardo on 18-2-27.
//

#ifndef DATASTRUCTURESINCPP_ZCMALGORITHM_H
#define DATASTRUCTURESINCPP_ZCMALGORITHM_H

#include "../List/list.h"

void Swap(int* a1,int* a2);

bool isStringLegal(string str);

List<int> intersect(List<int> &list1, List<int> &list2);

//插入排序
void InsertionSort(int A[], int N);

//希尔排序
void ShellSort(int A[], int N);

//堆排序
#define LeftChild(i) (2*(i)+1)

void PecDown(int A[], int i, int N);

void HeapSort(int A[], int N);

//快速排序
int Median3(int A[], int left, int right);

void Qsort(int A[], int left, int right);

void Quicksort(int A[], int N);
#endif //DATASTRUCTURESINCPP_ZCMALGORITHM_H

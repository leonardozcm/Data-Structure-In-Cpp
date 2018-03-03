//
// Created by leonardo on 18-2-27.
//

#include "zcmAlgorithm.h"
#include "../Stack/stack.h"

void Swap(int *a1, int *a2) {
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
};

bool isStringLegal(string str) {
    string::iterator itstr = str.begin();
    Stack<char> stack;
    for (; itstr != str.end(); itstr++) {
        if (*itstr == '{' || *itstr == '[' || *itstr == '(') {
            stack.Push(*itstr);
        } else if (*itstr == '}') {

            if (stack.Top() != '{') {
                return false;
            } else {
                stack.Pop();
            }

        } else if (*itstr == ']') {

            if (stack.Top() != '[') {
                return false;
            } else {
                stack.Pop();
            }

        } else if (*itstr == '(') {

            if (stack.Top() != ')') {
                return false;
            } else {
                stack.Pop();
            }

        }
    }

    return stack.isEmpty();
};

/**
 * 对排好序的链表取交集
 * @param list1
 * @param list2
 * @return
 */
List<int> intersect(List<int> &list1, List<int> &list2) {
    List<int> result;
    List<int>::PtrToNode L1, L2;

    L1 = list1.FindByPos(0);
    L2 = list2.FindByPos(0);

    while (L1 != nullptr && L2 != nullptr) {
        if (L1->t < L2->t) {
            L1 = L1->next;
        } else if (L1->t > L2->t) {
            L2 = L2->next;
        } else {
            result.add(L1->t);
            L1 = L1->next;
            L2 = L2->next;
        }
    }
    cout << "intersect被调用完毕" << endl;
    return result;
};

void InsertionSort(int A[], int N) {
    int j, p;
    int tmp;

    for (p = 0; p < N; p++) {
        tmp = A[p];
        for (j = p; j > 0 && A[j - 1] > tmp; j--) {
            A[j] = A[j - 1];
            A[j - 1] = tmp;
        }
    }
};

/*!*/
void ShellSort(int A[], int N) {
    int i, j, Increment, tmp;

    for (Increment = N / 2; Increment > 0; Increment /= 2)
        for (i = Increment; i < N; i++) {
            tmp = A[i];
            for (j = i; j > Increment - 1 && A[j - Increment] > tmp; j -= Increment) {
                if (tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else
                    break;
                A[j - Increment] = tmp;
            }
        }
};

void PecDown(int A[], int i, int N) {
    int Child;
    int tmp;

    for (tmp = A[i]; LeftChild(i) < N; i = Child) {
        Child = LeftChild(i);
        if (A[Child] < A[Child + 1])
            Child++;
        if (tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = tmp;
};

void HeapSort(int A[], int N) {
    int i;
    for (i = N / 2; i >= 0; i--) {
        PecDown(A, i, N - 1);
    }
    for (i = N - 1; i > 1; i--) {
        Swap(&A[0], &A[i]);
        PecDown(A, 0, i - 1);
    }
};

int Median3(int A[], int left, int right) {
    int Center = (left + right) / 2;

    if (A[left] > A[Center])
        Swap(&A[left], &A[Center]);
    if (A[left] > A[right])
        Swap(&A[left], &A[right]);
    if (A[Center] > A[right])
        Swap(&A[Center], &A[right]);
    ArrayPrint(A, 16);
    cout << endl << endl;
    Swap(&A[Center], &A[right - 1]);
    return A[right - 1];
};

#define cutoff 3

void Qsort(int A[], int left, int right) {
    int i, j;
    int Pivot;
    if (left + cutoff < right) {
        Pivot = Median3(A, left, right - 1);
        i = left - 1;
        j = right - 2;
        while (true) {
            while (A[++i] < Pivot) {};
            while (A[--j] > Pivot) {};
            if (i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[right - 2]);
        ArrayPrint(A, 16);
        cout << endl << endl;
        Qsort(A, left, i - 1);
        Qsort(A, i + 1, right);

    } else {
        InsertionSort(A + left, right - left );
    }

};

void Quicksort(int A[], int N) {
    Qsort(A, 0, N);
};

/*assuming all Elements less than M*/
void BucketSort(int A[], int N, int M) {
    auto *TmpArray = (int *) malloc(M * sizeof(int));
    int i, j;
    for (i = 0; i < N; ++i) {
        TmpArray[A[i]]++;
    }
    int pos = 0;
    for (i = 0; i < M; i++) {
        if (TmpArray[i])
            for (j = 0; j < TmpArray[i]; j++)
                A[pos++] = i;
    }
    free(TmpArray);
};

void MSort(int A[], int TmpArray[], int left, int right) {
    int Center;
    if (left < right) {
        Center = (left + right) / 2;
        MSort(A, TmpArray, left, Center);
        MSort(A, TmpArray, Center + 1, right);
        Merge(A, TmpArray, left, Center + 1, right);
    }
};

void MergeSort(int A[], int N) {
    auto *TmpArray = (int *) malloc(N * sizeof(int));
    if (!TmpArray) {
        MSort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    } else {
        cout << "out of space" << endl;
    }
};

void Merge(int A[], int TmpArray[], int left, int Center, int right) {
    int i, j, pos;
    i = left;
    j = Center;
    pos = left;
    while (i < Center && j <= right) {
        if (A[i] < A[j])
            TmpArray[pos++] = A[i++];
        else
            TmpArray[pos++] = A[j++];
    }
    if (i == Center) {
        i = j;
        j = right;
    } else if (j == right) {
        j = Center - 1;
    }

    for (; i <= j; i++) {
        TmpArray[pos++] = A[i];
    }
    for (i = left; i < right; i++) {
        A[i] = TmpArray[i];
    }
};

void ArrayPrint(int A[], int N) {
    int i = 0;
    for (; i < N; i++) {
        cout << A[i] << ',';
    }
}

void Test(){
    int A[] = {10, 5, 87, 14, 96, 63, 44, 15, 89, 15, 56, 12, 48, 6, 8, 7};
//    InsertionSort(A,16);
//    ShellSort(A,16);
//    BucketSort(A,16,100);
//    HeapSort(A,16);
//    Quicksort(A,16);
    ArrayPrint(A, 16);
};
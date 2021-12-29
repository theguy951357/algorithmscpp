//
// Created by cblah on 12/28/2021.
//

#include "Quicksort.h"

Quicksort::Quicksort() {

}

Quicksort::~Quicksort() {

}

int Quicksort::partition(int *A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r-1 ; ++j) {
        if(A[j]<=x){
            i=i+1;
            swap(A,i,j);
        }
    }
    swap(A,i+1,r);
    return i+1;
}

void Quicksort::swap(int *A, int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void Quicksort::quicksort(int *A, int p, int r) {
    int q = partition(A, p, r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);

}

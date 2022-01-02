//
// Created by cblah on 12/28/2021.
//

#include "Quicksort.h"

default_random_engine mt(time(nullptr));

Quicksort::Quicksort() = default;


Quicksort::~Quicksort() = default;

int Quicksort::partition(vector<int> *A, int p, int r) {
    int x = A->at(r);
    int i = p-1;
    for (int j = p; j < r ; ++j) {
        if(A->at(j)<=x){
            ++i;
            swap(A,i,j);
        }
    }
    swap(A, i+1,r);
    return i+1;
}

void Quicksort::swap(vector<int> *A, int a, int b) {
    int temp = A->at(a);
    A->at(a) = A->at(b);
    A->at(b) = temp;
}

void Quicksort::quicksort(vector<int> *A, int p, int r) {
    if(p<r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

void Quicksort::randomizedQuicksort(vector<int> *A, int p, int r){
    if(p<r) {
        uniform_int_distribution<int> dist(p,  r);
        int rando = dist(mt);
        swap(A, rando, r);
        int q = partition(A, p, r);
        randomizedQuicksort(A, p, q - 1);
        randomizedQuicksort(A, q + 1, r);
    }
}










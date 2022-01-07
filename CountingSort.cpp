//
// Created by cblah on 1/2/2022.
//

#include "CountingSort.h"

CountingSort::CountingSort() = default;

void CountingSort::countingSort(vector<int> A, vector<int> B, int k) {
    vector<int> C;
    C.reserve(k+1);
    for (int i = 0; i < C.size(); ++i) {
        C.push_back(0);
    }
    for (int i : A) {
        ++C.at(A.at(i));
    }
    for (int i = 1; i < C.size(); ++i) {
        C.at(i) = C.at(i)+C.at(i-1);
    }
    //decrementing each index in C by 1 to adjust for 0 indexing.
    for (int i = 1; i < C.size(); ++i) {
        --C.at(i);
    }
    for (int i = A.size()-1; i >= 0 ; --i) {
        B.at(C.at(A.at(i))) = A.at(i);
        --C.at(A.at(i));
    }
}



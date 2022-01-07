//
// Created by cblah on 1/2/2022.
//

#ifndef RAMMODEL_COUNTINGSORT_H
#define RAMMODEL_COUNTINGSORT_H
#include <vector>

using namespace std;

class CountingSort {

public:
    CountingSort();

private:

    void countingSort(vector<int> A, vector<int> B, int k);
};


#endif //RAMMODEL_COUNTINGSORT_H

//
// Created by cblah on 12/28/2021.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H
#include <vector>

using namespace std;
class Quicksort {
public:
    Quicksort();

    virtual ~Quicksort();

    void quicksort(vector<int> *A, int p, int r);

private:
    int partition(vector<int> *A, int p, int r);

    void swap(vector<int> *A, int a, int b);

    //vector<int> A;
};


#endif //QUICKSORT_QUICKSORT_H

//
// Created by cblah on 12/28/2021.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H


class Quicksort {
public:
    Quicksort();

    virtual ~Quicksort();

    void quicksort(int A[], int p, int r);

private:
    int partition(int A[], int p, int r);

    void swap(int A[], int a, int b);
};


#endif //QUICKSORT_QUICKSORT_H

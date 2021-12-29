//
// Created by cblah on 12/27/2021.
//

#ifndef HEAPSORT_HEAPSORT_H
#define HEAPSORT_HEAPSORT_H
#include <vector>

using namespace std;


class HeapSort {
public:
    explicit HeapSort(const vector<int>& heap);

    virtual ~HeapSort();

    void max_heapify(int i);

    void min_heapify(int i);

    void build_max_heap();

    void build_min_heap();

    void heapSort(bool ascending);

    int heap_maximum();

    int heap_minimum();

    int heap_extract_max();

    int heap_extract_min();

    void heap_increase_key(int i, int k);

    void heap_insert(int k);

    void print_heap();


private:
    vector<int> heap;

    vector<int>::iterator it;

    int heapsize;

    int leftChildOf(int index);

    int rightChildOf(int index);

    void swapper(int a, int b);

};


#endif //HEAPSORT_HEAPSORT_H

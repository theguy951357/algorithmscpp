//
// Created by cblah on 12/27/2021.
//

#include <iostream>
#include <bits/stdc++.h>
#include "HeapSort.h"

/**
 * The constructor will take in a vector as a parameter and set that parameter to an instance
 * variable vector. the size of the vector will alsobe set to a heapsize instance variable
 * since that size variable will change in certain methods
 * @param heap the vector that will be acted on
 */
HeapSort::HeapSort(const vector<int>& heap) : heap(heap) {
    this->heapsize = this->heap.size();
}
/**
 * default destructor
 */
HeapSort::~HeapSort() = default;
/**
 * max-heapify will find the largest int in the group and put it in the selected index(i).
 * @param i
 */
void HeapSort::max_heapify(int i) {
    int largest;
    int left = leftChildOf(i);
    int right = rightChildOf(i);
    left<this->heapsize&&heap.at(left)>heap.at(i) ? largest=left:largest=i;
    if(right<this->heapsize&&heap.at(right)>heap.at(largest)){
        largest=right;
    }
    if(largest!= i){
        swapper(i,largest);
        max_heapify(largest);
    }

}
/**
 * min heapify will do the same as max-heapify, but with the lowest number
 * @param i
 */
void HeapSort::min_heapify(int i) {
    int lowest;
    int left = leftChildOf(i);
    int right = rightChildOf(i);
    left<this->heapsize&&heap.at(left)<heap.at(i) ? lowest=left:lowest=i;
    if(right<this->heapsize&&heap.at(right)<heap.at(lowest)){
        lowest=right;
    }
    if(lowest!=i){
        swapper(i,lowest);
        min_heapify(lowest);
    }
}
/**
 * this is a print method for the heap.
 */
void HeapSort::print_heap() {
    cout<<"Heap= ";
    for(it=heap.begin(); it!=heap.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}
/**
 * build max heap will call max_heapify on the heap from halfway through down to the first index
 */
void HeapSort::build_max_heap() {
    for (int i = this->heapsize/2; i >=0 ; --i) {
        max_heapify(i);
    }
}
/**
 * build_min_heap will call min_heapify iteratively from halfway down to the first index
 */
void HeapSort::build_min_heap() {
    for (int i = this->heapsize/2; i >=0 ; --i) {
        min_heapify(i);
    }
}
/**
 * ascending will use max heap and descending will use min heap
 * @param ascending true is ascending, false if descending.
 */
void HeapSort::heapSort(bool ascending) {
    ascending? build_max_heap():build_min_heap();
    int backupCopy = this->heapsize;
    for(int i = this->heapsize-1; i>=1; --i){
        //swap(heap.at(0), heap.at(i));
        swapper(0,i);
        --this->heapsize;
        ascending? max_heapify(0): min_heapify(0);
    }
    this->heapsize = backupCopy;
}
/**
 * this is a helper method for swapping indexes in the heap.
 * @param a
 * @param b
 */
void HeapSort::swapper(int a, int b) {
    int temp = this->heap.at(a);
    this->heap.at(a) = this->heap.at(b);
    this->heap.at(b) = temp;
}
/**
 * this helper method finds the index that would represent the left child in a tree
 * @param index the index that will be used to find the left child.
 * @return returns the index that represents the left child in a tree.
 */
int HeapSort::leftChildOf(int index) {
    index>this->heap.size()?index=-1:
            index==0?index=1:
                    index+=index;
    return index;
}
/**
 * This method finds the index that would represent the right child in a tree.
 * @param index the index that will be used to find the right child.
 * @return returns the index that represents the right child in a tree.
 */
int HeapSort::rightChildOf(int index) {
    index>this->heap.size()?index=-1:
            index==0?index=2:
                    index+=index+1;
    return index;
}
/**
 * heap_maximum shows the maximum element in the heap
 * if heap is not maximized, the method will call build max heap first
 * @return returns the maximum element in the heap
 */
int HeapSort::heap_maximum() {
    if(this->heap.at(0)<this->heap.at(1)) {
        build_max_heap();
    }
    return this->heap.at(0);
}
/**
 * heap minimum shows the minimum element in the heap
 * if the heap is not sorted as minumum, the method will call build min heap
 * @return returns the minimum element in the heap
 */
int HeapSort::heap_minimum() {
    if(this->heap.at(0)>this->heap.at(1)) {
        build_min_heap();
    }
    return this->heap.at(0);
}

int HeapSort::heap_extract_max() {
    if(this->heapsize==0){
        return -1;
    }
    int max = heap_maximum();
    heap.erase(heap.begin());
    --this->heapsize;
    max_heapify(0);
    return max;
}

int HeapSort::heap_extract_min() {
    int min = heap_minimum();
    heap.erase(heap.begin());
    --this->heapsize;
    min_heapify(0);
    return min;
}
/**
 * heap_increase_key will take the given index and increase it to the given
 * key if the key is greater than the current key at the index
 * @param i the index to be increased
 * @param k the key that the index is to be increased to.
 */
void HeapSort::heap_increase_key(int i, int k) {
    if (k<heap.at(i)){
        cout<<"The new key needs to be greater than the current key at the chosen index. key was not increased."<<endl;
    }else{
        heap.at(i)=k;
        while(i!=0 && heap.at(i)>heap.at(i/2)){
            swapper(i,i/2);
            i/=2;
            max_heapify(i);
        }

    }

}
/**
 * heap_insert will insert the new key into the heap and increase the heapsize
 * @param k
 */
void HeapSort::heap_insert(int k) {
    ++this->heapsize;
    this->heap.insert(heap.end(),INT_MIN);
    heap_increase_key(heapsize-1,k);
}

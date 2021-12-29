#include <iostream>
#include <vector>
#include "HeapSort.h"

using namespace std;

int main() {
    int array[] = {10,3,9,2,8,1,7,4,6,5};

    vector<int> heap(array, array + sizeof(array) / sizeof(int));
    vector<int>::iterator it;
    auto *heapmin = new HeapSort(heap);
    heapmin->print_heap();
    heapmin->heapSort(false);
    heapmin->print_heap();
    heapmin->heapSort(true);
    heapmin->print_heap();
    cout<<"max= "<<heapmin->heap_maximum()<<endl;
    cout<<"min= "<<heapmin->heap_minimum()<<endl;
    cout<<"removed "<<heapmin->heap_extract_max()<<endl;
    heapmin->print_heap();
    cout<<"removed "<<heapmin->heap_extract_min()<<endl;
    heapmin->print_heap();
    heapmin->heap_increase_key(2,1);
    heapmin->heap_increase_key(6,200);
    heapmin->print_heap();
    heapmin->heap_insert(1);
    heapmin->heap_insert(1000);
    heapmin->heapSort(false);
    heapmin->print_heap();

    cout<<"heap in main=";
    for(it=heap.begin(); it!=heap.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;


    return 0;
}

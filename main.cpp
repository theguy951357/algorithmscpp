#include <iostream>
#include "Quicksort.h"

using namespace std;

int main() {
    int Array[] = {10,1,9,2,8,3,7,4,6,5};
    auto qs = new Quicksort();
    qs->quicksort(Array,0,9);
    for (int i : Array) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

#include <iostream>
#include "Quicksort.h"

using namespace std;

int main() {
    vector<int> Array = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    vector<int>::iterator it;
    auto qs = new Quicksort();
    qs->quicksort(&Array,0,Array.size()-1);
    for (it=Array.begin(); it!=Array.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}

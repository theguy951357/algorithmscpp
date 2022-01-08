#include <iostream>
#include "CountingSort.h"
int main() {
    vector<int> A = {1,0,2,9,3,8,4,7,5,6,76,53,99};
    vector<int> B;
    vector<int>::iterator it;
    B.reserve(A.size());
for (int i = 0; i < A.size(); ++i) {
        B.push_back(0);
    }
    auto cs = new CountingSort();
    cs->countingSort(&A,&B,100);
    for(it= B.begin(); it != B.end(); ++it) {
        cout << *it <<" ";
    }
    cout<<endl;


    return 0;
}

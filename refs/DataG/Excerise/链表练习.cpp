#include<iostream>
#include <vector>
//
//vecor的使用
using namespace std;


int main(){
    vector<int > vec;
    vector<int>::iterator it;
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i <= 4; i ++ ) {
        vec.push_back(a[i]);
    }
    int total = 0;
    for (it = vec.begin(); it != vec.end(); it ++ ) {
        total += *it;
    }
    cout<<total;
    return 0;
}

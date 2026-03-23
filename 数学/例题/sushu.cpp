#include <iostream>
using namespace std;
#include<cmath>
int main(){
    int n;
    cin >> n;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            cout <<"N" ;
            return 1;
        }
    }
    cout <<"Y";
    return 0;
}


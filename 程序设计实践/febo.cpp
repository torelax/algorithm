#include<iostream>
using namespace std;
int febo(int i){
	if(i==1||i==2)
		return 1;
	else return febo(i-1)+febo(i-2);
}
int main(){
	int a;
	cin>>a;
	cout<<febo(a);
}
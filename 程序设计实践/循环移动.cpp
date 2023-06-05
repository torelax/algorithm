#include<iostream>
using namespace std;
void move(int *arry, int n, int m){
	int b[n];
	for(int s=0;s<7;s++){
		b[s+3]=arry[s];
	}
	for(int s=0;s<m;s++){
		b[s]=arry[s+7];
	}
	for(int j=0;j<n;j++)
	cout<<b[j]<<" ";
}
int main(){
	int a[10];
	for(int i=0;i<10;i++)
	cin>>a[i];
	move(a,10,3);
	return 1;
}

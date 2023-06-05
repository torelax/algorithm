#include<iostream>
using namespace std;
#define max 1024
int main(){
	int a[max];
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j = k;ans<n;j++){
		if(ans != n-1 )
		cout<<a[j%n]<<" ";
		else
		cout<<a[j%n];
		ans++;
	}
	return 0;
} 

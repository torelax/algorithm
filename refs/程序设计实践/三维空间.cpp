#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	int m; 
	cin >> m;
	int a[100][100];
	for(int i = 0;i<n;i++){
		for(int j = 0;j < m;j++) {
			cin>>a[j][i];
		}		
	}
	int maxn[m];
	for(int i=0;i<m;i++){
		sort(a[i],a[i]+n);
		maxn[i]=a[i][n/2];
	}	
	int mm=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			mm+=abs(a[i][j]-maxn[i]);
		}
	}	
	cout<<mm;
}



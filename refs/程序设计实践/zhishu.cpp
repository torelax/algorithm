#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n=1;
	int re[100][100]={0};
	int a[100][100]={0};
	cin>>n;
	for(int i=1;i<n;i++){
		re[1][i]=i+1;
		re[i+1][i]=1;
		a[1][i+1]=1;
		for(int j=2;j<n;j++){
			for(int k=1;k<n+1;k++){
				if(k!=j&&a[j][k]==0 && (re[k][i]==j||re[k][i]==0)){
					re[j][i]=k;
					re[k][i]=j;
					a[j][k]=1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<"   ";
		for(int j=1;j<n;j++)
			cout<<re[i][j]<<"   ";
		cout<<endl;
	} 
}

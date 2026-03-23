#include<iostream>
#include<cstring> 
#include<string> 
using namespace std;
int m[20],num[20][10000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
		for(int j=0;j<m[i];j++){
			cin>>num[i][j];
		}
	}
	int flag[20][10000]={{0}};
	int f[20]={0};
	for(int i=0;i<n;i++){
		for(int j=1;j+1<m[i];j++){
			if(num[i][j-1]==1&&num[i][j+1]==1&&num[i][j]==0){
				flag[i][j]=1;
				f[i]=1;
			}				
		}
		if(f[i]==0){
			if(i==n-1)
			cout<<"wo hen kai xin!";
			else
			cout<<"wo hen kai xin!"<<endl;
		}		
		else {
			int sum=0;
			for(int j=1;j+1<m[i];j++){
			if(flag[i][j]==1){
				sum++;
				if(flag[i][j+2]==1)
				j+=2;
			}		
			}
			if(i==n-1)
			cout<<sum;
			else
			cout<<sum<<endl;
		}
	}
	
}


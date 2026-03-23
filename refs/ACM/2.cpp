#include<iostream>
#include<cstring> 
#include<stdio.h>
using namespace std;
int nex(char str[],int n);
int main(){
	int cas;
	cin>>cas;
	int len[cas],lim[cas];
	char str[cas][1000];
	for(int i=0;i<cas;i++) {
		scanf("%d%d",&len[i],lim[i]);
		gets(str[i]);
	}
	int m[cas];
	for(int i=0;i<cas;i++) {
		m[i]=strlen(str[i]);
	}	
	for(int j=0;j<cas;j++) {
		cout<<"Case #"<<j+1<<":"<<endl;
		cout<<m[j]<<endl;
		for(int k=0;k<m[j];){
			for(int i=0;i<lim[j];i++){
				if(str[j][k]!=' '){
					cout<<str[j][k];
					k++;
				}
				else {
					k++;
					if(i+nex(str[j],k)+1<lim[j])
					continue;
				//else
				//break;
				}
			}
		}
				
	}
}
int nex(char str[],int n){
	int sum=0;
	for(int i=0;i<20;i++){
		if(str[n+i] != ' ')
			sum++;
		else break;	
	}
	return sum;
}

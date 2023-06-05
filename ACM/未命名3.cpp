#include<iostream>
#include<cstring> 
#include<string> 
using namespace std;
int main(){
	int n;
	cin>>n;
	char a[10][100];
	char b[10][100];
	for(int m=0;m<n;m++) {
		gets(a[m]);
	}
	for(int j=0;j<n;j++){
		int k=0;
		for(int i=0;i<strlen(a[j]);i++,k++){
		if(a[j][i]=='&'){
			b[j][k]='\\';
		 	b[j][k+1]='\\';
		 	k++;
		}	 
		}
	}
	for(int j=0;j<n;j++){
		cout<<b[j];
		cout<<endl;	
	}

}

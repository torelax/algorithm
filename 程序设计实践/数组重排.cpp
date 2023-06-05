#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int a[10];
	//a=new int[100];
	//int size=0;
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	for(int i=0;i<10;i++){
		if(a[i]==0){
			for(int j=i;j<10;j++){
				if(a[j]!=0)
				{
					a[i]=a[j];
					a[j]=0;
					break;
				}
			}
	}
	}
	int m;
	for(m=0;m<10;m++){
		if(a[m]==0)
		break;
	}
	sort(a,a+m);
	for(int i=0;i<m;i++){
		cout<<a[m-i-1]<<" ";
	}
	for(int ab=m;ab<10;ab++){
		cout<<a[ab]<<" ";
	}
	cout<<endl<<m;
	
	
	
}

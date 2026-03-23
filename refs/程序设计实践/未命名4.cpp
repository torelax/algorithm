#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a[100];
	int i=0;
	while(1){
		char s;
		cin>>s;
		switch(s){
			case 'i':
			cin>>a[i];
			i++;
			break;
			case 'o':
			if(i<0)
			{
				cout<<"Can not pop empty stack";		
				return 0;
			}
			a[i]=0;
			i--;
			break;
			case 's':
			cout<<"( ";
			for(int j=0;j<i;j++){
				if(a[j]!=0&&j!=(i-1))
				cout<<a[j]<<" ";
				else if(a[j]!=0&&j==(i-1))
				cout<<a[j]<<" )"<<endl;
			}
			return 0;		
		}
	}
}

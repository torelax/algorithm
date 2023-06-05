#include <iostream> 
#include <string> 
#include <stack> 
using namespace std;  	
int main(){ 
	string s;
	cin>>s;
	int a[1000]={0}; 
	stack<int> q; 
	int num=s.size();
	int j=0,counts=0,max=0,flag=0; 
	for(int i=0;i<num;i++){ 
		if(s[i]=='('){ 
			j++; 
			flag=1; 
			q.push(j); 
		} 
		else{ 
			if(!q.empty()){ 
				a[q.top()]=1; 
				q.pop();
		  	} 
		 	else{ 
		 		if(flag==0) j++; 
			 } 
			flag=0; 
		}
	} 
	for(int i=1;i<=j+1;i++){ 
		if(a[i]==1) counts++; 
		else{ 
			if(counts>max) 
				max=counts; 
			counts=0; 
		} 
	} 
	cout<<max*2; 
}

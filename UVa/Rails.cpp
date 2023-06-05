#include<iostream>
#include<stack>
using namespace std;
const int Max = 1000 + 10;

int n, tar[Max];

int main(){
	while(scanf("%d",&n)==1){
		stack<int> s;
		int A=1, B=1;
		for(int i=1; i<=n;i++){
			scanf("%d",&tar[i]);
		}
		int ok=1;
		while(B<=n){
			if(A==tar[B]){A++; B++;}
			else if(!s.empty() && s.top()==tar[B]){s.pop();	B++;}
			else if(A<=n)	{s.push(A++);}
			else {	ok=0 ;	break;	}
		}
		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}
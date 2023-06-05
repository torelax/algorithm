#include <iostream>
#include <cstring>
using namespace std;
string s;
int len(int x){
	if(x<=0){
		return 0;
	}
	else if(s[x]=='(')
		return len(x-1);
	else if(s[x]==')'){
		if(s[x-1]=='(')
			return 2+len(x-2);
		else if(s[x-1]==')'){
			if(x-2-len(x-1)>=0&&s[x-1-len(x-1)]=='(')
				return 2+len(x-1)+len(x-2-len(x-1));
			else if(x-2-len(x-1)>=0)
				return len(x-1)+len(x-2-len(x-1));
		}
	}
	
		return 0;
}
int main(){	
	cin>>s; 
	int i;
	i=s.size();
	cout<<len(i-1);
}

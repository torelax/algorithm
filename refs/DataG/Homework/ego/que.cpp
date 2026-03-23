#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
	int n;
    string s;
	int i,j;
    queue<string>qn[3];
    for(i=0;i<10;i++){
        cin>>n>>s;
        qn[n].push(s);
    }
    for(i=0;i<10;i++){
        for(j=0;j<3;j++){
            if(!qn[j].empty()){
                cout<<qn[j].front();
                qn[j].pop();
            }
            else
            	cout<<"0";
                if(j!=2)
                	cout<<" ";
        }
        if(i!=9)	
			cout<<endl;
    }
    return 0;
}


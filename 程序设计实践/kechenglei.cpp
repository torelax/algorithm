#include<iostream>
#include<stdio.h>
using namespace std;
static int nu=0;
class cous{
	public:
		string name;
		int n;
		int xian;
		cous(){}
		int getx(){
			return xian;
		}
		void set(string str,int x){
			name=str;	xian=x;
		}
};

int main(){
	cous css[20];
	//int ab[20][20]={0};
	while(1){
		char s;
		cin>>s;
		if(s=='s'){
			for(int i=0;i<nu;i++){
				cout<<"Course "<<i<<"-"<<css[i].name<<" has prerequisites: ";
				int flag=i;
				
				if(css[i].xian<0)	
					cout<<"none"<<endl;
				else{
					for(int j=flag;j>=0;){
						cout<<css[css[j].xian].name<<" ";
						if(css[css[j].xian].xian>=0)
							j=css[j].xian;
						else break;
					}
					cout<<endl;		
				}
				
			}
		}
		else if(s=='e')	
			break;
		else if(s=='c'){
			string str;
			int x;
			cin>>str>>x;
			css[nu].set(str,x); 
			
			nu++;
		}
	}
		
} 


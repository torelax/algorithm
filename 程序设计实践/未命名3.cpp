#include<iostream>
#include<stdio.h>
using namespace std;
static int idn=0;
class stu{
	public:
		int x,y;
		string name;
		stu(){
		}
		int getx(){
			return x;
		}
		int gety(){
			return y;
		}
		void setxy(int xx,int yy){
			x=xx;	y=yy;
		}
		void get(string n){
			name=n;
		}
};

int main(){
	stu dent[20];
	while(1){
		char ss;
		cin>>ss;
		if(ss=='n'){
			string n;
			int xx,yy;
			cin>>n>>xx>>yy;
			dent[idn].get(n);
			dent[idn].setxy(xx,yy);
			idn++;
		}
		else if(ss=='m'){
			int n1,n2,n3;
			cin>>n1>>n2>>n3;
			dent[n1].setxy(n2,n3);
		}
		else if(ss=='s'){
			int x;
			cin>>x;
			cout<<"No. "<<x<<" creature "<<dent[x].name<<" is at ("<<dent[x].x<<", "<<dent[x].y<<")"<<endl;
		}
		else if(ss=='a'){
			for(int i=0;i<idn;i++){
				cout<<"No. "<<i<<" creature "<<dent[i].name<<" is at ("<<dent[i].x<<", "<<dent[i].y<<")"<<endl;
			}
		}

		else if(ss=='e')
		break;
	}
}

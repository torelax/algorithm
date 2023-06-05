#include<iostream>
#include<stdio.h>
using namespace std;
static int idn=0;
static int idn2=0;
class stu{
	public:
		int id;
		string name;
		stu(){
			for(int j=0;j<20;j++)
			major[j]=-1;
		}
		int major[20];
		void get(string n){
			name=n;
		}
};
class maj{
	public:
		int id2;
		string name2;
		maj(){
			for(int i=0;i<20;i++)
			student[i]=-1;
		}
		int student[20];
		void get2(string n){
			name2=n;
		}
};
int main(){
	stu dent[20];
	maj mu[20];
	while(1){
		char ss;
		cin>>ss;
		if(ss=='s'){
			string n;
			cin>>n;
			dent[idn].get(n);
			idn++;
		}
		else if(ss=='m'){
			string n;
			cin>>n;
			mu[idn2].get2(n);
			idn2++;
		}
		else if(ss=='a'){
			int id1,id2;
			cin>>id1>>id2;
			dent[id1].major[id2]=1;
			mu[id2].student[id1]=1;			
		}
		else if(ss=='d'){
			int id1,id2;
			cin>>id1>>id2;
			dent[id1].major[id2]=-1;
			mu[id2].student[id1]=-1;
		}
		else if(ss=='v'){
			int id1,id2,id3;
			cin>>id1>>id3>>id2;
			dent[id3].major[id1]=-1;
			dent[id3].major[id2]=1;
			mu[id1].student[id3]=-1;
			mu[id2].student[id3]=1;
		}
		else if(ss=='n'){
			for(int i=0;i<idn;i++){
				cout<<i<<"-"<<dent[i].name<<" ";
			}
			cout<<endl;
		}
		else if(ss=='l'){
			for(int i=0;i<idn2;i++){
				cout<<"Major "<<i<<"-"<<mu[i].name2<<": ";
				for(int j=0;j<20;j++){
					if(mu[i].student[j]==1)
					cout<<j<<"-"<<dent[j].name<<" ";
				}
				cout<<endl;
			}
		}
		else if(ss=='e')
		break;
	}
}

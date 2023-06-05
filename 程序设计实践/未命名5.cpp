#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int sum=0;
	int S=0;     //扫描仪类
	int P=0;     //打印机类
	int C=0;      //一体机类
	while(1){
		char s;
		cin>>s;
		switch(s){
		case 's':
		S++;
		sum++;
		printf("A new PoweredDevice is constructed.\n");
		printf("There are %d PoweredDevices in total.\n",sum);
		printf("A new Scanner is constructed.\n");
		printf("There are %d Scanner in total.\n",S+C);
		break;
		case 'p':
		P++;
		sum++;
		printf("A new PoweredDevice is constructed.\n");
		printf("There are %d PoweredDevices in total.\n",sum);
		printf("A new Printer is constructed.\n");
		printf("There are %d Printer in total.\n",P+C);
		break;
		case 'c':
		C++;
		sum++;
		printf("A new PoweredDevice is constructed.\n");
		printf("There are %d PoweredDevices in total.\n",sum);
		printf("A new Scanner is constructed.\n");
		printf("There are %d Scanner in total.\n",S+C);
		printf("A new Printer is constructed.\n");
		printf("There are %d Printer in total.\n",P+C);
		printf("A new Copier is constructed.\n");
		printf("There are %d Copiers in total.\n",C);
		break;
		case 'e':
			cout<<"The devices are: "<<endl;
			while(S>0){
				cout<<"Scanner"<<endl;
				S--; 
			}
			while(P>1){
				cout<<"Printer"<<endl;
				P--; 
			}
			while(C>0){
				cout<<"Copier"<<endl;
				C--; 
			}
			while(P>0){
				cout<<"Printer"<<endl;
				P--; 
			}
			return 0;
		}
	}
	
	
	
}




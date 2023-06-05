#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a[10]; //创建一个数组存放数据
	for(int i=0;i<10;i++)
	{
		cin>>a[i]; //输入数据 
	}
	int end=9;
	int start=0;
	int mid=(start+end)/2;	//划分子串 
	int find;
	cin>>find;
	while(a[mid]!=find){
		if(a[mid]>find)
			end=mid;
		else start=mid;
		mid=(start+end)/2; //更新mid和start、end的值，缩小成一个新的子串
	}
	cout<<"Find: "<<find<<"  At"<<mid+1;
}
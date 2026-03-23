#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int hav(int *max,int m);


void zhengli(int *max,int m);
void del(int *max,int m,int n,int &bh,string out[],int num[]);
int newf(int *max,int m,int n,int &bh,int num[]);

int main(){
	int T,M;
	cin>>T>>M;
	int Max[M];
	for(int i=0;i<M;i++){
		Max[i]=0;
	}
	int bh=1;
	int kk=0;
	static int num[100]={0};
	
	string out[20];
	int out2[20]={0};
	
	//int num=0;
	for(int i=0;i<T;i++){
		string s;
		int n=0;
		cin>>s;
		if(s=="new"||s=="del")
		cin>>n;
		num[bh]=n;
		if(s=="new"){
			if(hav(Max,M)>=n){
				kk++;
				num[bh]=n;
				newf(Max,M,n,bh,num);
				out2[bh]=kk;					
				bh++;
				
			}
			else{
				out[bh]="NULL";
				bh++;
				
			}
			
		}
		if(s=="def"){
			zhengli(Max,M);
		}
		if(s=="del"){
			del(Max,M,n,bh,out,num);
		}
		
	}
	for(int i=0;i<bh+1;i++)
	{
		if(out2[i]>0)
		{
		cout<<out2[i]<<endl;
		}
		else
		cout<<out[i]<<endl;
	} 
}

void zhengli(int *max,int m){
	for(int i=0;i<m;i++){
		
		if(max[i]==0){	\
			int flag=1;		
			for(int j=i;j<m;j++){
				if(max[j]==1){
					max[i]=1;
					max[j]=0;
					flag=0;
				}	
			}
			if(flag)	break;						
		}
	}
}


void del(int *max,int m,int n,int &bh,string out[],int num[]){
	int sum=0;
	for(int i=0;i<bh;i++){
		sum+=num[i];
	}
	int k=0;
	for(int i=0;i<n;i++){
		k+=num[n];
	}
	if(sum>m||n>bh){
		out[bh]="ILLEGAL_OPERATION";
		bh++;
	}
	else{
		for(int j=(k-num[n]);j<k;j++)
		max[j]=0;
	}
}

int newf(int *max,int m,int n,int &bh,int num[]){
	int *max2=max;
	int start=0;
	int j=0;
	int flag=0;
	int jj=0;
	for(jj=0;jj<m;jj++){
		if(flag)
		break;
		for(int i=jj;i<m;i++){
		if(max[i]==0){
			j++;
		}
		if(j==hav(max2,m))
		{
			start=jj;
			flag=1;
			break;
		}
		if(max[i]==1){
			j=0;
			break;
		}	
		}
		
	}
	for(int i=start;i<start+num[bh];i++){
		max[i]=1;
	}
	
	return 0;
}

int hav(int *max,int m)
{
	int j=0;
	int mix=0;
	for(int i=0;i<m;i++){
		if(max[i]==0){
			j++;
		}
		mix=mix>j?mix:j;
		if(max[i]==1){
			j=0;
		}	
	}
	return mix;	
	
}

#include<iostream>
#include<cstring> 
#include<string> 
using namespace std;
int T,n,k[10000],kk;
int main(){
	int dam=0;
	cin>>T;
	int di[T]={0};
	for(int i=0;i<T;i++) {
		cin>>n>>kk;
		for(int j=0;j<n;j++){
			k[j]=kk;
		}
		while(n>0){
			dam=2*n;
			if(dam>=kk){				
				n-=dam/kk;
				k[n-1]-=(dam%kk);
				di[i]++;
			}
			else {
				if((k[n-1]-dam%kk) > 0 ){
					k[n-1]-=(dam%kk);
					di[i]++;	
				}
					
				else if((k[n-1]-dam%kk) == 0 ){
					k[n-1]-=(dam%kk);
					n--;
					di[i]++;
				}
				else {
					n--;
					k[n-1]-=dam%kk;
					di[i]++;
				}
			}
		}
		
	}
	for(int i=0;i+1<T;i++){
		cout<<di[i]<<endl;
	}
	cout<<di[T-1];
}


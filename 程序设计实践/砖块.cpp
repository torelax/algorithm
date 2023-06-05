#include <iostream>
#include <cstring>
using namespace std;
int m,n;
int b[20][20];
int fin(int x,int y);
int main(){
	cin>>m>>n;
	char a[n][m];
	int i,k;
	for(i=0;i<n;i++){
		for(k=0;k<m;k++){
			cin>>a[i][k];
			b[i][k]=0;
		}
	}		
	for(int ii=0;ii<n;ii++){
		for(int kk=0;kk<m;kk++){
			if(a[ii][kk]=='@'||a[ii][kk]=='.'){
				b[ii][kk]=1;
		}
		}		
	}
	int max = 0;
	for(int p=0;p<n;p++){
		for(int q=0;q<m;q++){
			if(a[p][q] == '@'&& b[p][q]==1){
				int s=fin(p,q);
				max = max > s? max : s;
			}			
		}
	}
	cout<<max;
}
int fin(int x,int y){
	if(x<0||y<0||x>n-1||y>m-1)
		return 0;
	else if(b[x][y]==0)
		return 0;
	else if(b[x][y]==1){
		b[x][y]=0;
		return 1+fin(x,y+1)+fin(x+1,y)+fin(x,y-1)+fin(x-1,y);
	}
		
	else return 0;
}


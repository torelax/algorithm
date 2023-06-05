#include<iostream>
using namespace std;
enum direct {L,R,U,D};
int main(){
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	int i,j,flag=L;
	int k=n*n;
	i=j=n-1;
	while(k>0){
		for(;;){
		a[i][j]=k;
		k--;
		if(flag==L&& a[i][j-1]==0&&j>=1){
			j--;
			a[i][j]=k;
			if(a[i][j-1]>0||j==0)
			flag=U;
			break;
		}
		if(flag==U&&a[i-1][j]==0&&i>=1){
			i--;
			a[i][j]=k;
			if(a[i-1][j]>0||i==0)
			flag=R;
			break;
		}
		if(flag==R&&a[i][j+1]==0&&j<n-1){
			j++;
			a[i][j]=k;
			if(a[i][j+1]>0||j==n-1)
			flag=D;
			break;
		}
		if(flag==D&&a[i+1][j]==0&&i<n-1){
			i++;
			a[i][j]=k;
			if(a[i+1][j]>0||i==n-1)
			flag=L;
			break;
		}
		else 
			break;
	}	
	}
	int sum=0;
	for(int ii=0;ii<n;ii++){
		for(int jj=0;jj<n;jj++){
			cout<<a[ii][jj]<<" ";
		}
		sum=sum+a[ii][ii]+a[ii][n-ii-1];
		cout<<endl;
	}
	if(n%2!=0)
	sum-=a[n/2][n/2];
	cout<<sum;
}

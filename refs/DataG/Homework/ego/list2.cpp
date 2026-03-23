#include<iostream>
using namespace std;
struct list{
    int data[100];
    int last;
};
int main(){
    list a,b,c;
    a.last=-1;
    b.last=-1;
    c.last=-1;
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a.data[i];
        a.last++;
    }
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>b.data[j];
        b.last++;
    }
    int sa=0,sb=0,sc=0;
    for(int k=0;k<n;k++){
        for(int j=0;j<m;j++){
        	if(b.data[j]==a.data[k]){
        		c.data[c.last+1]=a.data[k];
        		c.last++;
			}
		}
    }
    if(c.last!=-1){
    	printf("%d\n",c.last+1);
    for(int i=0;i<c.last;i++){
        printf("%d ",c.data[i]);
    }
    cout<<c.data[c.last];
	}
    else cout<<0;
    return 0;
}

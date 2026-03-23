#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char a1[10001],b1[10001];
    int a[10001],b[10001],c[10001];
    int lena,lenb,i,j,x;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>a1;           
    cin>>b1;
    lena=strlen(a1);    
    lenb=strlen(b1);
    for (i=0;i<=lena-1;i++)     a[lena-i-1]=a1[i]-48;
    for (i=0;i<=lenb-1;i++)     b[lenb-i-1]=b1[i]-48; 
    j = lena > lenb ? lena : lenb;
    x=0;
    for(int n=0 ;n < j + 2  ; n ++ ){
        c[n]=a[n]+b[n]+x;
        x=c[n]/10;
        c[n]%=10;
    }
    if(c[j]==0) j--;
    for(int ii=j; ii>=0; ii--){
        cout<<c[ii];
    }
    return 0;
}

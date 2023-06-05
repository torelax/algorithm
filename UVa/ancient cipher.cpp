#include<iostream> 
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
int ch1[28],ch2[28];
int main(){
	char a1[110],a2[110];
	memset(ch1,0,sizeof(ch1));
	memset(ch2,0,sizeof(ch2));
	scanf("%s\n%s",&a1,&a2);
	for(int i=0;i<strlen(a1);i++)
	{
		ch1[a1[i]-'A']++;
	}
	for(int i=0;i<strlen(a2);i++)
	{
		ch2[a2[i]-'A']++;
	}
	sort(ch1,ch1+26);
	sort(ch2,ch2+26);
	int flag=1;
	for(int j=0;j<26;j++)
	{
		if(ch1[j]!=ch2[j])
		flag=0;
	}
	if(flag)
	cout<<"YES\n";
	else
	cout<<"NO\n";
	return 0;
	//古老的密码
}

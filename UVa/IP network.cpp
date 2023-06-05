#include<iostream>
using namespace std;
unsigned n,i,j,tp,mask=~0,ip=~0;//最后三个依次为临时ip,掩码,ip,初始为{1}
int main(){
	for(scanf("%u ",&n);n--;){
		tp=0;
		for(i=4;i--;){
			scanf("%u%*c",&j);
			tp|=j<<8*i;
		}
		ip&=tp;					//更新ip
		for(i=ip^tp;i;i>>=1)mask&=~i;//更新掩码
	}
	ip&=mask;			//修正ip
	for(j=2;j--;)
		for(i=4;i--;) printf("%d%c",((j?ip:mask)>>8*i)&255,i?'.':'\n');
}

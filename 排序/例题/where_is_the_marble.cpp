#include<iostream>
#include<algorithm>
#include<cstdio>
const int maxn=1000;
using namespace std;
int main(){
	int n,q,x,a[maxn],su=0;
	while(scanf("%d%d",&n,&q)==2&&n){
		printf("CASE# %d:\n",++su);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		while(q--){
			scanf("%d",&x);
			int p=lower_bound(a,a+n,x)-a;
			if(a[p]==x)
				printf("%d found at %d",x,p);
			else printf("%d not found\n",x);
		}
	}
	return 0;	
}

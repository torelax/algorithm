#include<stdio.h>
#include<stdlib.h>
//bug

typedef struct{
	char* num[12];
	int flag[12];
	int fron,last;
}quen,*dque;

int main(){
	int n,i;
	char s[11];
	dque one,two,zer;
	zer = (dque)malloc(sizeof(quen));
	zer->fron = 0;		
	zer->last = 0;
	for(i = 0;i < 3;i ++) {
		scanf("%d %s",&n,&s);
		zer->flag[zer->last] = n;
		zer->num[zer->last] = s;	
	
		printf("%s %d\n",zer->num[zer->last],zer->last);
		(zer->last)++;	
		printf("%s %d\n",zer->num[zer->fron],zer->fron);
		(zer->fron)++;
	}
	for(i = 0;i<3;i++) {
		printf("%s %d\n",zer->num[zer->fron],zer->fron);
		(zer->fron)++;
	}
	return 0;
}

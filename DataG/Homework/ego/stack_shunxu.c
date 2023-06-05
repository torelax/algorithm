#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct {
	int num[MAX];
	int top;
}stack,*qstack;

int push(qstack s,int n);
int pop(qstack s);

int main(){
	qstack s;
	s = (qstack)malloc(sizeof(stack));
	s->top = -1;
	int numb;
	scanf("%d",&numb);
	int a[MAX];
	int i;
	for(i = 0;i < numb;i++) {
		scanf("%d",&a[i]);
	}
	int next = 1;
	int flag = 1;
	push(s,0);
	for(i = 0;i < numb;i++) {
		//printf("%d",s->num[s->top]) ;
		if(s->num[s->top] > a[i]) {
			flag = 0;
			break;
		}
		else {
			while(s->num[s->top] < a[i]) {
				push(s,next);
				next++;
				//printf("push:%d  %d\n",s->num[s->top],s->top) ;
			}
			int x;
			x = pop(s);
			//printf("pop:%d  %d   %d\n",s->num[s->top],s->top,x) ;
		}
	}
	if(flag)	printf("YES");
	else		printf("NO");
	return 0;
}
int push(qstack s,int n) {
	if(s->top >= MAX-1)
		return -1;
	else {
		s->top++;
		s->num[s->top] = n;
		return 0;
	}
}

int pop(qstack s) {
	if(s->top == -1)
		return -1;
	else {
		s->top--;
		return s->num[s->top];
	}
		
}

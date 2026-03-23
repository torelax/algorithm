#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int date;
	struct node* next; 
}qnode,*nlist;

void dele(nlist h,int i);
int main(){
	nlist H,p,s;
	H = (nlist)malloc(sizeof(qnode));
	s = H;
	int n,m;
	scanf("%d%d",&n,&m);
	int a;
	int i;
	for(i = 0;i<n;i++) {
		p = (nlist)malloc(sizeof(qnode));
		p->date = i+1;	s->next = p;	s = p;
	}
	s->next = NULL;

	for(i = 0;i<m;i++) {
		scanf("%d",&a);
		dele(H,a);
	}
	/*
	nlist pm;
	pm = H->next;
	while(pm->next) {
		printf("%d",pm->date);
		pm = pm->next;
	}
	printf("%d\n",pm->date);
	*/
	int flg;
	flg = 1;
	nlist sm;
	sm = H->next;
	while(sm->next&&flg<(1+n-m)/2) {
		flg++;
		sm = sm->next;
	}
	printf("%d",sm->date);
	//free(H);
	return 0;
}
void dele(nlist h,int i) {
	int k=1;
	nlist p = h;
	while(p->next && k<i) {
		//printf("%d %d\n",p->date,k);
		p = p->next;
		k++;
	}
	if(p->next == NULL){
		p->next = NULL;
	}
	else{
		nlist q;
		q = p->next;	p->next = q->next;
	}
	
}

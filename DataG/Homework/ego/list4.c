#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node* prid;
	struct node* next;
	int data;
}nlist,*link;

int main(){
	link H,p,t,L;
	H = (link)malloc(sizeof(nlist));
	p = H;
	p->next = NULL;	p->prid = NULL;
	int n,i,a;
	scanf("%d",&n);
	for(i = 0;i<n-1;i++) {	
		scanf("%d",&a);
		p->data = a;
		L = p;
		t = (link)malloc(sizeof(nlist));
		p->next = t;
		p = t;
		p->prid = L; 
		//printf("%d",p->prid->data);
	}
	scanf("%d",&a);
	p->data = a;
	p->next = H;
	H->prid = p; 
	int kk;
	scanf("%d",&kk);
	link sm = H;
	for(i = 0;i<n;i++) {
		if(sm->data == kk) {
			for(i = 0;i < n-1;i ++) {
				printf("%d ",sm->data);
				sm = sm->prid;
			}
			printf("%d",sm->data);
			break;
		}
		sm = sm->next;
	}
	return 0;
}

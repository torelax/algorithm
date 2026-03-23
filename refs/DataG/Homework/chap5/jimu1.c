#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* right;
}Arry,*nArry;
nArry getposi(nArry s,int x);
int main() {
    //freopen("d1.txt","r",stdin);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    nArry s,h;
    s = (nArry)malloc(sizeof(Arry));
    s->right = NULL;
    s->next = NULL;
    h = s;
    for(i = 0;i < n;i++) {
        nArry p = (nArry)malloc(sizeof(Arry));
        p->data = i+1;
        p->right = NULL;
        h->next = p;
        h = p;
    }  
    h->next = NULL;
    int a,b;
    nArry l1,l2;
    for(i = 0;i < m;i++) {
        scanf("%d%d",&a,&b);
        if(a == b) {
            continue;
        }
        else {
            nArry l1 = s;
            nArry l2 = s;
            int q;
            for(q = 1;q <= a;q++) {
                l1 = l1->next;
            }
            for(q = 1;q <= b;q++) {
                l2 = l2->next;
            }
            // l1 = getposi(s,a);
            // l2 = getposi(s,b);
            if(l2->data == 0) {
                continue;
            }
            else {
                if(l1->data == 0) {
                    l1 = l2;  
                }
                else {
                    while(l1->right) {
                        l1 = l1->right;
                    }
                    l1->right = l2;
                }
                //l2->data = 0;
                //l2->right = NULL;
            }
        }
    }
    nArry k;
    k = s->next;
    for(i = 0;i < n;i++) {
        printf("%d ",k->data);
        if(k->right) {
            k = k->right;
        }
        else if(k->next){
            k = k->next;
            printf("\n");
        }
        else break;
    }
    system("pause");
    return 0;
}

nArry getposi(nArry s,int x) {
    nArry p = s;
    int q;
    for(q = 1;q <= x;q++) {
        p = p->next;
    }
    return p;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sta
{
    char c;
    struct sta* next;
}stack,*pstack;

int push(pstack *top,char *cs);
char pop(pstack *top);

int main(){
    pstack top = NULL;
    top = (pstack)malloc(sizeof(stack));
    top->next = NULL;
    char ch1[30],ch2[30];
    int i=0;
    char c;
    while(scanf("%c",&c) && c != '@') {
        push(&top,&c);
        ch1[i] = c;
        		//printf("%c   %d\n",ch1[i],i);
        i++;
    }
    		//printf("%s %d\n",ch1,strlen(ch1));
    i = 0;
    while(top->next != NULL) {
        ch2[i] = top->c;
        		//printf("%c   %d\n",top->c,i);
    	pop(&top);
    	i++;
    }
    free(top);
    		//printf("%s %d\n",ch2,strlen(ch2));
    if(!strncmp(ch2,ch1,i)) {
        printf("true");
    }
    else printf("false");
    system("pause");
    return 0;
}
int push(pstack *top,char *cs) {
    pstack p;
    p = (pstack)malloc(sizeof(stack));
    p->c = *cs;
    p->next = *top;
    *top = p;
}

char pop(pstack *top) {
    if(*top == NULL)
        return -1;
    else {
        pstack p = *top;
        *top = (*top)->next;
        free(p);
        return 0;
    }
}

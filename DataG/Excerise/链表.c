#include <stdio.h>
#include <stdlib.h>
typedef struct _list
{
    int value;
    struct _list *next;
    /* data */
}List;

int main(){
    List *head = NULL;
    List *p,*q;
    p = head;
    int a[] = {1,2,3,4,5,6,7,8};
    int i; 
    for(i = 0;i <= 7;i ++) {
        p = (List*)malloc(sizeof(List));
        p->value = a[i];
        printf("&p=%p\t p->value=%d \t",p,p->value);
        printf("&p->next=%p\n", p->next);
        q = p->next;
        p = q;
    }
    return 0;
}

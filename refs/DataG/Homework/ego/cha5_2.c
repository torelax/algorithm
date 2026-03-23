#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    struct queue *next;
    int data;
}Queue, *quelink;

typedef struct
{
    Queue *front, *last;
}Qnode;

void push();
void pos();

int main(){
    Qnode *s;
    s = (Qnode*)malloc(sizeof(Qnode));
    s->front = s->last = (quelink)malloc(sizeof(Queue));
    s->front->next = NULL;
    printf("а╢й╫╤сап");
    system("pause");
    return 0;
}

void push(Qnode *s, int x) {
    quelink p = (quelink)malloc(sizeof(Queue));
    p->data = x;
    p->next = NULL;
    s->last->next = p;
    s->last = p;
}

void pos(Qnode *s) {
    quelink q;
    q = s->front;
    s->front = q->next;
    free(q);
}

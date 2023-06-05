#include<stdio.h>
#include<stdlib.h>
#define Max 1024
//顺序队列
typedef struct
{
    int data[Max];
    int front,last;
}quene,*nque;

void Setempty(nque s);
int Getempty(nque s);
int push(nque s, int x);
int pop(nque s);
int main(){
    nque s;
    s = (nque)malloc(sizeof(quene));
    int i;
    Setempty(s);
    for(i = 0;i < 20;i++) {
        push(s,i);
    }
    for(i = 0;i < 9;i++) {
        pop(s);
    }
    for(i = s->front;i < s->last;i++) {
        printf("%d\n",s->data[i]);
    }
    system("pause");
    return 0;
}

void Setempty(nque s) {
    s->front = s->last = 0;
}

int Getempty(nque s) {
    return (s->front == s->last);
}

int push(nque s, int x) {
    if((s->last+1)%Max == s->front)
        return -1;
    s->data[s->last] = x;
    s->last = (s->last + 1)%Max; 
    return 0;
}

int pop(nque s) {
    s->front = s->front + 1;
}

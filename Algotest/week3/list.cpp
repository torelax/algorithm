#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct list
{
  int value;
  struct list* next;
}List;
int main() {
  List *A, *B, *p, *q, *t;
  A = (List*)malloc(sizeof(List));  p = A;
  B = (List*)malloc(sizeof(List));  q = B;
  for (int i = 0; i < 4; i++) {
    t = (List*)malloc(sizeof(List));
    t->value = i+1;
    p->next = t;
    p = t;
  }
  p->next = NULL;
  for (int i = 0; i < 2; i++) {
    t = (List*)malloc(sizeof(List));
    t->value = i+3;
    q->next = t;
    q = t;
  }
  q->next = NULL;
  List *head1 = A->next, *head2 = B->next;
  int sum1 = 0, sum2 = 0;
  while (head1) {
    sum1 = sum1 * 10 + head1->value;
    head1 = head1->next;
  }
  while (head2) {
    sum2 = sum2 * 10 + head2->value;
    head2 = head2->next;
  }
  int sum = sum1+sum2, i = 0;
  int ss[100] = {0};
  while (sum) {
    ss[i] = sum%10;
    sum = sum/10;
    i++;
  }
  List *C, *m;
  C = (List*)malloc(sizeof(List)); m = C;
  for (int k = i-1; k >= 0; k--) {
    t = (List*)malloc(sizeof(List));
    t->value = ss[k];
    m->next = t;
    m = t;
  }
  m->next = NULL;
  List *head = C->next;
  while (head) {
    cout <<head->value <<'\t';
    head = head->next;
  }
  return 0;
}
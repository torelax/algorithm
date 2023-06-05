#include<stdio.h>
#include<stdlib.h>
int tree[100][2] = {{10000}};
int i = 0;
void push(int l);
int main() {
  char a, b, c;
  int root;
  for(i = 0;i < 100;i++) {
    tree[i][0] = 200;
    tree[i][1] = 200;
  }
  i = 0;
  while(i < 130) {
    scanf(" %c%c%c",&a, &b, &c);
    if(a == '^' && b == '^') {
      break;
    }
    else if ( a == '^') {
      root = b-65;
    }
    else {
      if(c == 'L') {
        tree[a-65][0] = b-65;
      }
      else {
          tree[a-65][1] = b-65;
      }
    }
    i++;
  }
  //printf("%c", (char)(root+65));
  if(i >= 1)
  push(root);
  system("pause");
  return 0;
}
void push(int l) {
    if(l < 120) {
      if(tree[l][0] >= 128 && tree[l][1] >= 128) {
      printf("%c", (char)(l+65));
    }
    else {
      printf("%c(", (char)(l+65));
      push(tree[l][0]);
      if(tree[l][1] < 128) {
        printf(",");
      push(tree[l][1]);
      
      }
      printf(")");
    }
    }
    
}
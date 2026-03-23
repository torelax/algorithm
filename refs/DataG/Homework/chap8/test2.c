#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, target;
  int i, j;
  scanf("%d",&n);
  int num[n];
  for(i = 0; i < n; i++) {
    scanf("%d",&num[i]);
  }
  int flag = 0;
  scanf("%d",&target);
  for(i = 0;i < n; i++) {
    for(j = i+1; j < n; j++) {
      if(target == (num[i]+num[j])){
        flag = 1;
        break;
      }      
    }
    if(flag)  break;
  }
  printf("%d %d",i+1,j+1);
  return 0;
}
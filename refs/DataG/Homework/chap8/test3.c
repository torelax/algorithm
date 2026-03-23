#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int n, i, j;
  scanf("%d", &n);
  int a[n+1];
  bool b[1000001] = {false};
  for(i = 1; i <= n; i++) {
    scanf("%d",&a[i]);
  }
  for(i = 1; i <= n; i++ ) {
    if(a[i]>0 && a[i]<=1000001) {
      b[a[i]] = 1;
    }
  }
  for(j = 1; j <= n; j++) {
    if(b[j] == 0)
      break;
  }
  printf("%d", j);
  return 0;
}
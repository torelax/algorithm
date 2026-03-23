#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int n, m, a,b;
  scanf("%d%d",&n, &m);
  int nf[1001] = {0};
  bool guan[1001][1001] = {{false}};
  int i = 0;
  for(i;i < m;i++) {
    scanf("%d%d",&a, &b);
    if(!guan[a][b]) {
      guan[a][b] = true;
      nf[b]++;
      nf[a]--;
    }
  }

  for(i = 0;i < n-1;i++) {
    printf("%d\n",nf[i]);
  }
  printf("%d\n",nf[n-1]);
  return 0;
}
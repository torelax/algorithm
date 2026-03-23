#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n, m, C, i, j;
  int a[10001] = {0}, b[10001] = {0};
  int num[1001] = {30000};
  scanf("%d%d%d", &n, &m, &C);
  for (i = 1; i <= 1001;i++) {
    num[i] = 30000;
  }
  num[C] = 0;
  for (i = 1; i <= m; i++)
  {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (j = 1; j <= n+1;j++) {
    for (i = 1; i <= m+1; i++)
    {
      if (a[i] == C && b[i] != C)
      {
        num[b[i]] = 1;
      }
      else if (b[i] == C && a[i] != C)
      {
        num[a[i]] = 1;
      }
      else if (num[a[i]] > num[b[i]] + 1)
      {
        num[a[i]] = num[b[i]] + 1;
      }
      else if (num[b[i]] > num[a[i]] + 1)
      {
        num[b[i]] = num[a[i]] + 1;
      }
    }
  }
    
  for (i = 1; i < n; i++)
  {
    printf("%d\n", num[i]);
  }
  printf("%d",num[i]);
  return 0;
}

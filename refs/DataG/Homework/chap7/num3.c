#include <stdlib.h>
#include <stdio.h>

int a[100001], b[100001], t[100001];
int id[100001];

int unio(int a, int b, int m);
int find(int a);

int main()
{
  int n, m, i, k, num = 0, max = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++)
  {
    id[i] = i;
  }
  for (i = 1; i <= m; i++)
  {
    scanf("%d%d%d", &a[i], &b[i], &t[i]);
  }
  int t1, t2, t3, flag;
  for(k = 1; k <= m; k++) {
    flag = 1;
    for(i = k; i <= m-k; i++) {
      if(t[i+1] < t[i]) {
        t1 = a[i+1];  t2 = b[i+1];  t3 = t[i+1];
        a[i+1] = a[i];  b[i+1] = b[i];  t[i+1] = t[i];
        a[i] = t1;  b[i] = t2; t[i] = t3;
      }
    }
    if(flag) {
      break;
    }
  }
  for (i = 1; i <= m; i++)
  {
    if (find(a[i]) != find(b[i]))
    {
      max = max>t[i]?max:t[i];
      unio(a[i],b[i],m);
      num++;
    }
    if(num == n-1) {
      break;
    }
  }
  if(num == n-1){
    printf("%d",max);
  }
  else
  {
    printf("-1");
  }
  
  return 0;
}

int unio(int a, int b, int m)
{
  int p = id[a];
  int q = id[b];
  int j;
  if(p == q)  return 0;
  else {
    for(j = 1; j <= m; j++) {
      if(id[j] == p)   id[j] = q;
    }
  }
}
int find(int a)
{
  return id[a];
}
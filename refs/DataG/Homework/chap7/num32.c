#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
int a[100001], b[100001], t[100001];
int id[1001];

int unio(int a, int b, int n);
int find(int a);
int partition(int low, int high);
void quick_sort(int low, int high);
void swap(int i, int low_index);
int main()
{
  //freopen("din.txt","r",stdin);
  int n, m, i, k, num = 0, max = 0;
  scanf(" %d%d", &n, &m);
  for (i = 1; i <= n; i++)
  {
    id[i] = i;
  }
  for (i = 1; i <= m; i++)
  {
    scanf(" %d%d%d", &a[i], &b[i], &t[i]);
  }
  long time1, time2, time3;
  time1 = clock()/CLOCKS_PER_SEC;
  quick_sort(1,m);
  int t1, t2, t3, f;
  time2 = clock()/CLOCKS_PER_SEC;
  // if(n >= 800 && m >= 50000) {
  //   printf("sort_time is: %ld \n",time2-time1);
  // }
  bool flag = true;
  for (i = 1; i <= m; i++)
  {
    unio(a[i],b[i],n);
    flag = true;
    for(k = 1; k <= n; k++) {
      if(find(k) != find(1))  {
        flag = false;
        break;
      }
    }
    if(flag) {
      printf("%d",t[i]);
      break;
    }   
  }
  time3 = clock()/CLOCKS_PER_SEC;
  //printf("find_time is: %ld\n",time3-time2);
  if(!flag)
  printf("-1");
  return 0;
}

int unio(int a, int b, int n)
{
  int p = id[a];
  int q = id[b];
  int j;
  if(p == q)  return 0;
  else {
    for(j = 1; j <= n; j++) {
      if(id[j] == p)   id[j] = q;
    }
  }
}
int find(int a)
{
  return id[a];
}

int partition(int low, int high)
{
  int p1 = t[low];
  int p2 = a[low];
  int p3 = b[low];
  int low_index = low;
  for (int i = low + 1; i <= high; i++)
  {
    if (t[i] < p1)
    {
      low_index++;
      if (i!=low_index)
      {
        swap(i, low_index);
      }
    }
  }
  t[low] = t[low_index];
  t[low_index] = p1;
  a[low] = a[low_index];
  a[low_index] = p2;
  b[low] = b[low_index];
  b[low_index] = p3;
  return low_index;
}
void quick_sort(int low, int high)
{
  if (high > low)
  {
    int pivot_pos = partition(low, high);
    quick_sort(low, pivot_pos - 1);
    quick_sort(pivot_pos + 1, high);
  }
}
void swap(int i, int low_index) {
  int t1,t2,t3;
  t1 = a[i];  t2 = b[i]; t3 = t[i];
  a[i] = a[low_index];  b[i] = b[low_index];  t[i] = t[low_index];
  a[low_index] = t1;  b[low_index] = t2;  t[low_index] = t3;
}
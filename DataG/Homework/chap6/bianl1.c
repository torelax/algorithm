#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[50], b[50];

void prinh(int m,int n, int len);
int main() {
  
  scanf("%s%s", &a, &b);
  int l1;
  l1 = strlen(a);
  prinh(0,0,l1);
  //printf("\n%c%d", a[0], l1);
  int j;
  printf("\n");
  for(j = l1-1;j >=0 ;j--) {
    printf("%c", a[j]);
  }
  //system("pause");
  return 0;
}

void prinh(int m,int n, int len) {
  if(len <= 0) {
    return ;
  }
  else if (len == 1)
  {
    printf("%c", a[m]);
    return ;
  }
  int i = 0;
  while(a[m] != b[n+i]) {
    i++;
  }
  prinh(m+1,n,i);
  prinh(m+i+1,n+i+1,len-i-1);
  printf("%c", a[m]);
}
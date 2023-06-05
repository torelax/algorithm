#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char a[], int n);
int search(char a[], int *p, int n);
int ha[100001];
char s[100001][100] = {{0}};
int insert(char a[], int n);

int main() {
  int N, i, j;
  scanf("%d", &N);
  char a[100];
  for(i = 0; i < N; i++) {
    scanf("%s",a);
    for(j = 0;j < strlen(a); j++) {
      if(a[j] >= 'a')
       a[j] -= ' ';
    }
    ha[i] = insert(a, N);
    //memset(a,'\0',sizeof(a));
  }
  // for(i = 0; i < N; i++) {
  //   //scanf(" %s",a[i]);
  //   for(j = 0;j < strlen(a[i]); j++) {
  //     if(a[i][j] >= 'a')
  //      a[i][j] -= ' ';
  //   }
  //   ha[i] = insert(a[i], N);
  //   //memset(a,'\0',sizeof(a));
  // }
  for(i = 0;i < N-1;i++) {
    if(ha[i])
      printf("Yes\n");
    else
      printf("No\n");
  }
  if(ha[N-1]) {
    printf("Yes");
  }
  else {
    printf("No");
  }
}

int hash(char a[], int n) {
  int i;
  int key = 0;
  for(i = 0; i < strlen(a); i++) {
    if(a[i]>='a') {
      key = (key*256 + (int)(a[i]-97) + 128) % n;
    }
    else {
      key = (key*256 + (int)(a[i]-65) + 128) % n;
    }
  }
  return key;
}

int search(char a[], int *p, int n) {
  char m[100];
  int q = 0;
  *p = hash(a, n);
  while(strncmp(s[*p], a, strlen(a)) != 0 && strlen(s[*p]) >= 1) {
    q++;
    if(q < n) {
      *p = (*p+1) % n;
    }
    else {
      return 0;
    }
  }
  if(strncmp(s[*p], a, strlen(a)) == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

int insert(char a[], int n) {
  int tt = 0;
  int *p = &tt, i;
  if(search(a, p, n)) {
    return 1;
  }
  else {
    for(i = 0; i < strlen(a); i++) {
      s[*p][i] = a[i];
    }
    return 0;
  }
}
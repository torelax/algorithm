#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char a[100]);
int ha[100000];

int main() {
  int N, i, j;
  scanf("%d", &N);
  char a[N][100];
  char temp[100];
  for(i = 0; i < N; i++) {
    scanf(" %s",a[i]);
    for(j = 0;j < strlen(a[i]); j++) {
      if(a[i][j] >= 97)
        a[i][j] -= 32;
    }
    //printf("%s",a[i]);
  }
  for(i = 0;i < N;i++) {
    for(j = 0; j < i; j++) {
      //if(strlen(a[i]) - strlen(a[j]) <= 1){
        if(strncmp( a[i], a[j], strlen(a[i]) ) == 0) {
        if(i != N-1)
        {
          printf("Yes\n");
        }
        else
        {
          printf("Yes");
        }
        break;
      }
    }
      
    
    if(i != N-1 && j == i)
    {
      printf("No\n");
    }
    else if (j == i)
    {
      printf("No");
    }
  }
}


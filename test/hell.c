#include "stdio.h"
#include "string.h"

int fab(int n) {
    static int m = 1;
    m = m*n;
    return m;
}

void main() {
    char a[9] = "sfdgsdfas";
    char s[5] = "aaa";
    strcpy(a, s);
    printf("%c", s[4]);
    // printf(x/y);
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     printf("%d\n", fab(i+1));
    // }
    return ;
}


// char * strcpy(char *dst,const char *src)   
// {
//     if((dst==NULL)||(src==NULL))
         
//            return NULL; 
 
//     char *ret = dst; //[1]
 
//     while ((*dst++=*src++)!='\0'); //[2]
 
//     return ret;//[3]
// }
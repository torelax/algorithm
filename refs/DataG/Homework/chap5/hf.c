#include<stdio.h>
#include<stdlib.h>
#define Max 100000
//ª√∑Ωæÿ’Û≥¨ ±
void tran(int **a, int x, int y, int z,int n, int m);
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i, j;
    int **a;
    a = (int **)malloc(sizeof(int *)*n);
    for(i = 0;i < n;i++) {
        a[i] = (int *)malloc(sizeof(int)*m);
    }
    for(i = 0;i < n;i++) {
        for(j = 0;j < m;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int op,x,y,z;
    scanf("%d",&op);
    for(i = 0;i < op;i++) {
        scanf("%d%d%d",&x, &y, &z);
        tran(a,x,y,z,n,m);
    }
    for(i = 0;i < n;i++) {
        for(j = 0;j < m;j++) {
            printf("%d",a[i][j]);
            if(j != m-1)
                printf(" ");
        }
        if(i != n-1)
            printf("\n");
    }
    //system("pause");
    return 0;
}

void tran(int **a, int x, int y, int z, int n, int m) {
    if(x == 0) {
        int t,s;
        for(s = 0;s < m;s++) {
            //printf("%d %d\n",a[s][y],a[s][z]);
            t = a[y-1][s];
            a[y-1][s] = a[z-1][s];
            a[z-1][s] = t;
        }
    }
    else if(x == 1) {
        int f,s;
        for(s = 0;s < n;s++) {
            //printf("%d %d\n",a[s][y],a[s][z]);
            f = a[s][y-1];
            a[s][y-1] = a[s][z-1];
            a[s][z-1] = f;
        }
    }
}
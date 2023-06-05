#include<stdlib.h>
#include<stdio.h>
int main() {
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    int a[n*m];
    int r[n],c[m];
    for(i = 0;i < n;i++) {
        r[i] = i;
    }
    for(i = 0;i < m;i++) {
        c[i] = i;
    }
    for(i = 0;i < n*m;i++) {
        scanf("%d",&a[i]);
    }
    int op,x,y,z,k;
    scanf("%d",&op);
    for(j = 0;j < op;j++) {
        scanf("%d%d%d",&x,&y,&z);
        if(x == 0) {
            k = r[y-1];
            r[y-1] = r[z-1];
            r[z-1] = k;
        }
        else if(x == 1) {
            k = c[z-1];
            c[z-1] = c[y-1];
            c[y-1] = k;
        }
    }
    for(i = 0;i < n;i++) {
        for(j = 0;j < m;j++) {
            printf("%d",a[r[i]*m+c[j]]);
            if(j!=m-1)
                printf(" ");
        }
        if(i!=n-1)
            printf("\n");
    }
    system("pause");
    return 0;
}

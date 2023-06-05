#include<stdlib.h>
#include<stdio.h>
void tran(int a[],int x,int y,int z,int n,int m);
int main() {
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    int a[n*m];
    for(i = 0;i < n*m;i++) {
        scanf("%d",&a[i]);
    }
    int op,x,y,z;
    scanf("%d",&op);
    for(j = 0;j < op;j++) {
        scanf("%d%d%d",&x,&y,&z);
        tran(a,x,y,z,n,m);
    }
    for(i = 0;i < n;i++) {
        for(j = 0;j < m;j++) {
            printf("%d",a[i*m+j]);
            if(j!=m-1)
                printf(" ");
        }
        if(i!=n-1)
            printf("\n");
    }
    system("pause");
    return 0;
}

void tran(int a[],int x,int y,int z,int n,int m) {
    int y1 = y-1,z1 = z-1;
    int r,c,t;
    if(x == 0) {
        for(r = 0;r < m;r++) {
            t = a[y1*m+r];
            a[y1*m+r] = a[z1*m+r];
            a[z1*m+r] = t;
        }
    }
    else if(x == 1) {
        for(c = 0;c < n;c++) {
            t = a[c*m+y1];
            a[c*m+y1] = a[c*m+z1];
            a[c*m+z1] = t;
        }
    }
    else ;
}
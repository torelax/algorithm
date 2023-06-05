#include<stdio.h>
#include<stdlib.h>

int main() {
    freopen("d2.txt","r",stdin);
    int n,m,i,j,a,b;
    scanf("%d%d",&n,&m);
    //printf("%d",n);
    int next[n+1],f[n+1];
    for(i = 1;i <= n; i++) {
        next[i] = 0;
        f[i] = 1;
    }
    for(i = 0;i < m; i++) {
        
        scanf("%d%d",&a,&b);
        printf("%d%d\n",a,b);
        int s = a;
        if(a == b || f[b] == 0) {
            continue;
        }   
        else { 
                 
            if(f[a] == 0) {
                f[a] = 1;  
                next[a] = b;
                f[b] = 0;
            }
            else {
                while(next[s]) {
                    s = next[s];
                }
                next[s] = b;
                f[b] = 0;
            }
        }
    }
    int k = 1;
    for(i = 1;i <= n;i++) {
        if(f[i] == 0) {
            k = i + 1;
            //printf("\n");
            continue;
        }   
        else {
            printf("%d ",k);
            while(next[k]) {
                printf("%d ",next[k]);
                k = next[k];
            }
            printf("\n");
        }
    }
    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}
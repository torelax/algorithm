#include <iostream>
#include <queue>
//#include <fstream>
using namespace std;
int main()
{
    //freopen("d3.txt","r",stdin);
    int n,m,a,b;
    cin >> n >> m;
    //cout<<n<<" "<<m<<endl;
    queue<int> que[10001];
    for(int i = 1; i <= n; i++) {
        que[i].push(i); 
    }            
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        //cout<<a<<" "<<b<<endl;
        if(a == b) {
            continue;
        }   
        int l = que[b].size();           
        for(int i = 0; i < l; i++) {
            int num = que[b].front();
            que[b].pop();
            que[a].push(num);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!que[i].empty()) {
            cout << que[i].front();
            que[i].pop();
        }
        while(!que[i].empty()) {
            cout << " " << que[i].front();
            que[i].pop();
        }
        cout << endl;
    
    }
    //system("pause");
    return 0;
}
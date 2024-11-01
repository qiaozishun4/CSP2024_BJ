#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long cnt = 0;
int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};
int n,m,k;
bool vis[1005][1005];
char c[1005][1005];
bool f(int x,int y){
    return 1<=x &&x<=n && 1<=y && y<=m;//
}

void dfs(int x,int y,int d,int k){
    //cout << x <<" " <<y <<"  " <<  vis[x][y] <<endl;

    if (!vis[x][y]){
        cnt++;
    }
    if (k<=0)return;
    vis[x][y] = 1;
    int dx = fx[d]+x;
    int dy = fy[d]+y;
    if (f(dx,dy)&&c[dx][dy]=='.'){
        dfs(dx,dy,d,k-1);
    }
    else{
        dfs(x,y,(d+1)%4,k-1);
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >>t;
    while (t--){
        cnt = 0;
        memset(c,sizeof(c),0);
        cin >>n >>m >>k;
        int x,y,d;
        cin >> x >>y >>d;
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=m;j++){
                cin >>c[i][j];
            }

        }
        memset(vis,sizeof(vis),0);
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=m;j++){
                vis[i][j] = 0;
            }
        }
        dfs(x,y,d,k);
        cout << cnt <<endl;
    }

    return 0;
}

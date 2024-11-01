#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

char c[N][N];
bool f[N][N];
int T;
int n, m, k;
int x_0, y_0, d_0;
int ans;

int fx(int x, int d){
    if(d==1) return x + 1;
    if(d==3) return x - 1;
    return x;
}

int fy(int y, int d){
    if(d==0) return y + 1;
    if(d==2) return y - 1;
    return y;
}

void dfs(int x, int y, int d){
    int td = d;
    int tx = fx(x, td);
    int ty = fy(y, td);
    if(tx>=1 && tx<=n && ty>=1 && ty<=m && c[tx][ty]=='.'){
        f[tx][ty] = true;
        k--;
        if(!k) return;
        dfs(tx, ty, td);
        return;
    }
    for(int i=d+1; i<=d+3; i++){
        k--;
        if(!k) return;
        td = i % 4;
        tx = fx(x, td);
        ty = fy(y, td);
        if(tx>=1 && tx<=n && ty>=1 && ty<=m && c[tx][ty]=='.'){
            f[tx][ty] = true;
            k--;
            if(!k) return;
            dfs(tx, ty, td);
            return;
        }
    }
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &x_0, &y_0, &d_0);
        for(int i=1; i<=n; i++){
            cin.get();
            for(int j=1; j<=m; j++){
                scanf("%c", &c[i][j]);
            }
        }
        memset(f, 0, sizeof(f));
        f[x_0][y_0] = true;
        dfs(x_0, y_0, d_0);
        ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(f[i][j]){
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

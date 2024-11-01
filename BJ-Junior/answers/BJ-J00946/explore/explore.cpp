#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'

const int MAXN = 1e3 + 10;
bool vis[MAXN][MAXN];
int n,m,t,x,y,d,k;
char a[MAXN][MAXN];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool check(int x,int y){
    return x > 0 && x <= n && y > 0 && y <= m && a[x][y] == '.';
}

int main(){
    ios::sync_with_stdio(false);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j) cin >> a[i][j];
        for(int i = 1;i <= k;++i){
            vis[x][y] = 1;
            int tx = x + dx[d],ty = y + dy[d];
            if(!check(tx,ty)) d = (d + 1) % 4;
            else x = tx,y = ty;
        }
        vis[x][y] = 1;
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j) cnt += vis[i][j];
        cout << cnt << endl;
    }
    return 0;
}

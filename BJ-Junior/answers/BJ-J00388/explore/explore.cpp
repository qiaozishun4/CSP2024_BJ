#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m,k,dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
bool vis[1005][1005];
char a[1005][1005];
main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--){
        memset(vis,0,sizeof(vis));
        int x,y,d,cnt = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) cin >> a[i][j];
        vis[x][y] = true;
        while (k--){
            int nx = x + dx[d],ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.'){
                vis[nx][ny] = true;
                x = nx;
                y = ny;
            }else d = (d + 1) % 4;
        }
        for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) if (vis[i][j]) cnt++;
        cout << cnt << "\n";
    }
    return 0;
}
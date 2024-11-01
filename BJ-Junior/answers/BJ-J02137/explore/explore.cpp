/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, ans;
char a[1005][1005];
bool vis[1005][1005];
bool check(int x, int y) {
    if(a[x][y]=='x')
        return false;
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--) {
        memset(vis, false, sizeof(vis));
        ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++)
                cin >> a[i][j];
        }
        ans = 0;
        while(k--) {
            if(vis[x][y]==false) {
                vis[x][y] = true;
                ans++;
            }
            int tx = x, ty = y;
            if(d==0)
                ty++;
            else if(d==1)
                tx++;
            else if(d==2)
                ty--;
            else
                tx--;
            if(check(tx, ty)) {
                x = tx;
                y = ty;
            }
            else
                d = (d+1)%4;
        }
        if(vis[x][y]==false)
            ans++;
        cout << ans << '\n';
    }
    return 0;
}

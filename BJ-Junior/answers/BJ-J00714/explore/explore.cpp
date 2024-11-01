#include <bits/stdc++.h>
using namespace std;
int n, m, k, T, x, y, d, xp, yp;
int ans;
char a[1005][1005];
bool vis[1005][1005];
void exed(int &xp, int &yp) {
    switch(d) {
        case 0: xp=x, yp=y+1; break;
        case 1: xp=x+1, yp=y; break;
        case 2: xp=x, yp=y-1; break;
        case 3: xp=x-1, yp=y; break;
    }
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--) {
        ans = 1;
        memset(vis, 0, sizeof vis);
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        d %= 4;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cin >> a[i][j];
            }
        }
        vis[x][y] = 1;
        while(k--) {
            exed(xp, yp);
            if(1<=xp&&xp<=n&&1<=yp&&yp<=m) {
                    if(a[xp][yp] == '.') {
                        x=xp, y=yp;
                        // cout << x << " " << y << endl;
                        if(!vis[x][y])vis[x][y]=true, ans++;
                    }
                    else d = (d+1) % 4;

            }
            else d = (d+1) % 4;

        }
        cout << ans << endl;

    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
pair <int,int> D[18];
bool b[1003][1003];
char c[1003][1003];
inline void init () {
    D[0] = make_pair(0,1);
    D[1] = make_pair(1,0);
    D[2] = make_pair(0,-1);
    D[3] = make_pair(-1,0);
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    return;
}
int T,n,m,k;
inline bool chk (int x,int y) {
    if (x < 1 || n < x) {
        return false;
    }
    if (y < 1 || m < y) {
        return false;
    }
    if (c[x][y] == 'x') {
        return false;
    }
    return true;
}
int x,y,d;
int main () {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while (T--) {
        init();
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                cin >> c[i][j];
            }
        }
        b[x][y] = 1;
        for (int i = 1;i <= k;i++) {
            if (chk(x + D[d].first,y + D[d].second)) {
                x += D[d].first;
                y += D[d].second;
            } else {
                d = (d + 1) % 4;
            }
            b[x][y] = 1;
        }
        int ans = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (b[i][j]) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
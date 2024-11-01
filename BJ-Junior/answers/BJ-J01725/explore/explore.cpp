#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool visit[1005][1005];
bool check(int n, int m, int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) {
        return 0;
    }
    if(a[x][y] == 'x') {
        return 0;
    }
    return 1;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t, i;
    cin >> t;
    for(i = 1; i <= t; i++) {
        memset(visit, 0, sizeof(visit));
        int n, m, k, x, y, d;
        int i_1, i_2;
        int ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(i_1 = 1; i_1 <= n; i_1++) {
            for(i_2 = 1; i_2 <= m; i_2++) {
                cin >> a[i_1][i_2];
            }
        }
        visit[1][1] = 1;
        while(k--) {
            switch(d) {
                case 0: {
                    if(check(n, m, x, y + 1)) {
                        y = y + 1;
                        visit[x][y] = 1;
                    } else {
                        d = (d + 1) % 4;
                    }
                    break;
                }
                case 1: {
                    if(check(n, m, x + 1, y)) {
                        x = x + 1;
                        visit[x][y] = 1;
                    } else {
                        d = (d + 1) % 4;
                    }
                    break;
                }
                case 2: {
                    if(check(n, m, x, y - 1)) {
                        y = y - 1;
                        visit[x][y] = 1;
                    } else {
                        d = (d + 1) % 4;
                    }
                    break;
                }
                case 3: {
                    if(check(n, m, x - 1, y)) {
                        x = x - 1;
                        visit[x][y] = 1;
                    } else {
                        d = (d + 1) % 4;
                    }
                    break;
                }
            }
        }
        for(i_1 = 1; i_1 <= n; i_1++) {
            for(i_2 = 1; i_2 <= m; i_2++) {
                if(visit[i_1][i_2] == 1) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

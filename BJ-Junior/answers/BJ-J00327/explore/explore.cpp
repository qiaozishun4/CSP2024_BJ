// 勤奋 求实 创造 奉献
// Luogu Coder12823
// 塞尔达是天

#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
long long cnt;

void robot_move(long long &x, long long &y, long long n, long long m, long long &d) {
    long long tx, ty;
    if (d == 0) {
        tx = x; ty = y + 1;
    } else if (d == 1) {
        tx = x + 1; ty = y;
    } else if (d == 2) {
        tx = x; ty = y - 1;
    } else if (d == 3) {
        tx = x - 1; ty = y;
    }

    if (a[tx][ty] == '.' && x >= 1 && x <= n && y >= 1 && y <= m) {
        x = tx; y = ty;
        if (vis[x][y] == false) {
            cnt++;
        }
        vis[x][y] = true;
        return;
    }

    d = (d + 1) % 4;
    return;
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    long long T;
    scanf("%lld", &T);
    while (T--) {
        cnt = 1;
        memset(vis, 0, sizeof vis);
        long long n, m, k, x, y, d;
        scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &k, &x, &y, &d);
        for (long long i = 1; i <= n; i++) {
            scanf("%s", &a[i][1]);
        }

        // for (long long i = 1; i <= n; i++) {
        //     for (long long j = 1; j <= m; j++) {
        //         printf("%c", a[i][j]);
        //     }
        //     printf("\n");
        // }

        vis[x][y] = true;
        for (long long i = 0; i < k; i++) {
            robot_move(x, y, n, m, d);
        }
        printf("%lld\n", cnt);
    }

    return 0;
}

// C C F 快让我得 1=
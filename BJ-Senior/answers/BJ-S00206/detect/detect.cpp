#include <bits/stdc++.h>
using namespace std;

int n, m, l, lv, d[100005], v[100005], p[100005];
bool vis[100005];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f *= -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t = read();
    while (t--) {
        n = read(), m = read(), l = read(), lv = read();
        int vmax = -1, overrapid = 0, deleted = 0, dmax = 2147483647;
        for (int i = 1; i <= n; i++) {
            d[i] = read(), v[i] = read(); read();
            vmax = max(vmax, v[i]);
            dmax = min(dmax, d[i]);
        }
        for (int i = 1; i <= m; i++) {
            p[i] = read();
        }
        for (int i = 1; i <= n; i++) {
            bool found = false;
            for (int j = 1; j <= m; j++) {
                if (p[j] >= d[i]) {
                    vis[j] = true;
                    found = true;
                    break;
                }
            }
            if (found) overrapid += v[i] > lv;
        }
        if (!overrapid) deleted = m;
        else deleted = m - 1;
        printf("%d %d\n", overrapid, deleted);
    }
    return 0;
}
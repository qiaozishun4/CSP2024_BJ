#include <bits/stdc++.h>
using namespace std;

int res, n, m, L, V, d[100010], v[100010], a[100010], p[100010];
bool ifs[100010], open[100];// Is Fast Speed, open speedTest
bool check() {
    for (int i = 1; i <= n; i++) {
        bool IFS = 0;
        for (int j = 1; j <= m; j++) {
            if (d[i] > p[j] || open[j] == 0) {
                continue;
            }
            int s = p[j] - d[i];
            if (sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * s) > V) {
                IFS = 1;
                break;
            }
        }
        if (ifs[i] == 1 && IFS == 0) {
            return 0;
        }
    }
    return 1;
}
void dfs(int p, int cnt) {
    if (p > m) {
        if (check() == 1) {
            res = min(res, cnt);
        }
        return;
    }
    open[p] = 1, dfs(p + 1, cnt + 1);
    open[p] = 0, dfs(p + 1, cnt);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        memset(ifs, 0, sizeof ifs), memset(open, 0, sizeof open);
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + m + 1);
        if (n <= 20 && m <= 20) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (d[i] > p[j]) {
                        continue;
                    }
                    int s = p[j] - d[i];
                    if (sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * s) > V) {
                        ifs[i] = 1;
                        break;
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                ans += ifs[i];
            }
            cout << ans << ' ';
            res = m, dfs(1, 0);
            cout << m - res << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] > p[m]) {
                continue;
            }
            long long s = p[m] - d[i];
            if (sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * s) > V) {
                ifs[i] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += ifs[i];
        }
        cout << ans << ' ' << (ans == 0 ? m : m - 1) << '\n';
    }
    return 0;
}

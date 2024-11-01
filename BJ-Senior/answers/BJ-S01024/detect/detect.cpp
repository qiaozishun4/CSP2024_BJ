#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int T, n, m, L, V, d[N], v[N], a[N], p[N];
struct dat {
    int l, r;
    bool operator < (const dat &o) const {
        return r < o.r;
    }
} b[N];
void solve() {
    cin >> n >> m >> L >> V;
    for (int i = 1; i <= n; i++)
        cin >> d[i] >> v[i] >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> p[i];
    int ans1 = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            if (v[i] > V) {
                int x = lower_bound(p + 1, p + m + 1, d[i]) - p;
                if (x <= m) {
                    ans1++;
                    b[++cnt] = {x, m};
                }
            }
        }
        else if (a[i] > 0) {
            if (v[i] > V) {
                int x = lower_bound(p + 1, p + m + 1, d[i]) - p;
                if (x <= m) {
                    ans1++;
                    b[++cnt] = {x, m};
                }
            }
            else if (v[i] == V) {
                int x = upper_bound(p + 1, p + m + 1, d[i]) - p;
                if (x <= m) {
                    ans1++;
                    b[++cnt] = {x, m};
                }
            }
            else {
                //int y = ceil((double)((1.0 * V * V - 1.0 * v[i] * v[i]) / (2.0 * a[i])));
                int y = (V * V - v[i] * v[i]) / (2 * a[i]);
                //int flag = 1;
                //if (2 * a[i] * y != V * V - v[i] * v[i]) flag = 0;
                int x = lower_bound(p + 1, p + m + 1, d[i] + y + 1) - p;
                if (x <= m) {
                    ans1++;
                    b[++cnt] = {x, m};
                }
            }
        }
        else {
            if (v[i] > V) {
                //int y = floor((double)((1.0 * V * V - 1.0 * v[i] * v[i]) / (2.0 * a[i])));
                int y = (V * V - v[i] * v[i]) / (2 * a[i]);
                if (2 * a[i] * y == V * V - v[i] * v[i]) y--;
                int x = lower_bound(p + 1, p + m + 1, d[i]) - p;
                int z = upper_bound(p + 1, p + m + 1, d[i] + y) - p - 1;
                if (x <= z && x <= m) {
                    ans1++;
                    b[++cnt] = {x, z};
                }
            }
        }
    }
    sort(b + 1, b + cnt + 1);
    int ans2 = 0, mx = 0;
    for (int i = 1; i <= cnt; i++) {
        if (mx < b[i].l) {
            ans2++;
            mx = b[i].r;
        }
    }
    cout << ans1 << " " << m - ans2 << '\n';
}
signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) solve();
    return 0;
}
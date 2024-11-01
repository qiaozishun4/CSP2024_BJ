#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int d[maxn], v[maxn], a[maxn], p[maxn], close[maxn];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++) {
            close[i] = lower_bound(p + 1, p + m + 1, d[i]) - p;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0 && close[i] != m + 1 && v[i] > V) cnt++;
            if (a[i] != 0 && close[i] != m + 1 && (double)((V * V) - (v[i] * v[i])) / (2 * a[i]) + d[i] < p[m]) cnt++;
        }
        cout << cnt << " " << (cnt == 0 ? m : m - 1) << endl;
    }
    return 0;
}

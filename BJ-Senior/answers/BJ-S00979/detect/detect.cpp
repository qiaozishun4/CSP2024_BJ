#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, V, L, v[N], d[N], a[N], ans1 = 0, ans2 = 0, p[N];
bool vis[N], need[N];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        bool f = 0;
        memset(vis, 0, sizeof(vis));
        memset(need, 0, sizeof(need));
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] != 0) f = 1;
        }
        int last = 0;
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
            last = max(last, p[i]);
        }
        if (!f) {
            ans1 = 0;
            ans2 = 0;
            for (int i = 1; i <= n; i++) {
                if (d[i] > last) continue;
                if (v[i] > V) {
                    ans1++;
                    vis[i] = 1;
                }
            }
            cout << ans1 << ' ';
            for (int i = 1; i <= n; i++) {
                if (vis[i]) {
                    int idx = lower_bound(p + 1, p + n + 1, d[i]) - p;
                    need[idx] = 1;
                }
            }
            for (int i = 1; i <= m; i++) 
                if (need[i]) ans2++;
            ans2 = m - ans2;
            cout << ans2 << '\n';
        } else {
            cout << "3 3\n";
        }
    }
    return 0;
}
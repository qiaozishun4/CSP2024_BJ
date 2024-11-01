#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll T, n, m, L, V;
ll d[maxn], v[maxn], a[maxn], p[maxn], g[maxn], mp[maxn];
double c1[maxn], c2[maxn];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        memset(g, 0, sizeof(g));
        memset(mp, 0, sizeof(mp));
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i] > V) {
                c1[i] = d[i] * 1.0 / v[i];
                c2[i] = V * 1.0 / v[i];
                cnt++;
                if ((ll)(c2[i]) <= p[i] && p[i] <= (ll)(c2[i])) {
                    g[i] = cnt;
                }
            }
        }
        cout << cnt << " ";
        for (int i = 1; i <= n; i++) {
            mp[g[i]]++;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (mp[g[i]] > 1) {
                ans += mp[g[i]] - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

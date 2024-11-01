#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5, MAXM = 1e6;
ll t, n;
ll a[MAXN + 5], lst[MAXN + 5], b[MAXN + 5], dp[MAXN + 5], ma[MAXN + 5];
int p[MAXM + 5];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        ll tot = 0, res = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            if (i >= 2 && a[i] == a[i - 1]) res += a[i];
            else b[++tot] = a[i];
        }
        memset(p, 0, sizeof(p));
        for (ll i = 1; i <= tot; i++) {
            lst[i] = p[b[i]];
            p[b[i]] = i;
        }
        memset(dp, 0, sizeof(dp));
        ll res2 = 0;
        for (ll i = 1; i <= tot; i++) {
            if (lst[i]) dp[i] = max(ma[lst[i]], dp[lst[i] + 1]) + b[i];
            ma[i] = max(ma[i - 1], dp[i]);
            res2 = max(res2, dp[i]);
        }
        res += res2;
        cout << res << endl;
    }
    return 0;
}

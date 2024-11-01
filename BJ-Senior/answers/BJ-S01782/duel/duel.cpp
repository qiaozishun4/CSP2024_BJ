#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1e5 + 5;

int n, ans, tot, a[NR], cnt[NR];

signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], cnt[a[i]] ++;
    for (int i = 100000; i >= 1; --i) {
        int t = min(cnt[i], tot);
        ans += t, tot += cnt[i] - t;
    }
    cout << n - ans << '\n';
    return 0;
}
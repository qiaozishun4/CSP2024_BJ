#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 5;
int T, n, a[N], b[N], s[N], f[N][N], mx[N];
int calc(int l, int r) {
    if (l >= r) return 0;
    return s[r - 1] - s[l - 1];
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) b[i] = a[i];
        else b[i] = 0;
    }
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + b[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = s[i - 1];
        if (i == n) ans = f[i][0];
        for (int j = 0; j < i; j++) {
            f[i][j] = max(f[i][j], mx[j] + calc(j + 1, i));
            if (i == n) ans = max(ans, f[i][j]);
            mx[i] = max(mx[i], f[i][j] + (a[j] == a[i + 1] ? a[j] : 0));
        }
    }
    cout << ans << '\n';
}
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) solve();
    return 0;
}
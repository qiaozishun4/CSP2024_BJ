#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1, ch = getchar();
    while (!(ch == '-' || isdigit(ch))) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f == 1 ? x : -x;
}
#define ll long long
const int maxn = 2e5 + 10;
const int maxv = 1e6 + 10;
const ll inf = 1e15;
int n, a[maxn];
ll sum[maxn], f[maxn], best[maxv];
ll solve() {
    for (int i = 1; i < maxv; i++) best[i] = -inf;
    ll ans = sum[n], mx;
    f[1] = mx = 0;
    for (int i = 2; i <= n; i++) {
        f[i] = max(mx + sum[i - 1], sum[i - 1]);
        f[i] = max(f[i], best[a[i]] + sum[i - 1] + a[i]);
        mx = max(mx, f[i] - sum[i]);
        best[a[i - 1]] = max(best[a[i - 1]], f[i] - sum[i]);
        ans = max(ans, f[i] + sum[n] - sum[i]);
    }
    return ans;
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie();
    int t = read();
    while (t--) {
        n = read();
        for (int i = 1; i <= n; i++) a[i] = read(), sum[i] = sum[i - 1] + ((i > 1 && a[i] == a[i - 1]) ? a[i] : 0);
        printf("%lld\n", solve());
    }
    return 0;
}


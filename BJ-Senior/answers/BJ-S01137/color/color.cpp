#include <bits/stdc++.h>
typedef long long LL;
const int MAXN = 200005, MAXW = 1000005;
int n, a[MAXN], pre[MAXN], h[MAXW];
LL f[MAXN];

void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int cur = 0;
    a[0] = -1;
    LL ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] != a[cur])
            a[++cur] = a[i];
        else
            ans += a[i];
    }
    n = cur;
    for(int i = 1; i <= n; ++i) {
        pre[i] = h[a[i]];
        h[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i)
        h[a[i]] = 0;
    f[0] = 0;
    for(int i = 1; i < n; ++i) {
        f[i] = f[i - 1];
        if(pre[i] != 0 && pre[i + 1] != 0 && pre[i + 1] == i - 1)
            f[i] = std::max(f[i], f[pre[i]] + a[i] + a[i + 1]);
        if(pre[i] != 0)
            f[i] = std::max(f[i], f[pre[i]] + a[i]);
        if(pre[i + 1] != 0)
            f[i] = std::max(f[i], f[pre[i + 1]] + a[i + 1]);
    }
    printf("%lld\n", f[n - 1] + ans);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int a[maxn], b[maxn];
ll mx[maxm];

void work()
{
    int n, m = 0, mxa = 0; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], mxa = max(mxa, a[i]);
    for (int i = 1; i <= mxa; i++) mx[i] = -1e18;

    int l = 1; ll ans = 0, tmp = 0;
    while (l <= n)
    {
        int r = l;
        while (r < n && a[r + 1] == a[l]) r++;
        ans += 1ll * (r - l) * a[l];
        b[++m] = a[l];
        l = r + 1;
    }

    ll totmx = 0;
    for (int i = 2; i <= m; i++)
    {
        mx[b[i - 1]] = max(mx[b[i - 1]], max(totmx, mx[b[i]] + b[i]));
        totmx = max(totmx, mx[b[i - 1]]);
    }
    for (int i = 1; i <= mxa; i++) tmp = max(tmp, mx[i]);
    cout << ans + tmp << "\n";
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) work();
    return 0;
}
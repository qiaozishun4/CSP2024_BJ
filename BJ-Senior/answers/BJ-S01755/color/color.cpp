#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010], dp[200010], f[1000010];
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(dp, 0xcf, sizeof(dp));
        memset(f, 0xcf, sizeof(f));
        dp[0] = 0;
        int now = 0, mx = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(mx + now, f[a[i]] + now + a[i]);
            now += (a[i - 1] == a[i]) * a[i];
            mx = max(mx, dp[i] - now);
            f[a[i - 1]] = max(f[a[i - 1]], dp[i] - now);
        }
        int ans = now;
        now = 0;
        for (int i = n; i >= 2; i--)
        {
            ans = max(ans, dp[i] + now);
            now += (a[i - 1] == a[i]) * a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
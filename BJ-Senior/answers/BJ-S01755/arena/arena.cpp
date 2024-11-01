#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010], b[100010], c[100010], f[200010], pos[200010];
ll ans[100010], dp[400010];
vector<int> v[400010];
void merge(int x)
{
    int l = 2 * x, r = 2 * x + 1;
    v[x].clear();
    dp[x] = 0;
    if (f[x] == 1) swap(l, r);
    bool flag = false;
    for (auto i : v[l])
    {
        if (a[i] >= pos[x]) v[x].push_back(i);
        else flag = true;
    }
    if (dp[l]) dp[x] += dp[l], flag = true;
    if (flag)
    {
        for (auto i : v[r]) v[x].push_back(i);
        dp[x] += dp[r];
    }
}
ll calc(int l, int r)
{
    return 1ll * (l + r) * (r - l + 1) / 2;
}
signed main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, t;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    int k = __lg(2 * n - 1);
    for (int i = k - 1; i >= 0; i--)
    {
        for (int j = (1 << i); j < (1 << i + 1); j++)
        {
            char c;
            cin >> c;
            f[j] = c - '0', pos[j] = k - i;
        }
    }
    cin >> t;
    while (t--)
    {
        int x[4];
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for (int i = 1; i <= n; i++) a[i] = b[i] ^ x[i % 4];
        for (int i = 1; i < (1 << k + 1); i++)
        {
            v[i].clear();
            int x = (i - (1 << __lg(i))) * (1 << (k - __lg(i)));
            dp[i] = calc(x + 1, x + (1 << (k - __lg(i))));
        }
        for (int i = 1; i <= n; i++)
        {
            int x = (1 << k) + i - 1;
            dp[x] = 0;
            v[x].push_back(i);
            int kkk = (1 << (k - __lg(2 * i - 1)));
            while (x > kkk)
            {
                merge(x / 2);
                x /= 2;
            }
            ans[i] = dp[kkk];
            for (auto j : v[kkk]) ans[i] += j;
        }
        ll s = 0;
        for (int i = 1; i <= m; i++) s ^= (i * ans[c[i]]);
        cout << s << '\n';
    }
    return 0;
}
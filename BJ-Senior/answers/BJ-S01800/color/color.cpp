# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 2005;
int T, n;
int a[N];
int val[N];
int f[N][N];
int g[N];
void solve()
{
    cin >> n;
    if(n > 2000) return;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        val[i] = val[i - 1];
        if(a[i] == a[i - 1]) val[i] += a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = 0;
        }
        g[i] = 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            f[i][j] = max(g[i - j] + val[i] - val[i - j + 1], f[i][j]);
            int sum = (a[i - j] == a[i + 1] ? a[i + 1] : 0) + f[i][j];
            g[i] = max(g[i], sum);
            if(i == n) ans = max(ans, f[i][j]);
        }
    }
    cout << ans <<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--) solve();
    return 0;
}

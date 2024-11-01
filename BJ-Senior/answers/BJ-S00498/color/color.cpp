#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll t, n, f[N], a[N], ax;
bool vis[N];

ll check()
{
    ll x = 0, y = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] && a[i] == x) ans += x;
        else if (!vis[i] && a[i] == y) ans += y;
        if (vis[i]) x = a[i];
        else y = a[i];
    }
    return ans;
}

void dfs(ll x)
{
    if (x > n)
    {
        ax = max (ax, check());
        return ;
    }
    if (clock() >= 160000) return ;
    vis[x] = 0;
    dfs (x + 1);
    vis[x] = 1;
    dfs (x + 1);
}

int main()
{
    freopen ("color.in", "r", stdin);
    freopen ("color.out", "w", stdout);
    cin >> t;
    while (t --)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ax = 0;
        dfs (1);
        cout << ax << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

using namespace std;

using ll = long long;

int n;
int a[250001], prv[250001];
int cp[1500001];
ll dp[2001][2001][2];

struct SegT
{
    ll tree[1000001];
    ll lt[1000001];

    void Pushup(int cur)
    {
        tree[cur] = max(tree[ls(cur)], tree[rs(cur)]);
    }

    void Build(int cur, int l, int r)
    {
        tree[cur] = lt[cur] = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        Build(ls(cur), l, mid);
        Build(rs(cur), mid + 1, r);
    }

    void Pushdown(int cur)
    {
        if (!lt[cur]) return;
        tree[ls(cur)] += lt[cur];
        tree[rs(cur)] += lt[cur];
        lt[ls(cur)] += lt[cur];
        lt[rs(cur)] += lt[cur];
        lt[cur] = 0;
    }

    ll QueryMax(int cur, int l, int r, int s, int t)
    {
        if (l <= s && t <= r) return tree[cur];
        int mid = (s + t) >> 1;
        Pushdown(cur);
        ll ans = 0;
        if (l <= mid) ans = max(ans, QueryMax(ls(cur), l, r, s, mid));
        if (r > mid) ans = max(ans, QueryMax(rs(cur), l, r, mid + 1, t));
        return ans;
    }

    void SegAdd(int cur, int l, int r, int s, int t, ll x)
    {
        if (l <= s && t <= r)
        {
            tree[cur] += x;
            lt[cur] += x;
            return;
        }
        int mid = (s + t) >> 1;
        Pushdown(cur);
        if (l <= mid) SegAdd(ls(cur), l, r, s, mid, x);
        if (r > mid) SegAdd(rs(cur), l, r, mid + 1, t, x);
        Pushup(cur);
    }

}t[2];

void Solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        if (cp[a[i]]) prv[i] = cp[a[i]];
        else prv[i] = 0;
        cp[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) cp[a[i]] = 0;
    t[0].Build(1, 0, n);
    t[1].Build(1, 0, n);
    for (int i = 2; i <= n; i++)
    {
        ll c0 = t[0].QueryMax(1, 0, i - 2, 0, n);
        ll c1 = t[1].QueryMax(1, 0, i - 2, 0, n);
        if (prv[i] && prv[i] != i - 1)
        {
            ll cp0 = t[0].QueryMax(1, prv[i], prv[i], 0, n);
            ll cp1 = t[1].QueryMax(1, prv[i], prv[i], 0, n);
            t[0].SegAdd(1, i - 1, i - 1, 0, n, max(c1, cp1 + a[i]));
            t[1].SegAdd(1, i - 1, i - 1, 0, n, max(c0, cp0 + a[i]));
        }
        else
        {
            t[0].SegAdd(1, i - 1, i - 1, 0, n, c1);
            t[1].SegAdd(1, i - 1, i - 1, 0, n, c0);
        }
        if (prv[i] == i - 1)
        {
            t[0].SegAdd(1, 0, i - 2, 0, n, a[i]);
            t[1].SegAdd(1, 0, i - 2, 0, n, a[i]);
        }
    }
    cout << max(t[0].QueryMax(1, 0, n, 0, n), t[1].QueryMax(1, 0, n, 0, n)) << endl;
    return;
}

void Solve1()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        if (cp[a[i]]) prv[i] = cp[a[i]];
        else prv[i] = 0;
        cp[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) cp[a[i]] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++) dp[i][j][0] = dp[i][j][1] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0] + (ll)(a[i - 1] == a[i] ? a[i] : 0);
        dp[i][0][1] = dp[i - 1][0][1] + (ll)(a[i - 1] == a[i] ? a[i] : 0);
        for (int j = 1; j < i - 1; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + (ll)(a[i - 1] == a[i] ? a[i] : 0);
            dp[i][j][1] = dp[i - 1][j][1] + (ll)(a[i - 1] == a[i] ? a[i] : 0);
        }
        dp[i][i - 1][0] = dp[i - 1][0][1];
        dp[i][i - 1][1] = dp[i - 1][0][0];
        for (int j = 1; j < i - 1; j++)
        {
 //           dp[i][i - 1][0] = max(dp[i][i - 1][0], dp[i - 1][j][1] + (ll)(a[j] == a[i] ? a[i] : 0));
//            dp[i][i - 1][1] = max(dp[i][i - 1][1], dp[i - 1][j][0] + (ll)(a[j] == a[i] ? a[i] : 0));
            dp[i][i - 1][0] = max(dp[i][i - 1][0], dp[i - 1][j][1]);
            dp[i][i - 1][1] = max(dp[i][i - 1][1], dp[i - 1][j][0]);
        }
        if (prv[i]) 
        {
            dp[i][i - 1][0] = max(dp[i][i - 1][0], dp[i - 1][prv[i]][1] + a[i]);
            dp[i][i - 1][1] = max(dp[i][i - 1][1], dp[i - 1][prv[i]][0] + a[i]);
        }
    } // for segtree, first update dp[i][i - 1], then interval add on everything else
    ll ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
    cout << ans << endl;
    return;
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int _;
    cin >> _;
    while (_--) Solve();
    return 0;
}
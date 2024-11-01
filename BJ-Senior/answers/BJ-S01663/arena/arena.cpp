#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
ll read()
{
    ll res = 0;
    bool flg = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        flg |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = res * 10 + ch - '0', ch = getchar();
    return (flg ? -1 : 1) * res;
}
int _num[100];
void write(ll x)
{
    if (!x)
    {
        putchar('0');
        return;
    }
    if (x < 0)
    {
        putchar('-'), write(-x);
        return;
    }
    int cnt = 0;
    while (x)
        _num[++cnt] = x % 10, x /= 10;
    for (int i = cnt; i >= 1; i--)
        putchar('0' + _num[i]);
    return;
}
void write(char ch) { putchar(ch); }
#define int ll
constexpr int N = 1e5;

int n, m, k;
int A[N + 10], a[N + 10], c[N + 10], d[__lg(N) + 3][N + 10];
int X[4];
int rem[N + 10];

int win[4 * N + 10];
pair<int, int> rd[4 * N + 10];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
void build(int x = 1, int l = 1, int r = 1ll << k)
{
    if (l == r)
    {
        win[x] = l;
        rd[x] = {0, l};
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(x), l, mid), build(rs(x), mid + 1, r);
    rd[x] = {rd[ls(x)].first + 1, rd[rs(x)].second / 2};
    if (!d[rd[x].first][rd[x].second])
    {
        if (a[win[ls(x)]] >= rd[x].first)
            win[x] = win[ls(x)];
        else
            win[x] = win[rs(x)];
    }
    else
    {
        if (a[win[rs(x)]] >= rd[x].first)
            win[x] = win[rs(x)];
        else
            win[x] = win[ls(x)];
    }
}
pair<vector<int>, int> query(int pos, int x = 1, int l = 1, int r = 1ll << k)
{
    if (r <= pos)
    {
        vector<int> v;
        v.push_back(win[x]);
        return {v, 0};
    }
    if (l > pos)
    {
        vector<int> v;
        return {v, (l + r) * (r - l + 1) / 2};
    }
    
    int mid = (l + r) >> 1;
    auto pl = query(pos, ls(x), l, mid);
    auto pr = query(pos, rs(x), mid + 1, r);
    auto vl = pl.first, vr = pr.first;
    vector<int> v;
    int sum = 0;
    if (!d[rd[x].first][rd[x].second])
    {
        bool flg = 0;
        sum += pl.second;
        if (pl.second)
            flg = 1;
        for (auto t : vl)
            if (a[t] >= rd[x].first)
                v.push_back(t);
            else
                flg = 1;
        if (flg)
        {
            for (auto t : vr)
                v.push_back(t);
            sum += pr.second;
        }
    }
    else
    {
        bool flg = 0;
        sum += pr.second;
        if (pr.second)
            flg = 1;
        for (auto t : vr)
            if (a[t] >= rd[x].first)
                v.push_back(t);
            else
                flg = 1;
        if (flg)
        {
            for (auto t : vl)
                v.push_back(t);
            sum += pl.second;
        }
    }
    return {v, sum};
}

void solve()
{
    for (int i = 0; i < 4; i++)
        X[i] = read();
    for (int i = 1; i <= n; i++)
        a[i] = A[i] ^ X[i % 4];
    build();
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (rem[c[i]])
        {
            ans ^= i * rem[c[i]];
            continue;
        }
        int x = 1, r = 1ll << k;
        while (r / 2 >= c[i])
            r /= 2, x *= 2;
        auto p = query(c[i], x, 1, r);
        for (auto t : p.first)
            p.second += t;
        rem[c[i]] = p.second;
        ans ^= i * rem[c[i]];
    }
    write(ans), write(endl);
    for(int i = 1; i <= m; i++)
        rem[c[i]] = 0;
}

signed main()
{
    // double ST = clock();
    // cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    n = read(), m = read(), k = __lg(n - 1) + 1;
    for (int i = 1; i <= n; i++)
        A[i] = read();
    for (int i = 1; i <= m; i++)
        c[i] = read();
    for (int i = 1; i <= k; i++)
    {
        int t = 1ll << (k - i);
        for (int j = 1; j <= t; j++)
        {
            char ch = getchar();
            while (ch < '0' || ch > '9')
                ch = getchar();
            d[i][j] = ch - '0';
        }
    }
    int T = read();
    while (T--)
        solve();

    // double ED = clock();
    // cerr << (ED - ST) / CLOCKS_PER_SEC << endl;
    return 0;
}

// 16:44
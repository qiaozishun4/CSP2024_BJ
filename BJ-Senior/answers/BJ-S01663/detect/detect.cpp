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
constexpr int N = 1e5, M = 1e6;

int n, m, L, V;
struct Node
{
    int l, r;
    bool operator<(const Node &B) const { return r < B.r; }
} p[N + 10], q[N + 10];
set<int> s;

void solve()
{
    n = read(), m = read(), L = read(), V = read();
    for (int i = 1; i <= n; i++)
    {
        int d = read(), v = read(), a = read();
        p[i] = {-1, -1};
        if (a > 0 && v * v + 2 * a * (L - d) > V * V)
        {
            p[i] = {d, L};
            if (v <= V)
                p[i].l = d + (V * V - v * v) / (2 * a) + 1;
        }
        else if (a == 0 && v > V)
            p[i] = {d, L};
        else if (a < 0 && v > V)
        {
            p[i] = {d, L};
            if (v * v + 2 * a * (L - d) <= V * V)
            {
                int x = (v * v - V * V) / (-2 * a);
                if (-2 * a * x == v * v - V * V)
                    x--;
                p[i].r = d + x;
            }
        }
    }
    for (int i = 1; i <= m; i++)
        s.emplace(read());
    s.emplace(L + 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (*s.lower_bound(p[i].l) <= p[i].r)
            q[++cnt] = p[i];
    write(cnt), write(' ');

    sort(q + 1, q + cnt + 1);
    int lst = -1, ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (q[i].l <= lst)
            continue;
        ans++, lst = *(--s.upper_bound(q[i].r));
    }
    write(m - ans), write(endl);

    s.clear();
    for (int i = 1; i <= n; i++)
        p[i] = {0, 0};
    for (int i = 1; i <= cnt; i++)
        q[i] = {0, 0};
}

signed main()
{
    // double ST = clock();
    // cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int T = read();
    while (T--)
        solve();

    // double ED = clock();
    // cerr << (ED - ST) / CLOCKS_PER_SEC << endl;
    return 0;
}

// 15:29
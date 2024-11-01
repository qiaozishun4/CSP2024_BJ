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
constexpr int N = 2e5;

int n;
int a[N + 10];
int mx[N + 10];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        int nw = 0, s = 0;
        for (int j = i - 2; j >= 1; j--)
            nw = max(nw, mx[j] + s + (a[j] == a[i] ? a[i] : 0)), s += (a[j] == a[j + 1] ? a[j] : 0);
        mx[i] = max(mx[i], nw + (a[i - 1] == a[i + 1] ? a[i - 1] : 0)), s = 0;
        for (int j = i + 1; j <= n; j++)
            s += (a[j] == a[j - 1] ? a[j] : 0), mx[j] = max(mx[j], nw + s + (a[i - 1] == a[j + 1] ? a[i - 1] : 0));
    }
    write(mx[n]), write(endl);

    for (int i = 1; i <= n; i++)
        a[i] = mx[i] = 0;
}

signed main()
{
    // double ST = clock();
    // cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int T = read();
    while (T--)
        solve();

    // double ED = clock();
    // cerr << (ED - ST) / CLOCKS_PER_SEC << endl;
    return 0;
}

// 17:39 18:25
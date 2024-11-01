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

int n;
int r[N + 10];

signed main()
{
    // double ST = clock();
    // cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    n = read();
    for (int i = 1; i <= n; i++)
        r[i] = read();
    sort(r + 1, r + n + 1);
    int j = 1;
    for (int i = 2; i <= n; i++)
        if (r[i] > r[j])
            j++;
    write(n - j + 1), write(endl);

    // double ED = clock();
    // cerr << (ED - ST) / CLOCKS_PER_SEC << endl;
    return 0;
}

// 14:36
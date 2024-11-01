#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <ctime>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++)
    template <typename T>
    void Read(T &x)
    {
        x = 0; char ch = gc; bool f = 0;
        while (ch < '0' || ch > '9') { if (ch == '-') f = 1; ch = gc; }
        while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc;
        if (f) x = -x;
    }
}

using namespace std;
using FastIO::Read;

const int MAXN = 1e5 + 10;

int n, m; ll L, V;

int d[MAXN], v0[MAXN], a[MAXN];
int p[MAXN];

struct Seg
{
    int l, r;
    bool operator < (const Seg &u) const {return r < u.r; }
}op[MAXN];
int q;

void Calc(int d, ll v0, ll a)
{
    if (a == 0)
    {
        if (v0 <= V) return;
        int pos = lower_bound(p + 1, p + m + 1, d) - p;
        if (pos <= m) op[++q] = Seg{pos, m};
    }
    else if (a > 0)
    {
        int l = 1, r = m, mid, ans = m + 1;
        while (l <= r)
        {
            mid = l + r >> 1;
            if (p[mid] < d) { l = mid + 1; continue; }
            if (v0 * v0 + 2 * a * (p[mid] - d) > V * V) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        if (ans <= m) op[++q] = Seg{ans, m};
    }
    else
    {
        if (v0 <= V) return;
        int pos = lower_bound(p + 1, p + m + 1, d) - p;
        int l = pos, r = m, mid, ans = l - 1;
        while (l <= r)
        {
            mid = l + r >> 1;
            if (v0 * v0 + 2 * a * (p[mid] - d) < 0) { r = mid - 1; continue; }
            if (v0 * v0 + 2 * a * (p[mid] - d) > V * V) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        if (ans >= pos) op[++q] = Seg{pos, ans};
    }
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    Read(T);
    while (T--)
    {
        Read(n), Read(m), Read(L), Read(V);
        for (int i = 1; i <= n; i++) Read(d[i]), Read(v0[i]), Read(a[i]);
        for (int i = 1; i <= m; i++) Read(p[i]);
        q = 0;
        for (int i = 1; i <= n; i++) Calc(d[i], v0[i], a[i]);
        sort(op + 1, op + q + 1);
        int pre = 0, cnt = 0;
        for (int i = 1; i <= q; i++)
            if (op[i].l > pre) pre = op[i].r, cnt++;
        cout << q << ' ' << m - cnt << '\n';
    }
    return 0;
}
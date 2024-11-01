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

const int MAXN = 2e5 + 10, MAXM = 1e6 + 10;

int n, a[MAXN];
int lst[MAXM], pre[MAXN];

ll tr[MAXN << 2], add[MAXN << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
inline void Pushup(int p) { tr[p] = max(tr[ls], tr[rs]); }
inline void Calc(int p, ll k) { tr[p] += k, add[p] += k; }
inline void Pushdown(int p) { if (!add[p]) return; Calc(ls, add[p]), Calc(rs, add[p]), add[p] = 0; }
void Build(int p, int l, int r)
{
    tr[p] = add[p] = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    Build(ls, l, mid), Build(rs, mid + 1, r);
}
void Update(int p, int l, int r, int x, int y, ll k)
{
    if (x <= l && r <= y) return Calc(p, k);
    Pushdown(p); int mid = l + r >> 1;
    if (x <= mid) Update(ls, l, mid, x, y, k);
    if (y > mid) Update(rs, mid + 1, r, x, y, k);
    Pushup(p);
}
ll Query(int p, int l, int r, int x)
{
    if (l == r) return tr[p];
    Pushdown(p); int mid = l + r >> 1;
    if (x <= mid) return Query(ls, l, mid, x);
    return Query(rs, mid + 1, r, x);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    Read(T);
    while (T--)
    {
        Read(n);
        for (int i = 1; i <= n; i++) Read(a[i]), lst[a[i]] = 0;
        for (int i = 1; i <= n; i++) pre[i] = lst[a[i]], lst[a[i]] = i;

        Build(1, 0, n);
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == a[i - 1]) Update(1, 0, n, 0, i - 2, a[i]);
            Update(1, 0, n, i - 1, i - 1, max(tr[1], (pre[i] ? Query(1, 0, n, pre[i]) + a[i] : 0ll)));
        }
        cout << tr[1] << '\n';
    }
    return 0;
}
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

int n, a[MAXN], cnt[MAXN];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    Read(n);
    for (int i = 1; i <= n; i++) Read(a[i]), cnt[a[i]]++;
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, cnt[a[i]]);
    cout << mx << '\n';
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct fraction {
    long long u, d;

    void simplify() {
        if (d < 0) u = -u, d = -d;
        long long gcdn = __gcd(u, d);
        u /= gcdn, d /= gcdn;
    }

    fraction operator += (int x) {
        simplify();
        u += x * d;
        return *this;
    }

    int low_int() { return u / d - (u % d == 0); }
    int up_int() { return u / d + 1; }
};

fraction make_frac(long long u, long long d) {
    fraction frac = {u, d};
    frac.simplify();
    return frac;
}

int t;
int n, m, len, lim;
int p[100005];

struct segment
  { int l, r; };
vector<segment> req;

segment make_seg(int l, int r) {
    segment seg = {l, r};
    return seg;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &m, &len, &lim);

        req.clear();
        req.reserve(n);
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            int d, v, a;
            scanf("%d%d%d", &d, &v, &a);
            if (a >= 0) cnt++;
            if (v >  lim && a >= 0) req.push_back(make_seg(d, len));
            if (v >  lim && a <  0) req.push_back(make_seg(d, (make_frac(v * v - 1ll * lim * lim, -2 * a) += d).low_int()));
            if (v == lim && a >  0) req.push_back(make_seg(d + 1, len));
            if (v <  lim && a >  0) req.push_back(make_seg((make_frac(1ll * lim * lim - v * v, 2 * a) += d).up_int(), len));
        }
        for (int i = 0; i < m; ++i)
            scanf("%d", &p[i]);
        sort(p, p + m);
/*
        for (auto seg : req)
            printf("[%d, %d], ", seg.l, seg.r);
        puts("");
*/

        int tot = 0;
        for (auto seg : req)
            tot += (seg.l <= p[m - 1]);
        printf("%d %d\n", tot, m - 1);
    }
    return 0;
}

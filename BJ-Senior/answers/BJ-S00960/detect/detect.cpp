#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long LL;
LL gcd(LL x, LL y);
struct frac {
    LL v1, v2;
    friend bool operator <(frac &x, frac &y) {
        return x.v1 * y.v2 < y.v1 * x.v2;
    }

    friend bool operator <=(frac &x, frac &y) {
        return x.v1 * y.v2 <= y.v1 * x.v2;
    }

    friend bool operator >(frac &x, frac &y) {
        return x.v1 * y.v2 > y.v1 * x.v2;
    }

    friend bool operator >=(frac &x, frac &y) {
        return x.v1 * y.v2 >= y.v1 * x.v2;
    }

    friend bool operator ==(frac &x, frac &y) {
        return x.v1 * y.v2 == y.v1 * x.v2;
    }

    friend frac operator +(frac x, frac y) {
        if (!x.v1) return y;
        if (!y.v1) return x;
        LL v3 = gcd(x.v2, y.v2);
        frac z(x.v1 * y.v2 / v3 + y.v1 * x.v2 / v3, x.v2 / v3 * y.v2 / v3);
        return z;
    }

    frac (LL x = 0, LL y = 1) {
        this->v1 = x;
        this->v2 = y;
    } 
};

const LL N = 100010;
LL t, n, m, h;
LL a[N], b[N], d[N];
frac l;
frac p[N];
pair<LL, LL> g[N];
LL gcd(LL x, LL y) {
    if (!y) return x;
    return gcd(y, x % y);
}

LL fnd1(frac &k) {
    if (k > p[m]) return m + 1;
    LL l = 0, r = m;
    while (l < r) {
        LL mid = (l + r) / 2;
        if (p[mid] < k) l = mid + 1;
        else r = mid;
    }

    return l;
}

LL fnd2(frac &k) {
    if (k >= p[m])  return m + 1; 
    LL l = 0, r = m;
    while (l < r) {
        LL mid = (l + r) / 2;
        if (p[mid] <= k) l = mid + 1;
        else r = mid;
    }

    return l;
}

bool cmp(pair<LL, LL> &x, pair<LL, LL> &y) {
    return x.first < y.first;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &t);
    while (t -- ) {
        scanf("%lld%lld%lld%lld", &n, &m, &l.v1, &h);
        l.v2 = 1;
        for (int i = 1; i <= n; i ++ ) {
            scanf("%lld%lld%lld", &a[i], &b[i], &d[i]);
        }
        
        for (int i = 1; i <= m; i ++ ) {
            scanf("%lld", &p[i].v1);
            p[i].v2 = 1;
        }

        p[0] = frac(-1, 1);
        LL r = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (d[i] < 0) {
                if (b[i] <= h) continue;
                frac v1 = frac(a[i], 1);
                frac v2 = frac(b[i] * b[i] - h * h, -2 * d[i]) + v1;
                LL k1 = fnd1(v1), k2 = fnd1(v2);
                k2 -- ;
                if (k1 <= k2) {
                    r ++ ;
                    g[r] = {k1, k2};
                }
            } else if (d[i] > 0) {
                frac v = frac(a[i], 1);
                if (b[i] <= h) v = frac(h * h - b[i] * b[i], 2 * d[i]) + v;
                LL k = fnd1(v);
                if (b[i] <= h) k = fnd2(v);
                if (k <= m) {
                    r ++ ;
                    g[r] = {k, m};
                }
            } else {
                if (b[i] <= h) continue;
                frac v = frac(a[i], 1);
                LL k = fnd1(v);
                if (k <= m) {
                    r ++ ;
                    g[r] = {k, m};
                }
            }
        }

        sort(g + 1, g + r + 1, cmp);
        LL res = m, s = 0;
        for (int i = 1; i <= r; i ++ ) {
            if (g[i].first > s) {
                res -- ;
                s = m + 1;
            }

            s = min(s, g[i].second);
        }

        if (s == m + 1) res -- ;
        printf("%lld %lld\n", r, res);
    }                

    return 0;
}
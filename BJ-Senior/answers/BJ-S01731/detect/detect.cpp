

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for(int i = s; i <= t; i++) 
#define per(i, s, t) for(int i = t; i >= s; i--)

typedef long long ll;
typedef long double ldb;

const int MAXN = 1e5 + 9;

struct Car {

    int d, v, a;
    ldb l;

};

int T;
int n, m, L, V;
Car a[MAXN];
bool is[MAXN];
int p[MAXN];
set<int> res;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> T;

    while (T--) {
        int res1 = 0;
        int res2 = 0;

        cin >> n >> m >> L >> V;

        memset(is, 0, sizeof(is));
        res.clear();

        rep (i, 1, n) {
            cin >> a[i].d >> a[i].v >> a[i].a;

            a[i].l = 0;

            if (a[i].a > 0) {
                if (a[i].v > V) {
                    // 大于等于a[i].d且小于等于L即超速
                    continue;
                }

                a[i].l = a[i].d + 1.0 * (2 * a[i].v * (V - a[i].v) + (V - a[i].v) * (V - a[i].v)) / (2 * a[i].a); // 大于a[i].l且小于等于L即超速
            }
            
            else if (a[i].a < 0) {
                if (a[i].v <= V) {
                    // 永不超速
                    continue;
                }

                a[i].l = a[i].d + 1.0 * (2 * a[i].v * (V - a[i].v) + (V - a[i].v) * (V - a[i].v)) / (2 * a[i].a); // 小于a[i].l且大于等于a[i].d即超速
            }

            else {
                if (a[i].v > V) {
                    // 大于等于a[i].d且小于等于L即超速
                }

                else if (a[i].v <= V) {
                    // 永不超速
                }
            }
        }

        rep (i, 1, m) {
            cin >> p[i];
        }

        rep (i, 1, n) {
            if (a[i].a > 0) {
                if (a[i].v > V) {
                    if (p[m] >= a[i].d && a[i].d <= L) {
                        is[i] = 1; // 大于等于a[i].d且小于等于L即超速

                        if (res.find(p[m]) == res.end()) {
                            res.insert(p[m]);
                        }
                    }
                }

                else if (p[m] > a[i].l && a[i].d < L) {
                    is[i] = 1; // 大于a[i].l且小于等于L即超速

                    if (res.find(p[m]) == res.end()) {
                        res.insert(p[m]);
                    }
                }
            }

            else if (a[i].a < 0) {
                if (a[i].v <= V) {
                    continue;
                }

                int x = lower_bound(p + 1, p + m + 1, a[i].d) - p;

                if (p[x] < a[i].l && a[i].d < a[i].l) {
                    is[i] = 1; // 小于a[i].l且大于等于a[i].d即超速

                    auto y = lower_bound(res.begin(), res.end(), a[i].d);

                    if (y == res.end() || *y >= a[i].l) {
                        res.insert(p[x]);
                    }
                }
            }

            else {
                if (a[i].v > V) {
                    if (p[m] >= a[i].d && a[i].d <= L) {
                        is[i] = 1; // 大于等于a[i].d且小于等于L即超速

                        if (res.find(p[m]) == res.end()) {
                            res.insert(p[m]);
                        }
                    }
                }
            }
        }

        rep (i, 1, n) {
            res1 += is[i];
        }

        res2 = m - res.size();

        cout << res1 << ' ' << res2 << '\n';
    }

    return 0;

}
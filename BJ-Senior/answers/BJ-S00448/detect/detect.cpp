#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1e5+4;

int L, V, n, m, T;
struct car {
    int d, v, a;
    int s = -1, t = -1;
    bool oov = false;
};
int p[N];

bool cmp1(car x, car y) {
    return x.oov > y.oov;
}
bool cmp2(car x, car y) {
    return x.t < y.t;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    scanf("%d", &T);
    while (T--){

        car c[N] = {};
        memset(p, 0, sizeof p);

        scanf("%d%d%d%d", &n, &m, &L, &V);
        for (int i = 0; i < n; i++) scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
        for (int i = 0; i < m; i++) scanf("%d", &p[i]);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!c[i].a) {
                c[i].oov = (c[i].v > V && c[i].d <= p[m - 1]);
                if (c[i].oov) c[i].s = lower_bound(p, p + m, c[i].d) - p, c[i].t = m - 1, cnt++;
            } else if (c[i].a > 0) {
                double ds = (V * V - c[i].v * c[i].v) * 1. / (2. * c[i].a);
                c[i].oov = (c[i].d * 1. + ds < p[m - 1] && c[i].d <= p[m - 1]);
                if (!c[i].oov) continue;
                cnt++;
                if (ds < 0) {
                    c[i].s = lower_bound(p, p + m, c[i].d) - p;
                    c[i].t = m - 1;
                } else {
                    c[i].s = upper_bound(p, p + m, c[i].d * 1. + ds) - p;
                    c[i].t = m - 1;
                }
            } else {
                double ds = (V * V - c[i].v * c[i].v) * 1. / (2. * c[i].a);
                if (ds <= 0) {
                    c[i].oov = false;
                    continue;
                }
                c[i].s = lower_bound(p, p + m, c[i].d) - p;
                c[i].t = lower_bound(p, p + m, c[i].d + ds) - p - 1;
                c[i].oov = (c[i].s <= c[i].t);
                cnt += c[i].oov;
            }
        }
        printf("%d ", cnt);

        // for (int i = 0; i < n; i++) printf("%d %d %d\n", c[i].oov, c[i].s, c[i].t);

        sort(c, c + n, cmp1);
        sort(c, c + cnt, cmp2);
        int k = -1;
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            if (c[i].s > k) ans++, k = c[i].t;
        }

        printf("%d\n", m - ans);

    }

    return 0;
}
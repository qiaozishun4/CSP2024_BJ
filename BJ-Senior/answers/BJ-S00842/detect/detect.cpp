#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int p[maxn], n, m, L, V;
struct car {
    int d, v, a;
} q[maxn];
struct node {
    int l, r;
    bool operator < (const node & p) const {
        return r < p.r;
    }
} a[maxn];
int tot;
int T;
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &q[i].d, &q[i].v, &q[i].a);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &p[i]);
        }
        tot = 0;
        for (int i = 1; i <= n; i++) {
            if (q[i].v <= V && q[i].a <= 0) {
                continue;
            }
            if (q[i].v > V && q[i].a >= 0) {
                if (p[m] >= q[i].d) {
                    tot++;
                    a[tot].l = lower_bound(p + 1, p + m + 1, q[i].d) - p;
                    a[tot].r = m;
                    //cout << i << '*' << a[tot].l << ' ' << a[tot].r << endl;
                }
                continue;
            }
            if (q[i].v > V && q[i].a < 0) {
                int pos = q[i].d + ceil((V * V - q[i].v * q[i].v) / (2.0 * q[i].a)) - 1;
                int p1 = lower_bound(p + 1, p + m + 1, q[i].d) - p;
                int p2 = upper_bound(p + 1, p + m + 1, pos) - p - 1;
                if (p1 <= p2) {
                    tot++;
                    a[tot].l = p1;
                    a[tot].r = p2;
                    //cout << i << '*' << a[tot].l << ' ' << a[tot].r << endl;
                }
                continue;
            }
            if (q[i].v <= V && q[i].a > 0) {
                int pos = q[i].d + (V * V - q[i].v * q[i].v) / (2 * q[i].a) + 1;
                if (p[m] >= pos) {
                    tot++;
                    a[tot].l = lower_bound(p + 1, p + m + 1, pos) - p;
                    a[tot].r = m;
                    //cout << i << '*' << a[tot].l << ' ' << a[tot].r << endl;
                }
                continue;
            }
        }
        cout << tot << ' ';
        sort(a + 1, a + tot + 1);
        int lst = 0, ans = 0;
        for (int i = 1; i <= tot; i++) {
            if (a[i].l > lst) {
                ans++;
                lst = a[i].r;
            }
        }
        cout << m - ans << endl;
    }
    return 0;
}

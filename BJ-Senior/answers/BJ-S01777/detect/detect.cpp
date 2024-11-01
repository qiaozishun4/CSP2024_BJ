// 100pts
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 9;
int v1(int v0, int a, int s) {
    return v0 * v0 + 2 * a * s;
}
struct node {
    int d, v, a, lt, rt;
} s[N];
bool cmp(node x, node y) {
    if (x.rt != y.rt) return x.rt < y.rt;
    else return x.lt < y.lt;
}
int n, m, l, v, p[N], ov[N], tp;
#define lb(x) (x & -x)
struct BIT {
    int C[N];
    void clear() {
        for (int i = 1; i <= m; i++) C[i] = 0;
    }
    void upd(int x, int v) {
        while (x <= m) C[x] += v, x += lb(x);
    }
    int get(int x) {
        int res = 0;
        while (x) res += C[x], x -= lb(x);
        return res;
    }
    int qry(int x, int y) {return get(y) - get(x - 1);}
} T;
void slv() {
    scanf("%lld%lld%lld%lld", &n, &m, &l, &v);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &s[i].d, &s[i].v, &s[i].a);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &p[i]);
    }
    p[0] = -1, p[m + 1] = l + 1;
    tp = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i].a >= 0) {
            int lt = lower_bound(p + 1, p + m + 1, s[i].d) - p, rt = m + 1, mid;
            while (lt < rt) {
                mid = (lt + rt) >> 1;
                if (v1(s[i].v, s[i].a, p[mid] - s[i].d) > v * v) rt = mid;
                else lt = mid + 1;
            }
            if (lt > m) continue;
            s[i].lt = lt, s[i].rt = m, ov[++tp] = i;
        } else {
            int lt = lower_bound(p + 1, p + m + 1, s[i].d) - p, rt = m, mid;
            if (lt > m || v1(s[i].v, s[i].a, p[lt] - s[i].d) <= v * v) continue;
            s[i].lt = lt;
            while (lt < rt) {
                mid = (lt + rt + 1) >> 1;
                if (v1(s[i].v, s[i].a, p[mid] - s[i].d) > v * v) lt = mid;
                else rt = mid - 1;
            }
            s[i].rt = lt, ov[++tp] = i;
        }
    }
    printf("%lld ", tp);
    // for (int i = 1; i <= tp; i++) cout << ov[i] << ' ' << s[ov[i]].lt << ' ' << s[ov[i]].rt << endl;
    // cout << endl;
    n = tp;
    for (int i = 1; i <= n; i++) s[i] = s[ov[i]];
    sort(s + 1, s + n + 1, cmp);
    T.clear();
    for (int i = 1; i <= n; i++) {
        if (!T.qry(s[i].lt, s[i].rt)) T.upd(s[i].rt, 1);
    }
    printf("%lld\n", m - T.get(m));
}
signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int _; scanf("%lld", &_);
    while (_--) slv();
    fclose(stdin), fclose(stdout);
    return 0;
}
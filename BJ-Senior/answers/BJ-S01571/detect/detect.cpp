#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 8;
const int MAXL = 1e6 + 8;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;
int n, m, L, V, sz;
int l[MAXN], r[MAXN], p[MAXN];
struct Range {
    int lb, ub;
    bool operator < (const Range& rhs) const {
        if (lb != rhs.lb) return lb < rhs.lb;
        return ub > rhs.ub;
    }
} rg[MAXN];
void cal_range(int i, int d, int v, int a) {
    if (a == 0) {
        if (v > V) l[i] = d, r[i] = L;
        return;
    }
    if (a > 0) {
        double t = 1.0 * (V - v) / a;
        if (t < 0) l[i] = d, r[i] = L;
        else l[i] = ceil(1.0 * d + t * v + 0.5 * t * t * a + EPS) , r[i] = L;
        return;
    }
    if (v <= V) return;
    double t = 1.0 * (V - v) / a;
    l[i] = d, r[i] = floor(1.0 * d + t * v + 0.5 * t * t * a - EPS);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        cin >> n >> m >> L >> V;
        for (int i = 1, d, v, a; i <= n; i++) cin >> d >> v >> a, cal_range(i, d, v, a);
        for (int i = 1; i <= m; i++) cin >> p[i];
        sort(p + 1, p + m + 1);
        int ans1 = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i] > r[i]) continue;
            int lb = lower_bound(p + 1, p + m + 1, l[i]) - p;
            int ub = upper_bound(p + 1, p + m + 1, r[i]) - p;
            if (ub > lb) rg[++ans1] = {lb, ub}; // [lb, ub)
        }
        sort(rg + 1, rg + ans1 + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (rg[j].lb >= rg[i].ub) break;
                if (rg[j].ub <= rg[i].ub) {
                    rg[i].lb = rg[i].ub = INF;
                    break;
                }
            }
        }
        sort(rg + 1, rg + ans1 + 1);
        sz = 0;
        while (rg[sz + 1].lb != INF) sz++;
        int ans2 = 0, cvr = 1, pos;
        while (cvr <= sz) {
            ans2++;
            pos = rg[cvr].ub;
            while (cvr <= sz && rg[cvr].lb <= pos) cvr++;
        }
        cout << ans1 << " " << n - ans2 << endl;
    }
    return 0;
}

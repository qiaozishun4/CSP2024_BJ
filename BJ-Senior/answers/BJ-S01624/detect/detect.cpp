#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, m, L, V, d[N], v[N], a[N], p[N], cnt, cnt2;
struct node {
    int l, r;
} g[N];
bool cmp(node x, node y) {
    if (x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(p, 0, sizeof(p));
        cnt = 0;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", d + i, v + i, a + i);
        }
        for (int i = 1; i <= m; ++i) scanf("%d", p + i);
        sort(p + 1, p + m + 1);
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) {
                if (v[i] > V) {
                    int low = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    if (low <= m && low >= 1) {
                        g[++cnt] = node{low, m};
                    }
                } else {
                    double t = (V - v[i]) * 1.0 / a[i];
                    double s = d[i] + v[i] * t + 0.5 * a[i] * t * t;
                    if (ceil(s) <= p[m]) {
                        int low = lower_bound(p + 1, p + m + 1, ceil(s)) - p;
                        g[++cnt] = node{low, m};
                    }
                }
            } else if (a[i] < 0) {
                if (v[i] <= V) continue;
                int pos = lower_bound(p + 1, p + m + 1, d[i]) - p;
                int dd = p[pos] - d[i];
                if (dd < 0) continue;
                double vv = sqrt(v[i] * v[i] + 2 * a[i] * dd);
                if (floor(vv) > V) {
                    double t = -(v[i] - V) * 1.0 / a[i];
                    double ss = d[i] + v[i] * t + 0.5 * a[i] * t * t;
                    int upp = lower_bound(p + 1, p + m + 1, floor(ss)) - p;
                    g[++cnt] = node{pos, upp - 1};
                }
            } else {
                if (v[i] <= V) continue;
                if (d[i] <= p[m]) {
                    int low = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    g[++cnt] = node{low, m};
                }
            }
        }
        sort(g + 1, g + cnt + 1, cmp);
        priority_queue<int, vector<int>, greater<int> > q;
        int ans = 0, t = 1, rr = INF;
        for (int i = 1; i <= m; ++i) {
            for (; t <= cnt; ++t) {
                if (g[t].l <= i) {
                    q.push(g[t].r);
                } else {
                    break;
                }
            }
            if (!q.empty() && q.top() == i) {
                ++ans;
                while (!q.empty() && q.top() >= i) q.pop();
            }
        }
        if (!q.empty()) {
            ++ans;
        }
        printf("%d %d\n", cnt, m - ans);
    }
    return 0;
}
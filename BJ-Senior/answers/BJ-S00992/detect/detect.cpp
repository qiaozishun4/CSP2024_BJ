#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 1e8;

ll n, m, l, V, d[maxn], v[maxn], a[maxn], p[maxn];
ll start[maxn], enxd[maxn], sx[maxn], ex[maxn];

struct GoIn {
    ll st, sx, ed, ex, i;
    GoIn () {}
    GoIn (ll _st, ll _sx, ll _ed, ll _ex, ll _i) {
        st = _st, sx = _sx, ed = _ed, ex = _ex, i = _i;
    }
    bool operator < (const GoIn &x) const {
        return st > x.st || (st == x.st && sx == 1);
    }
};

struct GoOut {
    ll st, sx, ed, ex, i;
    GoOut () {}
    GoOut (ll _st, ll _sx, ll _ed, ll _ex, ll _i) {
        st = _st, sx = _sx, ed = _ed, ex = _ex, i = _i;
    }
    GoOut (GoIn x) {
        st = x.st, sx = x.sx, ed = x.ed, ex = x.ex, i = x.i;
    }
    bool operator < (const GoOut &x) const {
        return ed > x.ed || (ed == x.ed && ex == 1);
    }
};

priority_queue <GoIn> q1;
priority_queue <GoOut> q2;

int dp[maxn];

void work () {
    // init start, enxd to -1 ##
    for (int i = 0; i < maxn; i ++) {
        start[i] = inf, enxd[i] = inf, sx[i] = 0, ex[i] = 0;
        dp[i] = 0;
    }
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();

    scanf("%lld%lld%lld%lld", &n, &m, &l, &V);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
        if (a[i] == 0) {
            if (v[i] > V) {
                start[i] = d[i];
            } else {
                // never overspeed
            }
        } else {
            ll x = (V * V - v[i] * v[i]) / (2ll * a[i]);
            bool z = (V * V - v[i] * v[i]) % (2ll * a[i]) != 0;
            if (a[i] > 0) {
                if (v[i] > V) {
                    start[i] = d[i];
                } else {
                    start[i] = x + d[i];
                    sx[i] = 1;
                }
            } else {
                if (v[i] > V) {
                    start[i] = d[i];
                    enxd[i] = d[i] + x - (z == 0);
                    ex[i] = (z == 0);
                } else {
                    // never overspeed
                }
            }
        }
        if (start[i] != inf) q1.push(GoIn(start[i], sx[i], enxd[i], ex[i], i));
    }
    for (int i = 1; i <= m; i ++) {
        scanf("%lld", &p[i]);
    }

    // test
    // for (int i = 1; i <= n; i ++) {
    //     if (sx[i]) printf("%lld+, ", start[i]);
    //     else printf("%lld, ", start[i]);
    //     if (ex[i]) printf("%lld+\n", enxd[i]);
    //     else printf("%lld\n", enxd[i]);
    // }
    // while (!q1.empty()) {
    //     printf("# %lld %lld\n", q1.top().st, q1.top().sx);
    //     q1.pop();
    // } return;

    int ans1 = 0;
    for (int i = 1; i <= m; i ++) {
        int comec = 0;
        while (!q1.empty()) {
            GoIn x = q1.top();
            if (x.st < p[i] || (x.st == p[i] && x.sx == 0)) {
                q1.pop();
                if (x.ed < p[i] || (x.ed == p[i] && x.ex == 0)) continue;
                q2.push(x);
                comec ++;
            } else {
                break;
            }
        }
        // printf ("[LOG] at %d, come %d\n", p[i], comec);
        int leftc = 0;
        while (!q2.empty()) {
            GoOut x = q2.top();
            if (x.ed < p[i] || (x.ed == p[i] && x.ex == 0)) {
                q2.pop();
                leftc ++;
            } else {
                break;
            }
        }
        ans1 += comec;
        // printf ("[LOG] at %d, left %d\n", p[i], leftc);
        for (int j = i; j >= 1; j --) {
            dp[j] = max(dp[j - 1] + comec, dp[j]);
        }
    }
    int ans2 = ans1;
    for (int i = m; i >= 1; i --) {
        // printf ("!%d %d\n", i, dp[i]);
        if (dp[i] == ans1) {
            ans2 = i;
            // break;
        }
    }
    printf("%d %d\n", ans1, m - ans2);
}

int main () {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        work();
    }
    return 0;
}
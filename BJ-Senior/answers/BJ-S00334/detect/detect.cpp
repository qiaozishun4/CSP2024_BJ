#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// #define dbg(...) fprintf(stderr, __VA_ARGS__)

const int MAXN = 1e5 + 5;
const int MAXL = 1e6 + 5;

int n, m, pl, vl, p[MAXN], tree[MAXL];
// bool del[MAXN];

struct Car {
    int d, v, a;
    double lim;
    inline void calc() { if (a != 0) lim = 1.0 * (vl * vl - v * v) / (2.0 * a) + d; }
} cs[MAXN];

inline int lowbit(int x) { return x & (-x); }

void update(int p, int v) {
    ++p;
    for (int i = p; i < MAXL; i += lowbit(i)) tree[i] += v;
}

int query(int p) {
    ++p;
    int ans = 0;
    for (int i = p; i > 0; i -= lowbit(i)) ans += tree[i];
    return ans;
}

inline int query(int l, int r) { return l > r ? 0 : query(r) - query(l - 1); }

inline int upper(double x) { return int(x + 1.0); }
inline int lower(double x) { return int(x - 0.00001); }

inline bool contains(pair<int, int> a, int x) { return a.first <= x && x <= a.second; }
inline bool contains(pair<int, int> a, pair<int, int> b) { return contains(a, b.first) && contains(a, b.second); }
inline bool havepublic(pair<int, int> a, pair<int, int> b) { return contains(a, b.first) || contains(b, a.first); }

void solve() {
    scanf("%d%d%d%d", &n, &m, &pl, &vl);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &cs[i].d, &cs[i].v, &cs[i].a);
        cs[i].calc();
    }
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &p[i]);
        update(p[i], 1);
    }
    int ans1 = 0, ans2 = 0;
    vector<pair<int, int> > rs;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        if (cs[i].a == 0) {
            // dbg("%d <= %d | s < %d\n", cs[i].v, vl, cs[i].d);
            if (cs[i].v <= vl) continue;
            l = cs[i].d;
            r = pl;
        } else {
            if (cs[i].a > 0) {
                // dbg("s <= %.15lf | s < %d\n", cs[i].lim, cs[i].d);
                l = max(upper(cs[i].lim), cs[i].d);
                r = pl;
            } else {
                // dbg("s >= %.15lf | s < %d\n", cs[i].lim, cs[i].d);
                l = cs[i].d;
                r = lower(cs[i].lim);
            }
        }
        if (query(l, r) > 0) {
            ++ans1;
            rs.push_back({ l, r });
        }
    }
    // memset(del, 0, sizeof(del));
    sort(rs.begin(), rs.end());
    // for (auto i : rs)
    //     dbg("[%d,%d]\n", i.first, i.second);
    // dbg("========\n");
    int la = -1;
    for (int i = 0; i < rs.size(); ++i) {
        if (la != -1) {
            if (contains(rs[la], rs[i])) {
                // del[la] = true;
                ++ans2;
                la = i;
                continue;
            } else if (havepublic(rs[la], rs[i])) {
                int pul = rs[i].first, pur = rs[la].second;
                if (query(pul, pur) > 0) {
                    // del[la] = true;
                    ++ans2;
                    rs[i] = { pul, pur };
                    la = i;
                    continue;
                }
            }
            if (rs[i].second > rs[la].second) la = i;
        } else {
            la = i;
        }
    }
    // for (int i = 0; i < rs.size(); ++i) {
    //     if (del[i]) continue;
    //     dbg("[%d,%d]\n", rs[i].first, rs[i].second);
    // }
    ans2 = m - rs.size() + ans2;
    printf("%d %d\n", ans1, ans2);
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
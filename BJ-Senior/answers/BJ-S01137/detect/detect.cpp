#include <bits/stdc++.h>
const int MAXN = 100005;
int n, m, L, V, p[MAXN], d[MAXN], v[MAXN], a[MAXN];
struct node {
    int l, r;
} seg[MAXN];

inline bool check(int v0, int a, int x, int V) {
    return 2*a*x + v0*v0 > V*V;
}

void solve1(int i) {
    seg[i].l = std::lower_bound(p + 1, p + m + 1, d[i]) - p;
    if(seg[i].l > m || !check(v[i], a[i], p[seg[i].l] - d[i], V)) {
        seg[i].l = 0, seg[i].r = m;
        return ;
    }
    int l = seg[i].l, r = m;
    while(l <= r) {
        int mid = (l + r)/2;
        if(check(v[i], a[i], p[mid] - d[i], V))
            l = mid + 1;
        else
            r = mid - 1;
    }
    seg[i].r = r;
}

void solve2(int i) {
    if(d[i] > p[m] || !check(v[i], a[i], p[m] - d[i], V)) {
        seg[i].l = 0, seg[i].r = m;
        return ;
    }
    seg[i].r = m;
    int l = std::lower_bound(p + 1, p + m + 1, d[i]) - p, r = m;
    while(l <= r) {
        int mid = (l + r)/2;
        if(check(v[i], a[i], p[mid] - d[i], V))
            r = mid - 1;
        else
            l = mid + 1;
    }
    seg[i].l = l;
}

inline bool cmp(const node &x, const node &y) {
    return x.r < y.r;
}

void solve() {
    scanf("%d%d%d%d", &n, &m, &L, &V);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d%d", &d[i], &v[i], &a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &p[i]);
    for(int i = 1; i <= n; ++i) {
        if(a[i] <= 0)
            solve1(i);
        else
            solve2(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += (seg[i].l == 0);
        //printf("%d %d\n", seg[i].l, seg[i].r);
    }
    printf("%d ", n - ans);
    std::sort(seg + 1, seg + n + 1, cmp);
    int last = 0, cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(last < seg[i].l)
            cnt++, last = seg[i].r;
    }
    printf("%d\n", m - cnt);
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}
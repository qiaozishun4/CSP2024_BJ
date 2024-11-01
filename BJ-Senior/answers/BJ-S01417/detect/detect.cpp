#include <stdio.h>
#include <algorithm>
#define ll long long
#define gc() getchar()
int rd() {
    int x = 0, f = 0;
    char c = gc();
    for (; c < '0' || c > '9'; c = gc())
        f ^= c == '-';
    for (; c >= '0' && c <= '9'; c = gc())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return f ? -x : x;
}
#define pc(c) putchar(c)
void wt(int x) {
    if (x >= 10) wt(x / 10);
    pc(x % 10 ^ '0');
}
#define N 100005
int n, m, L, V, d[N], v[N], a[N], p[N];
struct node {
    int l, r;
} t[N];
bool cmp(node a, node b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}
int ubd(int x) {//进入后第一个监控
    int l = 1, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (p[mid] >= d[x]) r = mid - 1;
        else if (p[mid] < d[x]) l = mid + 1;
    }
    return l;
}
int upbd(int x) {//a[i]>=0 时第一个判断超速的监控
    int l = ubd(x), r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        long long dif = 2ll * a[x] * (p[mid] - d[x]) - (1ll * V * V - 1ll * v[x] * v[x]);
        if (dif > 0) r = mid - 1;
        else if (dif <= 0) l = mid + 1;
    }
    return l;
}
int lwbd(int x) {//a[i]<0 时最后一个判断超速的监控
    int l = ubd(x), r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        long long dif = 2ll * a[x] * (p[mid] - d[x]) - (1ll * V * V - 1ll * v[x] * v[x]);
        if (dif <= 0) r = mid - 1;
        else if (dif > 0) l = mid + 1;
    }
    return r;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T = rd();
    while (T--) {
        n = rd(), m = rd(), L = rd(), V = rd();
        for (int i = 1; i <= n; i++)
            d[i] = rd(), v[i] = rd(), a[i] = rd();
        for (int i = 1; i <= m; i++)
            p[i] = rd();
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int L = 0, R = 0;
            if (a[i] > 0)
                L = upbd(i), R = m;
            else if (a[i] == 0) {
                if (v[i] > V) L = ubd(i);
                else L = m + 1;
                R = m;
            }
            else if (a[i] < 0)
                L = ubd(i), R = lwbd(i);
            if (L <= R) t[++cnt].l = L, t[cnt].r = R;
        }
        wt(cnt), pc(' ');
        std::sort(t + 1, t + 1 + cnt, cmp);
        int ans = 0;
        for (int i = 1; i <= cnt; ) {
            int j = i, mnr = t[i].r;
            while (t[j].l <= mnr && j <= cnt) {
                j++;
                if (t[j].r < mnr) mnr = t[j].r;
            }
            i = j, ans++;
        }
        wt(m - ans), pc('\n');
    }
    return 0;
}
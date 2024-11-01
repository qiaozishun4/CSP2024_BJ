#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
    while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    if (f) x = -x;
}
template <typename T> inline void write(const T &x) {
    if (x < 0) return write(-x);
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
const int N = 1e5 + 5;
int T, n, m, L, V, d[N], v[N], a[N], p[N];
struct node {
    int lf, rt;
    inline bool operator < (const node &cmp) const {
        return rt < cmp.rt;
    }
} c[N];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    read(T);
    while (T--) {
        read(n), read(m), read(L), read(V);
        for (int i = 1; i <= n; i++)
            read(d[i]), read(v[i]), read(a[i]);
        for (int i = 1; i <= m; i++)
            read(p[i]);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0) {
                if (v[i] > V) {
                    int l = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    int r = lower_bound(p + 1, p + m + 1, ceil((v[i] * v[i] - V * V) / 2.0 / -a[i]) + d[i]) - p - 1;
                    if (l <= r) {
                        cnt++;
                        c[cnt].lf = l;
                        c[cnt].rt = r;
                    }
                }
            }
            else if (a[i] == 0) {
                if (v[i] > V) {
                    int l = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    int r = m;
                    if (l <= r) {
                        cnt++;
                        c[cnt].lf = l;
                        c[cnt].rt = r;
                    }
                }
            }
            else { // a[i] > 0
                if (v[i] > V) {
                    int l = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    int r = m;
                    if (l <= r) {
                        cnt++;
                        c[cnt].lf = l;
                        c[cnt].rt = r;
                    }
                }
                else { // v[i] <= V
                    int l = upper_bound(p + 1, p + m + 1, d[i] + (V * V - v[i] * v[i]) / (2 * a[i])) - p;
                    int r = m;
                    if (l <= r) {
                        cnt++;
                        c[cnt].lf = l;
                        c[cnt].rt = r;
                    }
                }
            }
        }
        write(cnt), putchar(' ');
        sort(c + 1, c + cnt + 1);
        int lst = 0, ans = 0;
        for (int i = 1; i <= cnt; i++) {
            if (c[i].lf <= lst) continue;
            ans++, lst = c[i].rt;
        }
        write(m - ans), putchar('\n');
    }
    return 0;
}

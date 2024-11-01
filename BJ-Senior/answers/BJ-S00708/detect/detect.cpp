#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e5, MAXL = 1e6;
const ld EPS = 0;
ll t, n, m;
ld L, V;
ld d[MAXN + 5], v[MAXN + 5], a[MAXN + 5], p[MAXN + 5];
struct Node {
    ll l, r;
    inline bool operator<(const Node &tmp) const {
        if (r == tmp.r) return l < tmp.l;
        return r < tmp.r;
    }
} node[MAXN + 5];
inline ll read() {
    ll opt = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') opt = -1;
        c = getchar_unlocked();
    }
    while (isdigit(c)) {
        num = num * 10 + c - '0';
        c = getchar_unlocked();
    }
    return opt * num;
}
void write(ll num) {
    if (num >= 10) write(num / 10);
    putchar('0' + num % 10);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    t = read();
    while (t--) {
        n = read(), m = read(), L = ld(read()), V = ld(read());
        for (register ll i = 1; i <= n; i++) d[i] = ld(read()), v[i] = ld(read()), a[i] = ld(read());
        for (register ll i = 1; i <= m; i++) p[i] = ld(read());
        sort(p + 1, p + m + 1);
        ll ans1 = 0;
        for (register ll i = 1; i <= n; i++) {
            if (a[i] == 0) {
                if (v[i] > V) {
                    node[++ans1].l = -1;
                    ll l = 1, r = m;
                    while (l <= r) {
                        ll mid = l + r >> 1;
                        if (p[mid] >= d[i]) node[ans1].l = mid, r = mid - 1;
                        else l = mid + 1;
                    }
                    if (node[ans1].l != -1) node[ans1].r = m;
                    else ans1--;
                }
            } else if (a[i] > 0) {
                ld dis = p[m] - d[i];
                if (dis < 0) continue;
                ld tmpv = sqrtl(v[i] * v[i] + 2.0 * a[i] * dis);
                if (tmpv + EPS > V) {
                    node[++ans1].l = -1;
                    ll l = 1, r = m;
                    while (l <= r) {
                        ll mid = l + r >> 1;
                        dis = p[mid] - d[i];
                        if (dis < 0) {
                            l = mid + 1;
                            continue;
                        }
                        tmpv = sqrtl(v[i] * v[i] + 2.0 * a[i] * dis);
                        if (tmpv + EPS > V) node[ans1].l = mid, r = mid - 1;
                        else l = mid + 1;
                    }
                    if (node[ans1].l != -1) node[ans1].r = m;
                    else ans1--;
                }
            } else {
                ll l = 1, r = m, res1 = -1;
                while (l <= r) {
                    ll mid = l + r >> 1;
                    if (p[mid] >= d[i]) res1 = mid, r = mid - 1;
                    else l = mid + 1;
                }
                if (res1 == -1) continue;
                l = res1, r = m;
                ll res2 = -1;
                while (l <= r) {
                    ll mid = l + r >> 1;
                    ld dis = p[mid] - d[i];
                    ld tmpv = sqrtl(v[i] * v[i] + 2.0 * a[i] * dis);
                    if (tmpv + EPS > V) res2 = mid, l = mid + 1;
                    else r = mid - 1;
                }
                if (res2 == -1) continue;
                node[++ans1].l = res1;
                node[ans1].r = res2;
            }
        }
        write(ans1); putchar(' ');
        if (ans1 == 0) {
            write(m); putchar('\n');
            continue;
        }
        sort(node + 1, node + ans1 + 1);
        ll lst = 1, ans2 = 1;
        for (register ll i = 2; i <= ans1; i++) {
            if (node[i].l > node[lst].r) ans2++, lst = i;
        }
        write(m - ans2); putchar('\n');
    }
    return 0;
}

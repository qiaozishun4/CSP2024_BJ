#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1, ch = getchar();
    while (!(ch == '-' || isdigit(ch))) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f == 1 ? x : -x;
}
#define ll long long
const int maxn = 1e5 + 10;
ll n, m, L, V, p[maxn];
struct Car {
    ll d, v, a;
} car[maxn];
struct Seg {
    int l, r;
    bool operator < (const Seg & o) const {
        return r < o.r;
    }
} seg[maxn];
void init() {
    n = read(); m = read(); L = read(); V = read();
    for (int i = 1; i <= n; i++) car[i].d = read(), car[i].v = read(), car[i].a = read();
    for (int i = 1; i <= m; i++) p[i] = read();
}
void solve() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (car[i].d > p[m]) continue;

        if (car[i].a == 0) {
            if (car[i].v <= V) continue;
            int id = lower_bound(p + 1, p + m + 1, car[i].d) - p;
            cnt++;
            //assert(id <= m);
            seg[cnt] = Seg({id, (int)m});
        } else if (car[i].a > 0) {
            ll s = p[m] - car[i].d;
            if (car[i].v * car[i].v + s * car[i].a * 2 > V * V) {
                cnt++;
                int st;
                if (car[i].v > V) st = lower_bound(p + 1, p + m + 1, car[i].d) - p;
                else {
                    ll s = ((ll)V * V - (ll)car[i].v * car[i].v) / 2.0 / car[i].a - 2;
                    s = max(s, (ll)0);
                    while (s * car[i].a * 2 <= (ll)V * V - (ll)car[i].v * car[i].v) s++;
                    st = lower_bound(p + 1, p + m + 1, car[i].d + s) - p;
                }
                //assert(st <= m);
                seg[cnt] = Seg({st, (int)m});
            }
        } else {
            if (car[i].v <= V) continue;
            int id = lower_bound(p + 1, p + m + 1, car[i].d) - p;
            ll s = -(ll)car[i].v * car[i].v / 2.0 / car[i].a + 2;
            while (s * car[i].a * 2 < -(ll)car[i].v * car[i].v) s--;
            if (car[i].d + s < p[id]) continue;
            ll t = p[id] - car[i].d;
            if (V * V < car[i].v * car[i].v + t * car[i].a * 2) {
                cnt++;
                ll r = (V * V - car[i].v * car[i].v) / 2.0 / car[i].a + 2;
                while (r * car[i].a * 2 <= V * V - car[i].v * car[i].v) r--;
                int ed = upper_bound(p + 1, p + m + 1, car[i].d + r) - p;
                //assert(id <= ed - 1);
                seg[cnt] = Seg({id, ed - 1});
            }
        }
    }
    cout << cnt << " ";
    sort(seg + 1, seg + cnt + 1);
    int ans = m, cur = -1;
    for (int i = 1; i <= cnt; i++)
        if (cur < seg[i].l) {
            ans--;
            cur = seg[i].r;
        }
    cout << ans << "\n";
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t = read();
    while (t--) {
        init();
        solve();
    }
    return 0;
}


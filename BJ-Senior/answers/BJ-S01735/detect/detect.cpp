#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

struct car {
    ll d, v, a;
    ll l, r;
};

car r[3005];
ll p[3005];
ll p_x[3005];

ld core(ll vt, ll v0, ll a) {
    if ((vt * vt - v0 * v0) % (2 * a) == 0) return (vt * vt - v0 * v0) / (2 * a);
    return ((ld)vt * vt - v0 * v0) / (2 * a);
}

car calc(car c, ll len, ll maxv) {
    if (c.a == 0) {
        if (c.v <= maxv) c.l = c.r = -1;
        else {
            c.l = c.d, c.r = len;
        }
    } else if (c.a < 0) {
        ll f = c.d + ceil(core(maxv, c.v, c.a)) - 1;
        if (c.d > f) c.l = c.r = -1;
        else {
            c.l = c.d;
            c.r = f;
        }
    } else {
        ll f = c.d + floor(core(maxv, c.v, c.a)) + 1;
        if (f > len) c.l = c.r = -1;
        else {
            c.l = f;
            c.r = len;
        }
    }
    return c;
}

ll count1(ll x) {
    ll c = 0;
    for (ll i = 0; i <= 22; i++) {
        if ((x >> i) & 1) c++;
    }
    return c;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ll t;
    ll n, m, len, maxv;
    cin >> t;
    while (t--) {
        cin >> n >> m >> len >> maxv;
        for (ll i = 1; i <= n; i++) {
            cin >> r[i].d >> r[i].v >> r[i].a;
        }
        for (ll i = 1; i <= m; i++) {
            cin >> p[i];
            p_x[i] = 0;
        }
        for (ll i = 1; i <= n; i++) {
            r[i] = calc(r[i], len, maxv);
            for (ll j = 1; j <= m; j++) {
                if (r[i].l <= p[j] && p[j] <= r[i].r) {
                    p_x[j] |= 1 << (i - 1);
                }
            }
        }
        ll fnl = 0;
        for (ll i = 1; i <= m; i++) {
            fnl |= p_x[i];
        }
        ll ans1 = count1(fnl), ans2 = 0;
        ll t = 1 << n, fx;
        for (ll k = 0; k < t; k++) {
            fx = 0;
            for (ll i = 1; i <= m; i++) {
                if ((k >> (i - 1)) & 1) {
                    fx |= p_x[i];
                }
            }
            if (fx == fnl) ans2 = max(ans2, m - count1(k));
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
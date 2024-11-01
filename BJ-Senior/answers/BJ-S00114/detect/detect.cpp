#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 100005;
int p[N];
struct Carp {
    int l, r;
}carp[N];
int n, m, L, V;
struct Car {
    int d, v, a;
} cr[N];
bool cmp(Carp x, Carp y) {
    if ( x.r != y.r) {
        return x.r < y.r;
    }
    return x.l <= y.l;
}
int Cal() {
    int a0, d0, v0;
    int s;
    int ret = 0;
    for ( int i = 1; i <= n; i++) {
        a0 = cr[i].a;
        d0 = cr[i].d;
        v0 = cr[i].v;
        if ( a0 == 0) {
            if ( v0 > V) {
                carp[i].l = lower_bound(p + 1, p + m + 1, d0) - p;
                carp[i].r = m;
            } 
            else {
                carp[i].l = carp[i].r = 0;
            }
        }
        else if ( a0 > 0) {
            s = (V * V - v0 * v0) / (2 * a0);
            s += d0;
            if ( s + 1 > p[m]) {
                carp[i].l = carp[i].r = 0;
            }
            else {
                //>=s+1junke
                carp[i].l = lower_bound(p + 1, p + m + 1, max(s + 1, 0)) - p;
                carp[i].r = m;
            }
        }
        else {
            s = (V * V - v0 * v0) / (2 * a0);
            if ( s * 2 * a0 == V * V - v0 * v0) {
                s--;
            }
            s += d0;
            if ( s < p[1]) {
                carp[i].l = carp[i].r = 0;
            }
            else {
                //<=sjunke
                carp[i].r = upper_bound(p + 1, p + m + 1, min(s, L)) - p;
                carp[i].r--;
                carp[i].l = lower_bound(p + 1, p + m + 1, d0) - p;
                if ( carp[i].l > carp[i].r) {
                    carp[i].l = carp[i].r = 0;
                }
            }
        }
    }
    for ( int i = 1; i <= n; i++) {
      //  cout << carp[i].l << " " << carp[i].r << endl;
        if ( carp[i].l > 0 && carp[i].r > 0) {
           ret++;
        }
    }
    return ret;
}
int F() {
    int ret = 0;
    sort(carp + 1, carp + n + 1, cmp);
    int rec = 0;
    for ( int i = 1; i <= n; i++) {
        if ( carp[i].l != 0 && carp[i].r != 0) {
            if ( carp[i].l > rec) {
                rec = carp[i].r;
                ret++;
            }
        }
    }
    return ret;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t, ans1 = 0, ans2 = 0;
    cin >> t;
    while ( t--) {
        ans1 = 0;
        ans2 = 0;
        cin >> n >> m >> L >> V;
        for ( int i = 1; i <= n; i++) {
            cin >> cr[i].d >> cr[i].v >> cr[i].a;
        }
        for ( int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        ans1 = Cal();
        ans2 = m - F();
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
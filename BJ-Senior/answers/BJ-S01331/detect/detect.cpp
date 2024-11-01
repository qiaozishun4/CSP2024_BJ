#include<bits/stdc++.h>
using namespace std;

const int maxN = int(1e5) + 10;
int vp[maxN], vs[maxN], ve[maxN];
int t, n, m, l, maxv, ttl, cnt;

void init_car(int& s, int&e) {
    int d, v, a;
    double tt, ev;
    cin >> d >> v >> a;
    if (a == 0) {
        if (v <= maxv) {
            s=e=l+1;
        } else {
            s=d; e=l;
        }
    } else if (a > 0) {
        if (v > maxv) {
            s=d; e=l;
        } else {
            ev = sqrt(double(v)*v + 2.0*a*(l-d));
            if (ev<=maxv) {
                s=e=l+1;
            } else {
                tt = double(maxv - v) / a;
                s = d + int(v*tt + 0.5*a*tt*tt) + 1;
                e = l;
            }
        }
    } else if (a < 0) {
        if (v <= maxv) {
            s=e=l+1;
        } else {
            s = d;
            ev = sqrt(double(v)*v + 2.0*a*(l-d));
            if (ev > maxv) {
                e = l;
            } else {
                tt = double(maxv - v) / a;
                e = d + int(v*tt + 0.5*a*tt*tt);
            }
        }
    }
    return;
}

void proc_ab () {
    int ttl = 0;
    for (int ii=0 ; ii<n ; ++ii) {
        if (vs[ii] <= vp[m-1]) { ++ttl; }
    }
    cout << ttl << " " << (ttl>0 ? m-1 : m) << endl;
    return;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int ii, jj, ttl, cnt;
    int min_e;
    cin >> t;
    while (t>0) {
        --t;
        cin >> n >> m >> l >> maxv;
        min_e = l; ttl = 0;
        for (ii=0 ; ii<n ; ++ii) {
            init_car(vs[ii], ve[ii]);
            min_e = min(min_e, ve[ii]);
        }
        for (ii=0 ; ii<m ; ++ii) {
            cin >> vp[ii];
        }
        if (min_e == l) {
            proc_ab();
        } else {
            cout << "TODO";
        }
    }

    return 0;
}

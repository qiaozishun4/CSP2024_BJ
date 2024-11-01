#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,L,V;
int l[100005],r[100005],v[100005],a[100005],p[100005];
bool b[100005];
inline int ef1 (int d) {//first >= d de.
    int ll = 1,rr = m;
    while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (p[mid] >= d) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }
    return ll;
}
inline int ef2 (int d) {//last <= d de.
    int ll = 1,rr = m;
    while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (p[mid] > d) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }
    return rr - 1;
}
signed main () {
    freopen("delect.in","r",stdin);
    freopen("delect.out","w",stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> L >> V;
        for (int i = 1;i <= n;i++) {
            cin >> l[i] >> v[i] >> a[i];
            int s = L - l[i];
            int v1 = v[i] * v[i] + 2 * a[i] * s;
            if (v1 >= 0) {
                r[i] = L;
            } else {
                int rit = -v[i] * v[i] / 2 / a[i];
                r[i] = rit;
            }
        }
        for (int i = 1;i <= m;i++) {
            cin >> p[i];
        }
        sort(p + 1,p + n + 1);
        for (int i = 1;i <= n;i++) {
            b[i] = 0;
            int pl,pr;
            pl = ef1(l[i]);
            pr = ef2(r[i]);
            if (pl <= pr) {
                if (a[i] > 0) {
                    int s = pr - l[i];
                    int v2 = v[i] * v[i] - 2 * a[i] * s;
                    if (V * V < v2) {
                        b[i] = 1;
                    }
                } else {
                    int s = pl - l[i];
                    int v2 = v[i] * v[i] - 2 * a[i] * s;
                    if (V * V < v2) {
                        b[i] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1;i <= n;i++) {
            cout << l[i] << ' ' << r[i] << endl;
            ans += b[i];
        }
        cout << ans << endl;
    }
    return 0;
}
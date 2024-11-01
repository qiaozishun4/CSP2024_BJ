#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int T;
int n, m, L, V;
struct node {
    int d, v, a;
}a[N];
int p[N];
struct nd {
    int l, r;
}w[N];

int erf1 (int x) {
    int l = 1, r = m, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (p[mid] >= x) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

int erf2 (int x) {
    int l = 1, r = m, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (p[mid] <= x) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

bool cmp (nd a, nd b) {
    if (a.l == b.l) {
        return a.r < b.r;
    }
    return a.l < b.l;
}

bool vis[N];

signed main () {
    freopen ("detect.in", "r", stdin);
    freopen ("detect.out", "w", stdout);

    cin >> T;
    while (T -- ) {
        cin >> n >> m >> L >> V;
        int ans = 0;
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i].d >> a[i].v >> a[i].a;
            //cout << a[i].d << " " << a[i].v << " " << a[i].a << endl;
        }

        for (int i = 1; i <= m; i ++ ) {
            cin >> p[i];
            //cout << p[i] << endl;
        }
        bool calc = false;
        queue <int> q;
        for (int i = 1; i <= n; i ++ ) {
            if (a[i].a >= 0) {
                //cout << a[i].a << " " << a[i].v << " " << a[i].d << endl;
                //cout << V << " " << p[m] << endl;
                calc = true;
                if (a[i].a == 0 && a[i].v > V && a[i].d <= p[m]) {
                    ans ++;
                    vis[i] = true;
                    continue;
                }
                else if (a[i].a == 0) continue;
                //cout << i << endl;
                if (a[i].d <= p[m] && V * V < 2 * a[i].a * (p[m] - a[i].d) + a[i].v * a[i].v) {
                        vis[i] = true;
                    ans ++ ;
                }
            }
            else {
                q.push (i);
            }
        }
        //cout << ans << endl;
        if (q.empty()) {
            if (ans == 0) cout << "0 " << m << endl;
            else cout << ans << " " << m - 1 << endl;
            continue;
        }
        int cnt = 0;
        while (!q.empty()) {
            int fr = q.front(); q.pop();
            int nfr = a[fr].d + ((a[fr].v * a[fr].v) / (2 * (-a[fr].a)));
            int l = erf1 (a[fr].d);
            int r = erf2 (nfr);
           // cout << l << " " << r << endl;
            if (p[l] > nfr) continue;
            int nl = l, nr = r, nans = -1;
            while (nl <= nr) {
                int mid = nl + nr >> 1;
                if ( (a[fr].v*a[fr].v) +  2 * a[fr].a * (p[mid] - a[fr].d) > V * V) {
                    nans = mid;
                    nl = mid + 1;
                }
                else nr = mid - 1;
            }
            if (nans == -1) continue;
            else {
               // cout << l << " " << nans << endl;
                ans ++ ;
                w[++cnt].l = l;
                w[cnt].r = nans;
            }
        }
        //cout << ans << endl;
        sort (w + 1, w + cnt + 1, cmp);

        int maxr = w[1].r;
        int maxansr = w[1].r;
        int tmpl = w[1].l;
        int res = 1;
        for (int i = 2; i <= cnt; i ++ ) {
            if (w[i].l == w[i - 1].l && w[i].r == w[i - 1].r) continue;
            if (w[i].l <= maxr) {
                if (w[i].l <= maxansr) {
                    if (w[i].r <= maxansr) {
                        maxansr = w[i].r;
                    }
                    else if (w[i].r <= maxr) {
                        continue;
                    }
                    else {
                        maxr = w[i].r;
                    }
                }
                else {
                    if (w[i].r <= maxr) {
                        res ++;
                   //     cout << "p1 " << i << endl;
                        maxansr = w[i].r;
                    }
                    else {
                        res ++ ;
                   //     cout << "p2 " << i << endl;
                        maxansr = w[i].r;
                        maxr = w[i].r;
                    }
                }
            }
            else {
                res ++ ;
              //  cout << "p3 " << i << endl;
                maxansr = w[i].r;
                maxr = w[i].r;
            }
        }
       // cout << res << endl;
        //cout << maxansr << " " << m << endl;
      //  cout << calc << endl;
        if (calc && maxansr != m) {
            bool ch = false;
            for (int i = 1; i <= n; i ++ ) {
                if (a[i].a >= 0) {
                    //cout << a[i].a << " " << a[i].v << " " << a[i].d << endl;
                    //cout << V << " " << p[maxansr] << endl;
                    if (a[i].a == 0 && a[i].v > V && a[i].d <= p[maxansr]) {
                        continue;
                    }
                    else if (a[i].a == 0 && vis[i] == true) {
                        ch = true;
                        break;
                    }
                    else if (a[i].a == 0) continue;
                    //cout << i << endl;
                    if (a[i].d <= p[maxansr] && V * V < 2 * a[i].a * (p[maxansr] - a[i].d) + a[i].v * a[i].v) {
                        continue;
                    }
                    else if (vis[i] == true){
                        ch = true;
                        break;
                    }
                }
                else {
                    continue;
                }
            }
            if (ch) cout << ans << " " << m - res - 1 << endl;
            else cout << ans << " " << m - res << endl;
        }
        else cout << ans << " " << m - res << endl;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;
int n, m, l, v;
int d[N], vi[N], a[N], p[N], le[N], ri[N], cnt;
struct nd {
    int lef, rig;
    bool operator < (const nd b) const {
        if (rig != b.rig) return rig < b.rig;
        return lef < b.lef;
    }
} pt[N];
signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(d, 0, sizeof(d));
        memset(vi, 0, sizeof(vi));
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        cnt = 0;
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> vi[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        int acnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0 && vi[i] > v) {
                int ndist = (vi[i] * vi[i] - v * v) / (2 * (-a[i]));
                int tdist = ndist + d[i];
                if (ndist * (2 * (-a[i])) == vi[i] * vi[i] - v * v) tdist--;
                if (tdist > l) tdist = l;
                int pos1 = lower_bound(p + 1, p + m + 1, d[i]) - p;
                int pos2 = upper_bound(p + 1, p + m + 1, tdist) - p - 1;
                if (pos1 == m + 1 || pos2 == 0 || pos1 > pos2) continue;
                le[++cnt] = pos1, ri[cnt] = pos2, acnt++;
            } else if (a[i] > 0) {
                int ndist = (v * v - vi[i] * vi[i]) / (2 * a[i]) + 1;
                if (vi[i] > v) ndist = 0;
                int tdist = ndist + d[i];
                if (tdist > l) continue;
                int pos1 = lower_bound(p + 1, p + m + 1, tdist) - p, pos2 = m;
                if (pos1 == m + 1 || pos1 > pos2) continue;
                le[++cnt] = pos1, ri[cnt] = pos2, acnt++;
            } else if (a[i] == 0) {
                if (vi[i] > v) {
                    int pos1 = lower_bound(p + 1, p + m + 1, d[i]) - p, pos2 = m;
                    if (pos1 == m + 1 || pos1 > pos2) continue;
                    le[++cnt] = pos1, ri[cnt] = pos2, acnt++;
                }
            }
        }
        for (int i = 1; i <= cnt; i++) {
            pt[i].lef = le[i], pt[i].rig = ri[i];
        }
        sort(pt + 1, pt + cnt + 1);
        int lst = -1, ans = 0;
        for (int i = 1; i <= cnt; i++) {
            if (lst < pt[i].lef) {
                lst = pt[i].rig, ans++;
            }
        }
        cout << acnt << ' ' << (m - ans) << '\n';
    }
    return 0;
}

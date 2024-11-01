// Zhang Yixun
// CSP-S T2 detect


#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+5;
struct Car {
    int d, v, a;
} c[N];
int p[N];
int n, m, L, V;
bool over[N];
int nd[N];


signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> L >> V;
        bool caseA = true, caseB = true, caseC = true;
        for (int i = 1; i <= n; i++) {
            cin >> c[i].d >> c[i].v >> c[i].a;
            over[i] = false;
            if (c[i].a > 0) caseA = caseC = false;
            if (c[i].a < 0) caseA = caseB = false;
        }
        for (int i = 1; i <= m; i++)
            cin >> p[i], nd[i] = 0;
        // for (int i = 1; i <= L; i++)
        //     cnt[i] += cnt[i-1];
        int ans1 = 0;
        for (int i = 1; i <= n; i++) {
            int d = c[i].d, v = c[i].v, a = c[i].a;
            int l, r;
            if (a == 0) {
                if (v > V)
                    l = d, r = L+1;
                else
                    l = r = L+1;
            }
            else if (a > 0) {
                if (v > V)
                    l = d, r = L+1;
                else {
                    double t = 1.0 * (V - v) / a;
                    double s = 1.0 * v * t + 0.5 * a * t * t;
                    l = min(L+1, (long long)(d + s)+1), r = L+1;
                }
            }
            else {
                if (v > V) {
                    double t = 1.0 * (V - v) / a;
                    double s = 1.0 * v * t + 0.5 * a * t * t;
                    l = d, r = min(L+1, (long long)ceil(d + s)-1);
                }
                else
                    l = L+1, r = L+1;
            }
            int pos1 = lower_bound(p+1, p+1+m, l) - p;
            int pos2 = lower_bound(p+1, p+1+m, r) - p;
            if (pos1 < pos2)
                ans1++, over[i] = true;
            if (pos2 > m || p[pos2] > r) pos2--;
            if (over[i]) {
                nd[pos1]++, nd[pos2+1]--;
            }
        }
        cout << ans1 << ' ';
        for (int i = 1; i <= m; i++)
            nd[i] += nd[i-1];
        int ans2 = 0;
        for (int i = 2; i <= m; i++) {
            if (nd[i] < nd[i-1])
                ans2++;
        }
        if (ans1 == 0) ans2--;
        cout << m - ans2 - 1 << endl;
    }
    return 0;
}
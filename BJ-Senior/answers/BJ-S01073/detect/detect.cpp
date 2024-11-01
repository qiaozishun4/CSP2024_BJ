#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
double d[N], v[N], a[N], p[N];
int res[N], tot;
bool res2[N];

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        tot = 0;
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) cin >> p[i];
        sort(p + 1, p + m + 1);
        for (int i = 1; i <= n; i++) {
            if (d[i] > p[m]) continue;
            if (a[i] == 0 && v[i] > V) {
                res[++tot] = i;
                continue;
            }
            if (a[i] < 0) {
                int t = lower_bound(p + 1, p + m + 1, d[i]) - p;
                double t1 = (double)v[i] * v[i] + 2.0 * a[i] * (p[lower_bound(p + 1, p + m + 1, d[i]) - p] - d[i]);
                if (t1 <= 0) continue;
                if (sqrt(t1) > 1.0 * V) {
                    res[++tot] = i;
                    res2[t] = true;
                    continue;
                }
                continue;
            }
            double t2 = (double)v[i] * v[i] + 2.0 * a[i] * (p[m] - d[i]);
            if (t2 <= 0) continue;
            if (sqrt(t2) > 1.0 * V) {
                res[++tot] = i;
                res2[m] = true;
            }
        }
        cout << tot << " ";
        if (tot == 0) {
            cout << m;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) if (res2[i]) ans++;
        if (ans) cout << m - ans;
        else cout << m - 1;
        cout << endl;
    }
    return 0;
}
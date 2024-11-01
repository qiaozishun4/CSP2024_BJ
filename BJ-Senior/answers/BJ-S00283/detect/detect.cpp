#include <bits/stdc++.h>
using namespace std;
int T, n, m, L, V, d[100005], v[100005], a[100005], p[100005];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> m >> L >> V;
        int ans = 0, A = 1, B = 1;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] != 0)
                A = 0;
            if (a[i] <= 0)
                B = 0;
        }
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        if (A) {
            for (int i = 1; i <= n; i++)
                if (d[i] <= p[m])
                    if (v[i] > V)
                        ans++;
            if (ans >= 1)
                cout << ans << " " << m - 1 << endl;
            else
                cout << "0 " << m << endl;
        } else if (B) {
            for (int i = 1; i <= n; i++)
                if (d[i] <= p[m])
                    if (sqrt(v[i] * v[i] + 2 * a[i] * (p[m] - d[i])) > V)
                        ans++;
            if (ans >= 1)
                cout << ans << " " << m - 1 << endl;
            else
                cout << "0 " << m << endl;
        }
    }
    return 0;
}

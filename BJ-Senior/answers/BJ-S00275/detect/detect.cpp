#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int v[100005] = {}, cnt = 0, a[100005] = {};
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        int d[100005] = {}, p[100005] = {};
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) {
            int s = p[m] - d[i];
            if (p[m] >= d[i] && sqrt(v[i] * v[i] + 2.0 * a[i] * s) > V) cnt++;
        }
        if (cnt == 0) cout << cnt << " " << m << "\n";
        else cout << cnt << " " << m - 1 << "\n";
    }
    return 0;
}

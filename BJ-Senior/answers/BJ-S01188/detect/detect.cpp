#include <bits/stdc++.h>

using namespace std;

int T, n, m, l, v2, s, cnt;
int d[100005], v[100005], a[100005], p[100005];
double tmp;

void solve() {
    cnt = 0;
    cin >> n >> m >> l >> v2;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> v[i] >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            if (v[i] > v2) cnt++;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            s = p[j] - d[i];
            tmp = sqrt(v[i] * v[i] + 2 * a[i] * s);
            if (tmp > v2) cnt++;
        }
    }
    cout << n << " " << n << "\n";
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) solve();

    return 0;
}

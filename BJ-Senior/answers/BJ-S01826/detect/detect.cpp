#include <bits/stdc++.h>
using namespace std;
struct Car {int d, v, a;};
Car car[100005];
int p[100005], isd[1000005], isp[100005], d[100005], n, m, l, v;
double Speed(int a, int b, int t) {
    double s = a * t + 0.5 * b * t * t;
    double speed = sqrt(a * a + 2 * b * s);
    return speed;
}
void SolveA() {
    int ans = 0, ans2 = 0;
    memset(isd, 0, sizeof isd);
    memset(isp, 0, sizeof isp);
    for (int i = 1; i <= n; i++) isd[car[i].d]++;
    for (int i = 1; i <= m; i++) isp[p[i]]++;
    for (int i = 1; i <= n; i++) if (isp[car[i].d] && car[i].v > v) ans++;
    for (int i = 1; i <= m; i++) if (!isd[i] || (isd[i] && car[i].v <= v)) ans2++;
    cout << ans << ' ' << ans2 << endl;
}
void SolveB() {
    int ans = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        int pos = m;
        if (p[pos] >= car[i].d) {
            double speed = Speed(car[i].v, car[i].a, p[pos] - car[i].d);
            if (speed > v) ans++;
        }
    }

    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; i++) d[i] = car[i].d;
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= m; i++) {
        int pos = upper_bound(d + 1, d + n + 1, p[i]) - d - 1;
        if (pos < 1 || pos > n || d[pos] > p[i]) ans2++;
    }
    cout << ans << ' ' << ans2 + (n - ans) << endl;

}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++) cin >> car[i].d >> car[i].v >> car[i].a;
        for (int i = 1; i <= m; i++) cin >> p[i];
        sort(p + 1, p + m + 1);
        if (car[1].a == 0) SolveA();
        else if (car[1].a > 0) SolveB();
        else cout << 0 << ' ' << m << endl;
    }
    return 0;
}

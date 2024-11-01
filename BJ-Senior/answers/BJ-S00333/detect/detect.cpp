#include <iostream>
using namespace std;

int T;
int n, m, L, V;
int d[100005], v[100005], a[100005], p[100005];
int ans1, ans2;
bool f[100005];

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
            cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                f[i] = f[i] || (v[i]*v[i]+2*a[i]*p[j]>V*V);
        for (int i = 1; i <= n; i++)
            ans1 += f[i];
        ans2 = m - 2;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}

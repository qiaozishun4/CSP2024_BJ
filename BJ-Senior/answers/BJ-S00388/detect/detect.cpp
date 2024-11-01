#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int d[N], v[N], a[N], p[N];
void solve()
{
    int n, m, l, V, msl = 0, met = 0x7f7f7f7f, ms = 0;
    cin >> n >> m >> l >> V;
    for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i], met = min(met, d[i]), ms = max(ms, v[i]);
    for (int i = 1; i <= m; i++) cin >> p[i], msl = max(msl, p[i]);
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) 
        if (d[i] <= msl && a[i] >= V) ans1++;
    for (int i = 1; i <= m; i++)
        if (p[i] < met || ms <= V) ans2++;
    cout << ans1 << " " << ans2 << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
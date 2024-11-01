#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll t, n, m, L, V, d[N], v[N], a[N], p[N];

void solve1()
{
    ll mx = 0;
    for (int i = 1; i <= m; i ++)
        mx = max (mx, p[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        if (v[i] > V && d[i] <= mx) ans ++;
    if (ans == 0) cout << 0 << " " << m << endl;
    else cout << ans << " " << m - 1 << endl;
}

void solve2()
{
    ll mx = 0;
    for (int i = 1; i <= m; i ++)
        mx = max (mx, p[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (d[i] > mx) continue;//cout << d[i] << " " << v[i] << " " << a[i] << " " << V << " " << mx << endl;
        else if (v[i] > V && d[i] <= mx) ans ++;
        else
        {
            if (V * V < v[i] * v[i]) continue;//cout << d[i] << " " << v[i] << " " << a[i] << " " << V << " " << mx << endl;
            ll op = d[i] + (ll) ((V * V - v[i] * v[i]) / (2 * a[i]));
            // if ((V * V - v[i] * v[i]) % (2 * a[i]) == 0) op --;
            if (op < mx) ans ++;
            else continue;//cout << d[i] << " " << v[i] << " " << a[i] << " " << V << " " << mx << endl;
        }
    }
    if (ans == 0) cout << 0 << " " << m << endl;
    else cout << ans << " " << m - 1 << endl;
}

int main()
{
    freopen ("detect.in", "r", stdin);
    freopen ("detect.out", "w", stdout);
    cin >> t;
    while (t --)
    {
        cin >> n >> m >> L >> V;
        // cout << L << endl;
        ll flag = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] < 0) flag = 1;
            else if (a[i] == 0) flag = 2;
            else flag = 3;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i];
        }
        if (flag == 2) solve1();
        if (flag == 3) solve2();
        // return 0;
    }
    return 0;
}
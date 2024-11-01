// cout << "hello_world" << endl;
#include <bits/stdc++.h>
using namespace std;

struct car
{
    int d = 0, v = 0, a = 0;
} c[100001];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t = 0, n = 0, m = 0, l = 0, v = 0;
    cin >> t;

    while (--t >= 0)
    {
        int ans = 0;
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; ++i) cin >> c[i].d >> c[i].v >> c[i].a;
        for (int i = 1; i <= n; ++i)
            if (c[i].v <= v) ++ans;
        cout << ans << " " << m - 1 << endl;
    }
    return 0;
}
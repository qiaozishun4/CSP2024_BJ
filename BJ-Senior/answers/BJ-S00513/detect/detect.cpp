#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int d[100010], v[100010], a[100010], p[100010];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(d, -1, sizeof d);
        memset(v, -1, sizeof v);
        memset(a, -1, sizeof a);
        memset(p, -1, sizeof p);
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        int mx = 0, cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            p[x] = 0;
            mx = max(mx, x);
        }
        for (int i = 1; i <= n; i++) if (d[i] <= mx && v[i] > V) cnt++;
        cout << cnt << " ";
        if (cnt == 0) cout << m << endl;
        else cout << m - 1 << endl;
    }
    return 0;
}
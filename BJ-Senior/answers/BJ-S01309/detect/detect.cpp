#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005], d[100005];
bool flag[1000005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int z;
    cin >> z;
    while (z--)
    {
        memset(flag, false, sizeof(flag));
        int n, m, l, v;
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> d[i];
        }
        int ans1 = 0;
        for (int i = 1;  i<= n; i++)
        {
            double pl;
            if (c[i] != 0)
            {
                pl = (v * v - b[i] * b[i]) / (2 * c[i]) + a[i];
            }
            else if (b[i] <= v) pl = 0;
            else pl = l;
            for (int j = 1; j <= m; j++)
            {
                if (a[i] <= d[j] && d[j] <= pl)
                {
                    ans1++;
                    flag[d[j]] = 1;
                    break;
                }
                if (d[j] > pl) break;
            }
        }
        int ans2 = 0;
        for (int i = 1; i <= m; i++)
        {
           if (flag[d[i]] == 0)
           {
                ans2++;
           }
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
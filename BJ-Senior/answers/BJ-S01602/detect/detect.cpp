#include<bits/stdc++.h>
#define int long long
using namespace std;

int machine[100005];

int d[100005];
int v[100005];
int a[100005];

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(machine, 0, sizeof(machine));
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        int overspeed = 0;
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> machine[i];
        }
        for (int i = 1; i <= n; i++)
        {
            bool flag = 0;
            for (int j = 1; j <= m; j++)
            {
                if (machine[j] >= d[i])
                {
                    if (v[i] > V)
                        flag = 1;
                }
            }
            if (flag) overspeed++;
        }
        cout << overspeed << endl;
        int latest = -1;
        for (int i = 1; i <= n; i++)
        {
            latest = max(latest, d[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            if (machine[i] >= latest)
            {
                if (overspeed >= 1)
                {
                    cout << m - 1;
                    break;
                }
                else
                {
                    cout << m;
                    break;
                }
            }
        }
    }
}

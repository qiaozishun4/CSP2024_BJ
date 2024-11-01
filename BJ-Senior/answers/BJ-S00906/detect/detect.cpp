#include <iostream>
#include <cstring>
using namespace std;
long long vis[100005], d[100005], p[100005], a[100005], ve[100005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, l, v;
        cin >> n >> m >> l >> v;
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        memset(a, 0, sizeof(a));
        memset(ve, 0, sizeof(ve));
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> ve[i] >> a[i];
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> p[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int flag = 0;
            int maxn = 0;
            for (int j = 1; j <= m; j++)
            {
                if (p[j] < d[i] || ve[i] + a[i] * (p[j] - d[i]) <= 0) continue;
                if (ve[i] + a[i] * (p[j] - d[i]) > v)
                {
                    vis[maxn]--;
                    vis[j]++;
                    maxn = max(maxn, j);
                    flag = 1;
                }
            }
            cnt += flag;
        }
        cout << cnt << " ";
        cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            if (vis[i] == 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}

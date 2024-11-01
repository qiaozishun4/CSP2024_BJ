#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int d[100005],v[100005],a[100005],p[100005],now[100005];
struct nd{
    int s,t;
}x[100005];
bool cmp(nd x,nd y)
{
    if (x.t != y.t) return x.t < y.t;
    return x.s < y.s;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n,m,l,V,ans = 0;
        cin >> n >> m >> l >> V;
        //memset(now,0,sizeof(now));
        for (int i = 1;i <= n;i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            //x[i].s = 0;
            //x[i].t = 0;
        }
        for (int i = 1;i <= m;i++)
        {
            cin >> p[i];
        }
        for (int i = 1;i <= n;i++)
        {
            if (v[i] > V && d[i] <= p[m]) ans++;
        }
        /*int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i] > 0)
            {
                for (int j = 1;j <= m;j++)
                {
                    if (p[j] >= d[i] && sqrt(v[i] * v[i] + 2.0 * a[i] * (p[j] - d[i])) > V)
                    {
                        x[i].s = j;
                        x[i].t = m;
                        ans++;
                        break;
                    }
                }
            }
            if (a[i] < 0)
            {
                for (int j = m;j >= 1 && p[j] >= d[i];j--)
                {
                    if (sqrt(v[i] * v[i] + 2.0 * a[i] * (p[j] - d[i])) > V)
                    {
                        x[i].s = lower_bound(p + 1,p + m + 1,d[i]) - p + 1;
                        x[i].t = j;
                        ans++;
                        break;
                    }
                }
            }
            if (a[i] == 0 && v[i] > V && lower_bound(p + 1,p + m + 1,d[i]) - p + 1 <= m)
            {
                x[i].s = lower_bound(p + 1,p + m + 1,d[i]) - p + 1;
                x[i].t = m;
                ans++;
            }
            cout << x[i].s << " " << x[i].t << endl;
        }
        cout << ans << " ";
        sort(x + 1,x + n + 1,cmp);
        int ans2 = 0,cnt = 0;
        for (int i = n - ans + 1;i <= n;i++)
        {
            bool flag = 0;
            for (int j = 1;j <= cnt;j++)
            {
                if (x[i].t >= now[j] && now[j] >= x[i].s) flag = 1;
            }
            if (!flag)
            {
                ans2++;
                now[++cnt] = x[i].t;
            }
        }
        cout << m - ans2 << endl;*/
        cout << ans << " " << m - (ans == 0) << endl;
    }
    return 0;
}

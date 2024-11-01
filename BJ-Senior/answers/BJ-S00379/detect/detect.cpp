#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, L, V;
int vis[100005];
struct car
{
    int d, v, a;
    double sp;
}c[100005];
int w[100005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        bool tta = true, ttb = true, ttc = true;
        cin >> n >> m >> L >> V;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
            if (c[i].a != 0) tta = false;
            if (c[i].a <= 0) ttb = false;
            if (c[i].a >= 0)
            c[i].sp = c[i].d + 1.0 * (1ll * pow(V,2) - pow(c[i].v, 2)) / (1ll * 2 * c[i].a);
        }
        for (int i = 1;i <= m;i++) scanf("%d", &w[i]);
        int ta = w[m];
        int ans = 0, l = 0, r = ta, close = 0;
        if (tta)
        {
            for (int i = 1;i <= n;i++)
            {
                if (c[i].d <= ta && c[i].v > V)
                {
                    ans++;
                    l = max(c[i].d, l);
                }
            }
            for (int i = 1;i <= m;i++)
            {
                if (w[i] < l) close++;
                if (w[i] >= l)
                {
                    close += m - i;
                    break;
                }
            }
            if (ans != 0) cout << ans << " " << close << endl;
            else cout << ans << " " << m << endl;
        }
        else if(ttb)
        {
            for (int i = 1;i <= n;i++)
            {
                //printf("%.3f\n", c[i].sp);
                if (c[i].sp < w[m])
                {
                    ans++;
                    l = max(c[i].d, l);
                }
            }
            for (int i = 1;i <= m;i++)
            {
                if (w[i] < l) close++;
                if (w[i] >= l)
                {
                    close += m - i;
                    break;
                }
            }
            if (ans != 0) cout << ans << " " << close << endl;
            else cout << ans << " " << m << endl;
        }
        else
        {
            l = L, r = 1;
            for (int i = 1;i <= n;i++)
            {
                if (c[i].a == 0)
                {
                    if (c[i].d < ta)
                    {
                        ans++;
                    }
                }
                else if (c[i].a > 0)
                {
                    if (c[i].sp < ta)
                    {
                        ans++;
                    }
                }
                else
                {
                    for (int j = 1;j <= m;j++)
                    {
                        int p = w[j];
                        if (p >= c[i].d && p <= c[i].sp)
                        {
                            ans++;
                            vis[j] == true;
                        }
                    }
                }
            }
            for (int i = 1;i <= m;i++)
            {
                if (!vis[i]) close++;
            }
            cout << ans << " " << min(m-1, close) << endl;
        }
    }
    return 0;
}

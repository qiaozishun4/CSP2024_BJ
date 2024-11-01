#include <bits/stdc++.h>
using namespace std;
int t, n, m, l, lmt;
int lft[3020], rt[3020];
bool vis[3020];
struct node
{
    double d, v, a;
}car[3020];
int p[3020];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(lft, 0, sizeof(lft));
        memset(rt, 0, sizeof(rt));
        int ansc = 0, ansd = m;
        cin >> n >> m >> l >> lmt;
        for(int i = 1; i <= n; i++) cin >> car[i].d >> car[i].v >> car[i].a;
        for(int i = 1; i <= m; i++) cin >> p[i];
        for(int i = 1; i <= n; i++)
        {
            int s;
            for(int j = 1; j <= m; j++)
            {
                if(p[j] < car[i].d) continue;
                s = p[j] - car[i].d;
                double curv = sqrt(car[i].v * car[i].v + 2 * car[i].a * s);
                if(curv > lmt)
                {
                    if(!vis[i])
                    {
                        vis[i] = 1;
                        ansc++;
                        lft[i] = j;
                        if(car[i].a >= 0)
                        {
                            rt[i] = m;
                            break;
                        }
                    }
                }
                else
                {
                    if(vis[i])
                    {
                        rt[i] = j - 1;
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(lft[i] <= rt[j] || rt[i] >= lft[j])
                {
                    ansd--;
                    break;
                }
            }
        }
        cout << ansc << " " << ansd << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
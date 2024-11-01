#include <bits/stdc++.h>
using namespace std;

struct car
{
    int d, v, a;
}c[100010];
bool p[1000010];
int n, m, L, V;

int solve1()
{
    bool vis[100010] = {0};
    int ans = 0;
    for(int i = 0; i <= L; i++)
    {
        if(p[i])
        {
            for(int j = 1; j <= n; j++)
            {
                int v0 = c[j].v, a = c[j].a, s = i - c[j].d;
                double nv = 1.0 * sqrt(v0 * v0 + 2 * a * s);
                if(nv < 0)continue;
                if(s >= 0 && nv > V)
                {
                    if(!vis[j])ans++;
                    vis[j]++;
                }
            }
        }
    }
    return ans;
}

int solve2(int x)
{
    int ans = 0;
    for(int i = 1; i <= L; i++)
    {
        if(p[i])
        {
            p[i] = false;
            int w = solve1();
            if(w == x)ans++;
            else p[i] = true;
        }
    }
    return ans;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++)
        {
            cin >> c[i].d >> c[i].v >> c[i].a;
        }
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            p[x] = true;
        }
        int x = solve1();
        cout << x << " " << solve2(x) << endl;
        for(int i = 1; i <= n; i++)
        {
            c[i].d = 0;
            c[i].v = 0;
            c[i].a = 0;
            p[i] = false;
        }
    }
    return 0;
}

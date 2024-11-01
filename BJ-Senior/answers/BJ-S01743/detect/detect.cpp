#include <bits/stdc++.h>
using namespace std;
const int eps = 1e-6;
struct Car{
    int d, v, a;
    void read()
    {
        cin >> d >> v >> a;
    }
}c[100010];
struct Dis{
    int start = -1e9, finish = -1e9, id;
}s[100010], f[100010];
int T, n, m, L, V, p[100010];
bool vis[100010];
double cal_speed(Car x, int len)
{
    return sqrt(1.0 * x.v * x.v +1.0 * 2 * x.a * len);
}
double cal_len(Car x, int speed)
{
    return 1.0 * (V * V - x.v * x.v) / (2 * x.a) + x.d;
}
bool cmp1(Dis x, Dis y)
{
    return x.start > y.start;
}
bool cmp2(Dis x, Dis y)
{
    return x.finish > y.finish;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(s, 0, sizeof(s));
        memset(f, 0, sizeof(f));
        cin >> n >> m >> L >> V;
        bool isAllA0 = true, isAllAbig = true, isAllAsmall = true;
        for(int i = 1; i <= n; i++)
        {
            c[i].read();
            if(c[i].a != 0) isAllA0 = false;
            if(c[i].a < 0) isAllAbig = false;
            if(c[i].a > 0) isAllAsmall = false;
        }
        for(int i = 1; i <= m; i++) cin >> p[i];
        sort(p +1, p + m +1);
        if(isAllA0)
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(c[i].v > V && c[i].d <= p[m]) cnt++;
            }
            cout << cnt << " " << m - (cnt != 0) << endl;

        }
        else if(isAllAbig)
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(c[i].d <= p[m])
                    if(cal_speed(c[i], p[m] - c[i].d) - V > eps) cnt++;
            }
            cout << cnt << " " << m - (cnt != 0) << endl;
        }
        else if(isAllAsmall)
        {
            int cnt = 0, remain = 0;
            for(int i = 1; i <= n; i++)
            {
                if(c[i].v > V)
                {
                    int len = cal_len(c[i], V)  + eps;
                    int pos_last = upper_bound(p + 1, p + m + 1, len) - p;
                    int pos_first = lower_bound(p + 1, p + m + 1, c[i].d) - p;
                    if(pos_last > pos_first)
                    {
                        cnt++;
                        s[cnt].start = pos_first;
                        f[cnt].finish = pos_last;
                        s[cnt].id = f[cnt].id = cnt;
                    }
                }
            }
            sort(s + 1, s + cnt + 1, cmp1);
            sort(f + 1, f + cnt + 1, cmp2);
            int cur = 1;
            for(int i = 1; i <= cnt; i++)
            {
                if(!vis[s[i].id])
                {
                    remain++;
                    vis[s[i].id] = true;
                    while(s[i].start < f[cur].finish && cur <= cnt)
                    {
                        if(vis[f[cur].id]) continue;
                        vis[f[cur].id] = true;
                        cur++;
                    }
                }
            }
            cout << cnt << " " << remain << endl;
        }
        else
        {
            int cnt = 0, remain = 0;
            for(int i = 1; i <= n; i++)
            {
                if(c[i].a >= 0)
                {
                    for(int i = 1; i <= n; i++)
                    {
                        if(c[i].d <= p[m])
                            if(cal_speed(c[i], p[m] - c[i].d) - V > eps) cnt++;
                    }
                }
                else
                {
                    if(c[i].v > V)
                    {
                        int len = cal_len(c[i], V)  + eps;
                        int pos_last = upper_bound(p + 1, p + m + 1, len) - p;
                        int pos_first = lower_bound(p + 1, p + m + 1, c[i].d) - p;
                        if(pos_last > pos_first)
                        {
                            cnt++;
                            s[cnt].start = pos_first;
                            f[cnt].finish = pos_last;
                            s[cnt].id = f[cnt].id = cnt;
                        }
                    }
                }
            }
            sort(s + 1, s + cnt + 1, cmp1);
            sort(f + 1, f + cnt + 1, cmp2);
            int cur = 1;
            bool nolast = true;
            for(int i = 1; i <= cnt; i++)
            {
                if(!vis[s[i].id])
                {
                    if(s[i].start == m) nolast = false;
                    remain++;
                    vis[s[i].id] = true;
                    while(s[i].start < f[cur].finish && cur <= cnt)
                    {
                        if(vis[f[cur].id]) continue;
                        vis[f[cur].id] = true;
                        cur++;
                    }
                }
            }
            cout << cnt << " " << remain + nolast << endl;
        }
    }
    return 0;
}

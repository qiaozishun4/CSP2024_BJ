#include <bits/stdc++.h>
#define int long long
using namespace std;

int d[100010];
int v[100010];
int a[100010];

int p[100010];

int pos[1000010];

struct Node
{
    int b, e;
}g[100010];

bool cmp(Node x, Node y)
{
    return x.e < y.e;
}

int ismarked[100010];

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, l, vlim;
        cin >> n >> m >> l >> vlim;
        bool note0 = 1;
        bool noteup = 1;
        bool notedown = 1;
        for(int i=1; i<=n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if(a[i] != 0) note0 = 0;
            if(a[i] <= 0) noteup = 0;
            if(a[i] >= 0) notedown = 0;
        }
        for(int i=1; i<=m; i++)
        {
            cin >> p[i];
        }

        if(note0)
        {
            int cnt = 0;
            for(int i=1; i<=n; i++)
            {
                if(v[i] > vlim && d[i] <= p[m]) cnt ++;
            }
            if(cnt == 0)
            {
                cout << 0 << " " << m << endl;
            }
            else cout << cnt << " " << m - 1 << endl;
            continue;
        }

        if(noteup)
        {
            int cnt = 0;
            for(int i=1; i<=n; i++)
            {
                if(d[i] > p[m]) continue;
                long double vmax = sqrtl(2 * a[i] * (p[m] - d[i]) + v[i] * v[i]);
                if(vmax > (long double)vlim) cnt ++;
            }
            if(cnt == 0)
            {
                cout << 0 << " " << m << endl;
            }
            else cout << cnt << " " << m - 1 << endl;
            continue;
        }

        if(notedown)
        {
            int cnt = 0;
            memset(pos, 0, sizeof(pos));
            for(int i=1; i<=m; i++)
            {
                pos[p[i]] = 1;
            }
            for(int i=1; i<=l; i++)
            {
                pos[i] = pos[i - 1] + pos[i];
            }
            p[m + 1] = 0x3f3f3f3f;
            for(int i=1; i<=n; i++)
            {
                if(v[i] <= vlim) continue;
                long double x = (1.00 * v[i] * v[i] - 1.00 * vlim * vlim) / (-2.00 * a[i]);
                if(pos[(int)ceil(x + d[i] - 1)] == pos[d[i] - 1]) continue;
                cnt ++;
                g[cnt].b = d[i];
                g[cnt].e = ceil(x + d[i] - 1);
            }
            sort(g + 1, g + cnt + 1, cmp);
            int nowfindid = 0;
            memset(ismarked, 0, sizeof(ismarked));
            int totaluse = 0;
            for(int i=1; i<=cnt; i++)
            {
                if(ismarked[i]) continue;
                int be = g[i].b;
                int en = g[i].e;
                for(int j=nowfindid+1; j<=m+1; j++)
                {
                    if(p[j] > en)
                    {
                        nowfindid = j - 1;
                        break;
                    }
                }
                if(nowfindid == m) nowfindid += 2;
                ismarked[i] = 1;
                totaluse ++;
                int location = p[nowfindid];
                for(int j=i+1; j<=cnt; j++)
                {
                    if(g[j].b <= location && g[j].e >= location)
                    {
                        ismarked[j] = 1;
                    }
                }
            }
            cout << cnt << " " << m - totaluse << endl;
            continue;
        }

        int cntnormal = 0;
        int cnt = 0;
        memset(pos, 0, sizeof(pos));
        for(int i=1; i<=m; i++)
        {
            pos[p[i]] = 1;
        }
        for(int i=1; i<=l; i++)
        {
            pos[i] = pos[i - 1] + pos[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i] == 0)
            {
                if(v[i] > vlim && d[i] <= p[m]) cntnormal ++;
            }
            else if(a[i] > 0)
            {
                if(d[i] > p[m]) continue;
                long double vmax = sqrtl(2 * a[i] * (p[m] - d[i]) + v[i] * v[i]);
                if(vmax > (long double)vlim) cntnormal ++;
            }
            else
            {
                if(v[i] <= vlim) continue;
                long double x = (1.00 * v[i] * v[i] - 1.00 * vlim * vlim) / (-2.00 * a[i]);
                if(pos[(int)ceil(x + d[i] - 1)] == pos[d[i] - 1]) continue;
                cnt ++;
                g[cnt].b = d[i];
                g[cnt].e = min(p[m], (int)ceil(x + d[i] - 1));
            }
        }
        sort(g + 1, g + cnt + 1, cmp);
        int nowfindid = 0;
        int ismqwq = 0;
        memset(ismarked, 0, sizeof(ismarked));
        int totaluse = 0;
        for(int i=1; i<=cnt; i++)
        {
            if(ismarked[i]) continue;
            int be = g[i].b;
            int en = g[i].e;
            for(int j=nowfindid+1; j<=m+1; j++)
            {
                if(p[j] > en)
                {
                    nowfindid = j - 1;
                    break;
                }
            }
            if(nowfindid == m)
            {
                nowfindid += 2;
                ismqwq = 1;
            }
            ismarked[i] = 1;
            totaluse ++;
            int location = p[nowfindid];
            for(int j=i+1; j<=cnt; j++)
            {
                if(g[j].b <= location && g[j].e >= location)
                {
                    ismarked[j] = 1;
                }
            }
        }
        cout << cnt << " " << m - totaluse - 1 + ismqwq << endl;
    }
}

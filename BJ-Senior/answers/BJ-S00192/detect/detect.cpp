#include<bits/stdc++.h>

using namespace std;

const int NR = 3005, MR = 100005;
int n, m, L, V, cnt, ans;
int v[MR], a[MR];
double p[MR], d[MR];
bool num[NR][NR], f[MR];
bool t[NR], tmp;

void dfs(int step, int c)
{
    if(step > m)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            bool x = 0;
            for(int j = 1; j <= m; j++)
                if(num[i][j] && t[j])
                {
                    x = 1;
                    break;
                }
            sum += x;
        }
        if(sum == cnt)
        {
            ans = min(ans, c);
            tmp = true;
        }
        return;
    }
    if(tmp == true) return;
    t[step] = false;
    dfs(step + 1, c);
    if(tmp == true) return;
    t[step] = true;
    dfs(step + 1, c + 1);
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> L >> V;
        int flag = 1;
        for(int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if(a[i] < 0) flag = 0;
        }
        for(int i = 1; i <= m; i++)
            cin >> p[i];
        if(flag == 1)
        {
            memset(f, 0, sizeof(f));
            for(int i = 1; i <= n; i++)
            {
                if(a[i] > 0)
                {
                    double pnt = d[i] + (V * V - v[i] * v[i]) / (2.0 * a[i]);
                    int pos = upper_bound(p + 1, p + m + 1, pnt) - p;
                    if(pos <= m) f[i] = true;
                }
                else
                    if(v[i] > V && d[i] <= p[m]) f[i] = true;
            }
            int cnt = 0;
            for(int i = 1; i <= n; i++)
                cnt += f[i];
            if(cnt == 0) cout << cnt << ' ' << m << endl;
            else cout << cnt << ' ' << m - 1 << endl;
        }
        else
        {
            memset(num, 0, sizeof(num));
            memset(f, 0, sizeof(f));
            for(int i = 1; i <= n; i++)
            {
                if(a[i] > 0)
                {
                    double pnt = d[i] + (V * V - v[i] * v[i]) / (2.0 * a[i]);
                    for(int j = 1; j <= m; j++)
                        if(1.0 * p[j] > pnt) num[i][j] = true, f[i] = true;
                }
                else if(a[i] < 0)
                {
                    double pnt = d[i] + max(0.0, (V * V - v[i] * v[i]) / (2.0 * a[i]));
                    for(int j = 1; j <= m; j++)
                        if(d[i] <= p[j] && p[j] * 1.0 < pnt) num[i][j] = true, f[i] = true;
                }
                else
                {
                    for(int j = 1; j <= m; j++)
                        if(V < v[i] && p[j] >= d[i]) num[i][j] = true, f[i] = true;
                }
            }
            cnt = 0;
            for(int i = 1; i <= n; i++)
                cnt += f[i];
            ans = 1e9;
            tmp = 0;
            dfs(1, 0);
            cout << cnt << ' ' << m - ans << endl;
        }
    }
    return 0;
}

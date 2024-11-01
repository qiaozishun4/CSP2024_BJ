#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int Inf = 0x3f3f3f;
int d[100010], v[100010], a[100010], p[100010];
bool flag[100010], ff[100010];
vector<int> g[100010];
int minn;
int n, m, l, ov;
bool c[100010];

bool chk()
{
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= m; ++i)
        if (c[i])
            for (auto y : g[i])
                flag[y] = 1;
    for (int i = 1; i <= n; ++i)
        if (!flag[i] && !ff[i])
            return 0;
    /*for (int i = 1; i <= m; ++i)
        cout << c[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; ++i)
        cout << flag[i] << ' ';
    cout << endl << endl;*/
    return 1;
}

void dfs(int step, int sum)
{
    if (sum >= minn) return;
    if (step > m)
    {
        /*cout << sum <<endl;*/
        if (chk()) minn = sum;
        return ;
    }
    c[step] = 1;
    dfs(step + 1, sum + 1);
    c[step] = 0;
    dfs(step + 1, sum);
    c[step] = 0;
}

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(c, 0, sizeof c);
        for (int i = 0; i <= 100009; ++i)
            g[i].clear();
        memset(ff, 0, sizeof ff);
        cin >> n >> m >> l >> ov;
        for (int i = 1; i <= n; ++i)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; ++i)
            cin >> p[i];
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            bool flg = 0;
            //if (a[i] > 0)
            //{
            double out = a[i] >= 0 ? 1e9 : 1.0 * -v[i] * v[i] / (2.0 * a[i]);
                for (int j = 1; j <= m; ++j)
                {
                    if (p[j] < d[i]) continue;
                    if (p[j] - d[i] > out) continue;
                    double ns = sqrt(v[i] * v[i] + 2ll * a[i] * (p[j] - d[i]));
                    if (ns > ov)
                    {
                        flg = 1;
                        g[j].push_back(i);
                    }
                }
            //}
            /*else if (a[i] == 0)
            {
                int st;
                for (int j = m; j >= 1; --j)
                    if (p[j] >= d[i])
                    {
                        st = j;
                    }
                if (v[i] > ov)
                {
                    for (int j = st; j <= m; ++j)
                        g[j].push_back(i);
                    flag = 1;
                }
            }
            else
            {
                for (int j = 1; j <= m; ++j)
                {
                    if (p[j] < d[i])
                        continue;
                    double ns = sqrt(v[i] * v[i] + 2 * a[i] * (p[j] - d[i])) + 1e-6;
                    if (ns > ov)
                    {
                        flag = 1;
                        g[j].push_back(i);
                    }
                }
            }*/
            if (flg)
                ++cnt;
            else
                ff[i] = 1/*, cout << i <<endl*/;
        }
        minn = m;
        dfs(1, 0);
        cout << cnt << ' ' << m - minn << endl;
    }
    return 0;
}

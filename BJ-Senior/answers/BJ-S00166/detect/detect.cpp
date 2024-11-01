#include <bits/stdc++.h>
using namespace std;

int n, m, L, V, p[100005], vis[100005], vis2[100005], mx;
int d[100005], v[100005], a[100005];

vector<int> g[100005];

void dfs(int x, int cnt)
{
    if (x == m + 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i] == 1 && vis2[i] == 0) return;
        }
        mx = max(mx, m - cnt);
        return;
    }
    dfs(x + 1, cnt);
    for (int i = 0; i < g[x].size(); ++i)
    {
        vis2[g[x][i]]++;
    }
    dfs(x + 1, cnt + 1);
    for (int i = 0; i < g[x].size(); ++i)
    {
        vis2[g[x][i]]--;
    }
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis2));
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= 100000; ++i) g[i].clear();
        mx = 0;
        cin >> n >> m >> L >> V;
        bool A = true, B = true, C = true;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d %d %d", &d[i], &v[i], &a[i]);
            if (a[i] != 0) A = false;
            if (a[i] <= 0) B = false;
            if (a[i] >= 0) C = false;
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> p[i];
        }
        if (n <= 20 && m <= 20)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                {
                    if (d[i] > p[j]) continue;
                    long long dis = 1ll * v[i] * v[i] + 2ll * (p[j] - d[i]) * a[i];
                    if (dis > 1ll * V * V)
                    {
                        g[j].push_back(i);
                        vis[i] = 1;
                    }
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
            {
                cnt += vis[i];
            }
            cout << cnt << " ";
            dfs(1, 0);
            cout << mx << endl;
        }
        else if (A)
        {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (d[i] <= p[m] && v[i] > V) cnt1++;
            }
            cout << cnt1 << " " << m - 1 << endl;
        }
        else if (B)
        {
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (d[i] <= p[m] && (1ll * v[i] * v[i] + 2ll * (p[m] - d[i]) * a[i] > 1ll * V * V)) cnt++;
            }
            cout << cnt << " " << m - 1 << endl;
        }
    }
    return 0;
}

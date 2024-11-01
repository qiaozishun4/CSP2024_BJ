#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, L, V;
int ma = -1;
int p[100005], v[100005], a[100005], x[100005], cnt[100005], f[100005], s[100005];

void dfs(int u, int tar)
{
    if (u > m)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!s[j])
                {
                    continue;
                }
                if (x[j] < p[i])
                {
                    continue;
                }
                if (v[i] * v[i] + 2 * a[i] * (x[j] - p[i]) <= 0)
                {
                    break;
                }
                if (v[i] * v[i] + 2 * a[i] * (x[j] - p[i]) > V * V)
                {
                    f[i] = 1;
                    break;
                }
            }
        }
        int sum = 0, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += f[i];
        }
        for (int i = 1; i <= m; i++)
        {
            tot += s[i];
        }
        if (sum < tar)
        {
            memset(f, 0, sizeof(f));
            return;
        }
        else
        {
            ma = max(ma, m - tot);
            memset(f, 0, sizeof(f));
            return;
        }
    }
    s[u + 1] = 0;
    dfs(u + 1, tar);
    s[u + 1] = 1;
    dfs(u + 1, tar);
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &n, &m, &L, &V);
        memset(f, 0, sizeof(f));
        memset(cnt, 0, sizeof(cnt));
        ma = 0;
        bool A = 1, B = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &p[i], &v[i], &a[i]);
            if (a[i])
            {
                A = 0;
            }
            if (a[i] <= 0)
            {
                B = 0;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &x[i]);
        }
        int ans = 0;
        if (A)
        {
            for (int i = 1; i <= n; i++)
            {
                if (v[i] > V && p[i] <= x[m])
                {
                    ans++;
                }
            }
            if (ans == 0)
            {
                m++;
            }
            cout << ans << ' ' << m - 1 << endl;
        }
        else if (B)
        {
            for (int i = 1; i <= n; i++)
            {
                if (v[i] * v[i] + 2 * a[i] * (x[m] - p[i]) > V * V && p[i] <= x[m])
                {
                    ans++;
                }
            }
            if (ans == 0)
            {
                m++;
            }
            cout << ans << ' ' << m - 1 << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (x[j] < p[i])
                    {
                        continue;
                    }
                    if (v[i] * v[i] + 2 * a[i] * (x[j] - p[i]) <= 0)
                    {
                        break;
                    }
                    if (v[i] * v[i] + 2 * a[i] * (x[j] - p[i]) > V * V)
                    {
                        f[i] = 1;
                        break;
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                ans += f[i];
            }
            cout << ans << ' ';
            memset(f, 0, sizeof(f));
            dfs(0, ans);
            cout << ma << endl;
        }
        
    }
    return 0;
}
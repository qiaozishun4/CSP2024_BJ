#include <bits/stdc++.h>
using namespace std;

int T, n, m, L, ans, V, d[100005], v[100005], a[100005], minn = 2e9;
double p[100005];
bool flag[100005], flag1[100005], flagp[100005];

void dfs(int step, int sum)
{
    if (step > m)
    {
        memset(flag1, false, sizeof(flag1));
        for (int i = 1; i <= m; i++)
        {
            if (!flagp[m]) continue;
            for (int j = 1; j <= n; j++)
            {
                if (flag1[j]) continue;
                if (d[j] > p[i]) continue;
                if (a[i] == 0 && v[j] > V)
                {
                    flag1[j] = true;
                    continue;
                }
                if (a[i] == 0 && v[j] <= V) continue;
                double t = sqrt(v[j] * v[j] + 2 * a[j] * (p[i] - d[j]));
                if (t > V) flag1[j] = true;
            }
        }
        for (int i = 1; i <= n; i++)
            if (flag[i] && flag1[i])
                return;
        minn = min(minn, sum);
        return;
    }
    dfs(step + 1, sum);
    flagp[step] = false;
    dfs(step + 1, sum + 1);
    flagp[step] = true;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        memset(flag, false, sizeof(flag));
        ans = 0;
        bool A = true, B = true, C = true;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] != 0) A = false;
            if (a[i] < 0)  B = false;
            if (a[i] > 0)  C = false;
        }
        for (int i = 1; i <= m; i++)
            cin >> p[i];

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (flag[j]) continue;
                if (d[j] > p[i]) continue;
                if (a[i] == 0 && v[j] > V)
                {
                    ans++;
                    flag[j] = true;
                    continue;
                }
                if (a[i] == 0 && v[j] <= V) continue;
                double t = sqrt(v[j] * v[j] + 2 * a[j] * (p[i] - d[j]));
                if (t > V) ans++, flag[j] = true;
            }
        }

        cout << ans << " ";

        if (A)
        {
            int limit = -2e9;
            for (int i = 1; i <= n; i++)
            {
                if (v[i] > V) limit = max(limit, d[i]);
            }
            bool temp = true;
            for (int i = 1; i <= m; i++)
            {
                if (p[i] > limit)
                {
                    cout << m - 1 << endl;
                    temp = false;
                    break;
                }
            }
            if (temp) cout << m << endl;
            continue;
        }
        if (B)
        {
            memset(flag1, false, sizeof(flag1));
            int cnt = 0;
            bool temp = true;
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (flag1[j]) continue;
                    if (d[j] > p[i]) continue;
                    double t = sqrt(v[j] * v[j] + 2 * a[j] * (p[i] - d[j]));
                    if (t > V) cnt++, flag1[j] = true;
                }
                if (cnt == n)
                {
                    cout << m - 2 << endl;
                    temp = false;
                    break;
                }
            }
            if (temp) cout << m - 1 << endl;
            continue;
        }
        if (C)
        {
            memset(flag1, false, sizeof(flag1));
            int cnt = 0;
            bool temp = true;
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (flag1[j]) continue;
                    if (d[j] > p[i]) continue;
                    double t = sqrt(v[j] * v[j] + 2 * a[j] * (p[i] - d[j]));
                    if (t > V) cnt++, flag1[j] = true;
                }
                if (cnt == n)
                {
                    cout << m - 2 << endl;
                    temp = false;
                    break;
                }
            }
            if (temp) cout << m - 1 << endl;
            continue;
        }

        memset(flagp, true, sizeof(flag));
        minn = 2e9;
        dfs(1, 0);
    }
    return 0;
}

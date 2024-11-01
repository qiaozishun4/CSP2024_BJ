#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, a[N], dp[N][N], pre[N][N], no[N], ans, col[N];
void dfs (int u)
{
    if (u == n + 1)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (col[i] == col[j]) 
                {
                    if (a[i] == a[j]) sum += a[i];
                    break;
                }
            }
        }
        ans = max (ans, sum);
        return;
    }
    dfs (u + 1);
    col[u] = 1;
    dfs (u + 1);
    col[u] = 0;
    return;
}
int main ()
{
    freopen ("color.in", "r", stdin);
    freopen ("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = 0;
                pre[i][j] = 0;
                no[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n <= 15)
        {
            ans = 0;
            dfs (1);
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                pre[i][j] = pre[i][j - 1];
                if (a[j] == a[j - 1])
                {
                    pre[i][j] += a[j];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                dp[i][j] = no[j + 1] + pre[j + 1][i - 1];
                if (a[i] == a[j]) dp[i][j] += a[i];
            }
            dp[i][0] = pre[1][i - 1];
            for (int j = 0; j <= i - 2; j++)
            {
                no[i] = max (no[i], dp[i][j]); 
            }
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max (ans, dp[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
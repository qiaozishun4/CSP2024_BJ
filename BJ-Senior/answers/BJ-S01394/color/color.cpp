#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int N = 200005;
int t, n, a[N], a1[N], a2[N], s[N], ans, dp[2005][2005], mx;
void dfs(int x, int sum, int cnt1, int cnt2)
{
    if (sum + s[n] - s[x - 1] <= ans) return;
    if (x > n)
    {
        ans = max(ans, sum);
        return;
    }
    if (a[x] == a1[cnt1])
    {
        a1[cnt1 + 1] = a[x];
        dfs(x + 1, sum + a[x], cnt1 + 1, cnt2);
        a1[cnt1 + 1] = 0;
    }
    else if (a[x] == a2[cnt2])
    {
        a2[cnt2 + 1] = a[x];
        dfs(x + 1, sum + a[x], cnt1, cnt2 + 1);
        a2[cnt2 + 1] = 0;
    }
    else
    {
        a1[cnt1 + 1] = a[x];
        dfs(x + 1, sum, cnt1 + 1, cnt2);
        a1[cnt1 + 1] = 0;
        a2[cnt2 + 1] = a[x];
        dfs(x + 1, sum, cnt1, cnt2 + 1);
        a2[cnt2 + 1] = 0;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
        {
            if (i > j + 1)
            {
                dp[i][j] = dp[i - 1][j];
                if (a[i] == a[i - 1]) dp[i][j] += a[i];
            }
            if (j > 1)
            {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if (a[i] == a[j - 1]) dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i]);
            }
        }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        ans = 0, mx = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
            mx = max(a[i], mx);
        }
        if (n <= 15) dfs(1, 0, 0, 0);
        else solve();
        printf("%d\n", ans);
    }
    return 0;
}


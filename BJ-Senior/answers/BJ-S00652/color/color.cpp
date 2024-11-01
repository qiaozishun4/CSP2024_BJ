#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long a[200005],dp[105][105][105],vis[1000005],pos[200005],reg[1000005];
int v1[2005],v2[2005];
long long ans = 0,n;
void dfs(int step,int c1,int c2)
{
    if (step > n)
    {
        long long s = 0;
        for (int i = 1;i <= c1;i++)
            if (a[v1[i]] == a[v1[i-1]])
                s += a[v1[i]];
        for (int i = 1;i <= c2;i++)
            if (a[v2[i]] == a[v2[i-1]])
                s += a[v2[i]]; 
        ans = max(ans,s);
        return;
    }
    int i = step;
    v1[c1+1] = step;
    dfs(step+1,c1+1,c2);
    v2[c2+1] = step;
    dfs(step + 1,c1,c2+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp,-0x7f,sizeof(dp));
        int cnt = 0;
        cin >> n;
        long long maxn = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            pos[i] = reg[a[i]];
            reg[a[i]] = i;
            maxn = max(maxn,a[i]);
        }
        if (n <= 20)
        {
            ans = 0;
            dfs(1,0,0);
            cout << ans << endl;
            continue;
        }
        dp[1][a[1]][0] = dp[1][0][a[1]] = 0;
        long long st = 0;
        for (int i = 2;i <= n;i++)
        {
            for (int j = maxn;j >= 0;j--)
                for (int k = maxn;k >= 0;k--)
                {
                    dp[i][a[i]][k] = max(dp[i-1][a[i]][k],dp[i-1][j][k] + a[i]*(a[i]==j));
                }
             for (int j = maxn;j >= 0;j--)
                for (int k = maxn;k >= 0;k--)
                    dp[i][j][a[i]] = max(dp[i-1][j][a[i]],dp[i-1][j][k] + a[i]*(a[i]==k));
             
        }
        for (int i = 0;i <= maxn;i++)
            for (int k = 0;k <= maxn;k++)
                st = max(st,dp[n][i][k]);
        cout << st << endl;
    }
	return 0;
}
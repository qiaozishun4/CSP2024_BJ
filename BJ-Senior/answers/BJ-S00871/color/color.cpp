#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 2e5+5;
int a[MAXN],red[MAXN],blue[MAXN],f[MAXN],fa[MAXN];
long long ans;
bool c[MAXN];
long long dp[2001];

void dfs(int p)
{
    if(p > n)
    {
        int cnt1 = 0,cnt2 = 0;
        for(int i = 1;i <= n;i++)
        {
            if(c[i]) red[++cnt1] = a[i];
            else blue[++cnt2] = a[i];
        }
        // << cnt1 << " " << cnt2 << endl;
        long long sum = 0;
        for(int i = 1;i <= cnt1;i++)
        {
            if(red[i] == red[i-1])  sum += red[i];
            //cout << red[i] << " ";
        }
        //cout << endl;
        for(int i = 1;i <= cnt2;i++)
        {
            if(blue[i] == blue[i-1]) sum += blue[i];
            //cout << blue[i] << " ";
        }
        //cout << endl;
        ans = max(ans,sum);
        return;
    }
    dfs(p+1);
    c[p] = 1;
    dfs(p+1);
    c[p] = 0;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(c,0,sizeof(c));
        ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        if(n <= 15)
        {
            dfs(1);
            cout << ans << endl;
        }
        else
        {
            long long ans = 0,k;
            memset(dp,0,sizeof(dp));
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j < i;j++)
                {
                    if(dp[i] < dp[j])
                    {
                        fa[i] = j;
                        dp[i] = dp[j];
                    }
                    if(a[i] == a[j])
                    {
                        if(dp[i] < dp[j]+a[j])
                        {
                            fa[i] = j;
                            dp[i] = dp[j]+a[j];
                        }
                    }
                }
                if(dp[i] > ans)
                {
                    ans = dp[i];
                    k = i;
                }
            }
            while(k != 0)
            {
                f[k] = 1;
                k = fa[k];
            }
            long long ans2 = 0;
            memset(dp,0,sizeof(dp));
            for(int i = 1;i <= n;i++)
            {
                if(f[i]) continue;
                for(int j = 1;j < i;j++)
                {
                    if(f[j]) continue;
                    dp[i] = max(dp[i],dp[j]);
                    if(a[i] == a[j]) dp[i] = max(dp[i],dp[j]+a[j]);
                }
                ans2 = max(ans2,dp[i]);
            }
            cout << ans+ans2 << endl;
        }
    }
    return 0;
}

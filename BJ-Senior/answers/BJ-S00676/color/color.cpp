#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[400][400],n,A[2005];
void solve()
{
    scanf("%lld",&n);
    for(ll i = 1;i <=n;i++)scanf("%lld",&A[i]);
    for(ll i = 0;i <400;i++)
        for(ll j = 0;j <400;j++)
            dp[i][j]=0;
    dp[1][0]=0;
    for(ll i = 2;i <=n;i++)
    {
        for(ll j = 0;j <i;j++)
        {
            for(ll k = 0;k <j;k++)
                dp[i][j]=max(dp[i][j],dp[j][k]+(A[j+1]==A[k]?A[j+1]:0));
            for(ll k = i;k >=j+2;k--)dp[i][j]+=(A[i]==A[i-1]?A[i]:0);
        }
    }
    ll lans=0;
    for(ll i = 1;i <n;i++)lans=max(lans,dp[n][i]);
    printf("%lld\n",lans);
}
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll T;scanf("%lld",&T);
    for(ll i = 1;i <=T;i++)solve();
    return 0;
}

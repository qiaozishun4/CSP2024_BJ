#include<bits/stdc++.h>
using namespace std;
int a[2010],dp[2][2010][2010];
void solve()
{
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=2000)
    {
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i-1;j++)
            {
                int k=i-1;
                int now=(i+1)&1,lst=i&1;
                dp[now][i][k]=max(dp[now][i][k],dp[lst][j][k]+(a[i]==a[j])*a[i]);
                dp[now][j][i]=max(dp[now][j][i],dp[lst][j][k]+(a[i]==a[k])*a[i]);
                swap(j,k);
                dp[now][i][k]=max(dp[now][i][k],dp[lst][j][k]+(a[i]==a[j])*a[i]);
                dp[now][j][i]=max(dp[now][j][i],dp[lst][j][k]+(a[i]==a[k])*a[i]);
                swap(j,k);
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<'\n';
                ans=max(ans,dp[0][j][k]);
                ans=max(ans,dp[1][j][k]);
            }
        }
        cout<<ans<<'\n';
    }
    else cout<<0<<'\n';
    
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--) solve();
}
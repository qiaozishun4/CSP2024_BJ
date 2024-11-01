#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int a[200005];
long long dp[2][20010][2];
long long dp2[2][15][15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=20000)
        {
            for(int i=1;i<=n;i++)
            {
                dp[0][i][0]=dp[0][i][1]=dp[1][i][0]=dp[1][i][1]=-1e18;
            }
            dp[1][1][0]=dp[1][1][1]=0;
            for(int i=2;i<=n;i++)
            {
                dp[i%2][1][0]=-1e18;
                dp[i%2][1][1]=-1e18;
                for(int j=1;j<i;j++)
                {
                    dp[i%2][1][0]=max(dp[i%2][1][0],dp[(i-1)%2][j][1]+(a[i]==a[i-j-1])*a[i]);
                    dp[i%2][1][1]=max(dp[i%2][1][1],dp[(i-1)%2][j][0]+(a[i]==a[i-j-1])*a[i]);
                }
                for(int j=2;j<=i;j++)
                {
                    dp[i%2][j][0]=dp[(i-1)%2][j-1][0]+(a[i]==a[i-1])*a[i];
                    dp[i%2][j][1]=dp[(i-1)%2][j-1][1]+(a[i]==a[i-1])*a[i];
                }
            }
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                ans=max(ans,dp[n%2][i][0]);
                ans=max(ans,dp[n%2][i][1]);
            }
            cout<<ans<<'\n';
        }
        else
        {
            for(int i=0;i<=10;i++)
            {
                for(int j=0;j<=10;j++)
                {
                    dp2[0][i][j]=-1e18;
                }
            }
            dp2[0][0][0]=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=10;j++)
                {
                    for(int k=0;k<=10;k++)
                    {
                        dp2[(i+1)%2][j][k]=-1e18;
                    }
                }
                for(int j=0;j<=10;j++)
                {
                    for(int k=0;k<=10;k++)if(dp2[i%2][j][k]>=0){
                        //red
                        dp2[(i+1)%2][a[i+1]][k]=max(dp2[(i+1)%2][a[i+1]][k],dp2[i%2][j][k]+(a[i+1]==j)*a[i+1]);
                        //blue
                        dp2[(i+1)%2][j][a[i+1]]=max(dp2[(i+1)%2][j][a[i+1]],dp2[i%2][j][k]+(a[i+1]==k)*a[i+1]);
                        // cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
                    }
                }
            }
            long long ans=0;
            for(int i=1;i<=10;i++)
            {
                for(int j=1;j<=10;j++)
                {
                    ans=max(ans,dp2[n%2][i][j]);
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
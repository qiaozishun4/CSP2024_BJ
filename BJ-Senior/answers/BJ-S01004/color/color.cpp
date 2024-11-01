#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e3+5;
int T,n,a[N],dp[N][N][2],ans;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    faster;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j][0]=dp[i][j][1]=-1e9;
        dp[1][1][1]=0;
        dp[1][1][0]=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(i==j)
                {
                    for(int k=1;k<=i-1;k++)
                    {
                        dp[i][j][0]=max(dp[i][j][0],dp[i-1][k][0]+((a[i]==a[i-1])?a[i]:0));
                        dp[i][j][0]=max(dp[i][j][0],dp[i-1][k][1]+((a[i]==a[k-1])?a[i]:0));
                        dp[i][j][1]=max(dp[i][j][1],dp[i-1][k][1]+((a[i]==a[i-1])?a[i]:0));
                        dp[i][j][1]=max(dp[i][j][1],dp[i-1][k][0]+((a[i]==a[k-1])?a[i]:0));
                    }
                }
                else
                {
                    dp[i][j][0]=dp[i-1][j][0]+((a[i]==a[i-1])?a[i]:0);
                    dp[i][j][1]=dp[i-1][j][1]+((a[i]==a[i-1])?a[i]:0);
                }
            }
        }
        ans=-1e9;
        for(int i=0;i<=n;i++)
        {
            ans=max(ans,max(dp[n][i][0],dp[n][i][1]));
        }
        cout << ans <<'\n';
    }
    return 0;
}

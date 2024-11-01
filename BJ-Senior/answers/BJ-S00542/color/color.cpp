#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int t,n,a[2005],dp[2005][2][2][2005],cnt[2005],sp[2005][2005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=2000;j++)    cnt[j] = 0;
            cnt[a[i]] = 1;
            for(int j=i-1;j>=1;j--)
            {
                sp[j][i] = sp[j+1][i];
                if(cnt[a[j]])   sp[j][i] += a[j];
                cnt[a[j]] ++;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++)
                    for(int l=1;l<=2000;l++)
                        dp[i][j][k][l] = -INF;
        dp[1][0][0][a[1]] = dp[1][1][1][a[1]] = 0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++) //i bu zhuan
            {
                dp[i][0][0][a[i]] = max(dp[i][0][0][a[i]],dp[i-1][0][0][a[i]]);
                if(a[i] == a[i-1])  dp[i][0][0][a[i]] += a[i];
                dp[i][0][1][a[j]] = max(dp[i][0][1][a[j]],dp[i-1][0][1][a[j]]);
                if(a[i] == a[i-1])  dp[i][0][1][a[j]] += a[i];
                dp[i][1][0][a[j]] = dp[i][0][1][a[j]];
                dp[i][1][1][a[i]] = dp[i][0][0][a[i]];
            }
            for(int j=1;j<i;j++) //i zhuan
            {
                if(a[j] != a[i])    continue;
                if(j == i-1)
                {
                    dp[i][1][1][a[i]] = max(dp[i][1][1][a[i]],dp[j][1][1][a[j]] + a[j]);
                    dp[i][0][0][a[i]] = max(dp[i][0][0][a[i]],dp[j][0][0][a[j]] + a[j]);
                }
                else
                {
                    dp[i][1][1][a[i]] = max(dp[i][1][1][a[i]],max(dp[j][1][1][a[j]],dp[j][1][0][a[j+1]]+a[j+1]) + sp[j+1][i-1] + a[i]);
                    dp[i][0][0][a[i]] = max(dp[i][0][0][a[i]],max(dp[j][0][0][a[j]],dp[j][0][1][a[j+1]]+a[j+1]) + sp[j+1][i-1] + a[i]);
                }

                if(j == i-1) //maybe need for
                {
                    for(int k=1;k<j;k++)
                    {
                        dp[i][1][0][a[k]] = max(dp[i][1][0][a[k]],dp[k][0][0][a[k]] + sp[k+1][i]);
                        dp[i][0][1][a[k]] = max(dp[i][0][1][a[k]],dp[k][1][1][a[k]] + sp[k+1][i]);
                    }
                }
                else
                {
                    dp[i][1][0][a[i-1]] = max(dp[i][1][0][a[i-1]],max(dp[j][1][1][a[j]],dp[j][1][0][a[j+1]]+a[j+1]) + sp[j+1][i-1] + a[i]);
                    dp[i][0][1][a[i-1]] = max(dp[i][0][1][a[i-1]],max(dp[j][0][0][a[j]],dp[j][0][1][a[j+1]]+a[j+1]) + sp[j+1][i-1] + a[i]);
                }

            }
        }
        /*
        9
        5 3 13 6 5 5
        0 1 1  1 0 0
        */
        /*
        1
        6
        5 2 5 1 2 1
        */
        //cout << dp[5][0][0][2] << '\n';
        cout << max(dp[n][0][0][a[n]],dp[n][1][1][a[n]]) << '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long t,n,w[10]={6,2,5,5,4,5,6,3,7,6},mi=0x7f7f7f,dp[10000][1000];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {

        cin>>n;
        if(n<2)cout<<-1<<endl;
        else
        {
            for(int i=1;i<=10;i++)
            {
                for(int j=n;j>=0;j--)
                {
                    if(j>=w[i])
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+i);
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            cout<<dp[10][n]<<endl;
        }
    }

    return 0;
}
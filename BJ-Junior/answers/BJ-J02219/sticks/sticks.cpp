/*
dp[i]=min(dp[i-st[j]]*10+j);
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int sti[11]= {6,2,5,5,4,5,6,3,7,6,0};
int dp[N];
int n;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(dp,0x3f,sizeof dp);
        dp[2]=1;
        dp[3]=7;
        dp[6]=6;
        dp[5]=2;
        dp[7]=7;
        dp[4]=4;
        for(int i=4; i<=n; i++)
        {
            if(i!=2&&i!=3&&i!=6&&i!=5&&i!=7&&i!=4)
            {
                for(int j=0; j<10; j++)
                {
                    if(dp[i]>=dp[i-sti[j]]&&dp[i-sti[j]]!=0&&dp[i-sti[j]]!=INF)
                    {
                        dp[i]=min(dp[i],dp[i-sti[j]]*10+j);
                    }
                }
            }

        }
        if(dp[n]==INF)
        {
            cout<<-1<<'\n';
        }
        else
        {
            cout<<dp[n]<<'\n';
        }

    }
    return 0;
}

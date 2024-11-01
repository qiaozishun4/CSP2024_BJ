#include<bits/stdc++.h>
using namespace std;
struct node{
    int w;
    long long v;
}s[8];
struct str{
    long long f;
    int c;
}dp[100002];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    s[1].w=6,s[1].v=0;
    s[2].w=2,s[2].v=1;
    s[3].w=5,s[3].v=2;
    s[4].w=4,s[4].v=4;
    s[5].w=3,s[5].v=7;
    s[6].w=7,s[6].v=8;
    s[7].w=6,s[7].v=6;
    while(T)
    {
        T--;
        int n;
        cin>>n;
        dp[0].f=0,dp[0].c=0;
        for(int i=1;i<=n;i++)
            dp[i].f=LONG_LONG_MAX;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=7;j++)
            {
                if(i==n&&j==1)
                    continue;
                if(i-s[j].w>=0&&dp[i-s[j].w].f+pow(10,dp[i-s[j].w].c)*s[j].v<dp[i].f)
                {
                    dp[i].f=dp[i-s[j].w].f+pow(10,dp[i-s[j].w].c)*s[j].v;
                    dp[i].c=dp[i-s[j].w].c+1;
                }
            }
        }
        if(dp[n].f==LONG_LONG_MAX)
            cout<<-1<<endl;
        else
            cout<<dp[n].f<<endl;
    }
    return 0;
}
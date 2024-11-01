#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
const int N=1e5+5;
int pre[N];//lian biao,zhi xiang pre char
int dp[N][2];//yong i gen hua chai,zui xiao chang du(you xian)
int cost[]={6,2,5,4,6,3,7,6};
int num[]={0,1,2,4,6,7,8,9};
int nnum[N][2];
void dpp(int i,int nn)
{
    nnum[i][nn]=1e18;
    for(int j=0;j<8;j++)
    {
        if(nn==1 && num[j]==0)continue;
        if(i>cost[j])
        {
            if(dp[i-cost[j]][0]+1<dp[i][nn])
            {
                dp[i][nn]=dp[i-cost[j]][0]+1;
                nnum[i][nn]=num[j];
                pre[i]=i-cost[j];
            }
            else if(dp[i-cost[j]][0]+1==dp[i][nn] && num[j]<nnum[i][nn])
            {
                nnum[i][nn]=num[j];
                pre[i]=i-cost[j];
            }
        }
    }
}
signed main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,0x3f,sizeof(dp));
    for(int j=8;j>=0;j--)
    {
        dp[cost[j]][0]=1;
        nnum[cost[j]][0]=num[j];
        if(num[j]!=0)
        {
            dp[cost[j]][1]=1;
            nnum[cost[j]][1]=num[j];
        }
    }
    for(int i=1;i<=N;i++)//init
    {
        if(dp[i][0]==1)continue;
        dpp(i,0);
        dpp(i,1);
        /////////////////////qu min len

    }
    //cout<<nnum[1][1]<<"\n";
    //cout<<dp[1][1]<<"\n";
    cin>>t;
    while(t--)
    {
        int tmp;
        cin>>tmp;
        if(tmp%7==0)
        {
            for(int j=1;j<=tmp/7;j++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        else if(tmp%7==1)
        {
            cout<<10;
            for(int j=1;j<=tmp/7-1;j++)
            {
                cout<<8;
            }
            cout<<"\n";
            continue;
        }
        if(dp[tmp][1]>=1e18)
        {
            cout<<-1<<"\n";
            continue;
        }
        string outp="";
        int xx=tmp;
        for(int i=1;i<=dp[tmp][1];i++)
        {
            if(xx==tmp)
            {
                outp+=(nnum[xx][1]+'0');
                xx=pre[xx];
                continue;
            }
            outp+=(nnum[xx][0]+'0');
            xx=pre[xx];
        }
        cout<<outp<<"\n";
    }
}






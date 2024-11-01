#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
int n;
int a[N];
int ans;
int dp[N][101][101];
void dfs(int cur,int pre1,int pre2,int sum)
{
    int x=(pre1==-1?0:a[pre1]),y=(pre2==-1?0:a[pre2]);
    if(dp[cur][x][y]>=sum)
    {
        return;
    }
    else
    {
        dp[cur][x][y]=sum;

    }
    if(cur>n)
    {
        ans=max(ans,sum);
        return;
    }
    else
    {
        if(pre1==-1)
        {
            dfs(cur+1,cur,pre2,sum);
        }
        else
        {
            dfs(cur+1,cur,pre2,sum+(a[cur]==a[pre1])*a[cur]);
        }
        if(pre2==-1)
        {
            dfs(cur+1,pre1,cur,sum);
        }
        else
        {
            dfs(cur+1,pre1,cur,sum+(a[cur]==a[pre2])*a[cur]);
        }
    }
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=n;i++) for(int j=0;j<=100;j++) for(int k=0;k<=100;k++) dp[i][j][k]=-1;
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        dfs(1,-1,-1,0);
        cout<<ans<<endl;
    }

    return 0;
}

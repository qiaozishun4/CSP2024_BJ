#include<bits/stdc++.h>
using namespace std;
bool vis[1010][1010],a[1010][1010];
int n,m,k,ans;
void dfs(int x,int y,int d,int step)
{
    if(step==0)return;
    if(d==0)
    {
        if(a[x][y+1])
        {
            if(!vis[x][y+1])ans++;
            vis[x][y+1]=1;
            dfs(x,y+1,d,step-1);
        }
        else dfs(x,y,1,step-1);
    }
    if(d==1)
    {
        if(a[x+1][y])
        {
            if(!vis[x+1][y])ans++;
            vis[x+1][y]=1;
            dfs(x+1,y,d,step-1);
        }
        else dfs(x,y,2,step-1);
    }
    if(d==2)
    {
        if(a[x][y-1])
        {
            if(!vis[x][y-1])ans++;
            vis[x][y-1]=1;
            dfs(x,y-1,d,step-1);
        }
        else dfs(x,y,3,step-1);
    }
    if(d==3)
    {
        if(a[x-1][y])
        {
            if(!vis[x-1][y])ans++;
            vis[x-1][y]=1;
            dfs(x-1,y,d,step-1);
        }
        else dfs(x,y,0,step-1);
    }
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=1;
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                a[i][j]=(c=='.');
                vis[i][j]=0;
            }
        vis[x][y]=1;
        dfs(x,y,d,k);
        cout<<ans<<endl;
    }
    return 0;
}
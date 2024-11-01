#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,ans,cnt;
char w[1005][1005];
int x,y,d;
void dfs(int x,int y,int d)
{
    if(cnt>=k)
    {
        return ;
    }
    if(d==0)
    {
        if(w[x+1][y]=='.')
        {
            ans++;
            cnt++;
            dfs(x+1,y,d);
        }
        else
        {
            cnt++;
            dfs(x,y,(d+1)%4);
        }
    }
    else if(d==1)
    {
        if(w[x][y+1]=='.')
        {
            ans++;
            cnt++;
            dfs(x+1,y,d);
        }
        else
        {
            cnt++;
            dfs(x,y,(d+1)%4);
        }
    }
    else if(d==2)
    {
        if(w[x-1][y]=='.')
        {
            ans++;
            cnt++;
            dfs(x+1,y,d);
        }
        else
        {
            cnt++;
            dfs(x,y,(d+1)%4);
        }
    }
    else if(d==3)
    {
        if(w[x][y-1]=='.')
        {
            ans++;
            cnt++;
            dfs(x+1,y,d);
        }
        else
        {
            cnt++;
            dfs(x,y,(d+1)%4);
        }
    }
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>w[i][j];
            }
        }
        dfs(x,y,d);
        cout<<ans<<'\n';
    }
    return 0;
}

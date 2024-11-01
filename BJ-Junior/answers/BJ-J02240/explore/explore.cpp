#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string s[1005];
int v[1005][1005];
void dfs(int x,int y,int d)
{
    v[x][y]=1;
    if(k==0)
    {
        return ;
    }
    if(d==0)
    {
        if(y+1<m && s[x][y]=='.')
        {
            k--;
            dfs(x,y+1,0);
        }
        else if(x+1<=n && s[x+1][y-1]=='.')
        {
            k--;
            k--;
            dfs(x+1,y,1);
        }
        else if(y-1>0 && s[x][y-2]=='.')
        {
            k--;
            k--;
            k--;
            dfs(x,y-1,2);
        }
        else if(x-1>0 && s[x-1][y-1]=='.')
        {
            k--;
            k--;
            k--;
            k--;
            dfs(x-1,y,3);
        }
        return ;
    }
    if(d==1)
    {
        if(x+1<=n && s[x+1][y-1]=='.')
        {
            k--;
            dfs(x+1,y,1);
        }
        else if(y-1>0 && s[x][y-2]=='.')
        {
            k--;
            k--;
            dfs(x,y-1,2);
        }
        else if(x-1>0 && s[x-1][y-1]=='.')
        {
            k--;
            k--;
            k--;
            dfs(x-1,y,3);
        }
        else if(y+1<m && s[x][y]=='.')
        {
            k--;
            k--;
            k--;
            k--;
            dfs(x,y+1,0);
        }
        return ;
    }
    if(d==2)
    {
        if(y-1>0 && s[x][y-2]=='.')
        {
            k--;
            dfs(x,y-1,2);
        }
        else if(x-1>0 && s[x-1][y-1]=='.')
        {
            k--;
            k--;
            dfs(x-1,y,3);
        }
        else if(y+1<m && s[x][y]=='.')
        {
            k--;
            k--;
            k--;
            dfs(x,y+1,0);
        }
        else if(x+1<=n && s[x+1][y-1]=='.')
        {
            k--;
            k--;
            k--;
            k--;
            dfs(x+1,y,1);
        }
        return ;
    }
    if(d==3)
    {
        if(x-1>0 && s[x-1][y-1]=='.')
        {
            k--;
            dfs(x-1,y,3);
        }
        else if(y+1<m && s[x][y]=='.')
        {
            k--;
            k--;
            dfs(x,y+1,0);
        }
        else if(x+1<=n && s[x+1][y-1]=='.')
        {
            k--;
            k--;
            k--;
            dfs(x+1,y,1);
        }
        else if(y-1>0 && s[x][y-2]=='.')
        {
            k--;
            k--;
            k--;
            k--;
            dfs(x,y-1,2);
        }
        return ;
    }

}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        dfs(x,y,d);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(v[i][j]==1)
                {
                    ans++;
                    v[i][j]=0;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}

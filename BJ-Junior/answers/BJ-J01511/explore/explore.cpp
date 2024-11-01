#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,s=0;
bool a[1005][1005];
void dfs(int x,int y,int d,int step)
{
    if(step==0)
    {
        s++;
        cout<<s<<endl;
        return;
    }
    if(d==0)
    {
        if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&a[x][y+1]==0)
        {
            s++;
            dfs(x,y+1,d,step-1);
        }
        else dfs(x,y,d+1,step-1);
    }
    else if(d==1)
    {
        if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&a[x+1][y]==0)
        {
            s++;
            dfs(x+1,y,d,step-1);
        }
        else dfs(x,y,d+1,step-1);
    }
    else if(d==2)
    {
        if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&a[x][y-1]==0)
        {
            s++;
            dfs(x,y-1,d,step-1);
        }
        else dfs(x,y,d+1,step-1);
    }
    else if(d==3)
    {
        if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&a[x-1][y]==0)
        {
            s++;
            dfs(x-1,y,d,step-1);
        }
        else dfs(x,y,d-3,step-1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        s=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char l;
                cin>>l;
                if(l=='x')a[i][j]=1;
            }
        }
        dfs(x,y,d,k);
    }
    return 0;
}

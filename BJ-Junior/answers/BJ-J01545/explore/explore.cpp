#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char a[1010][1010];
bool vis[1010][1010];
int X[4]={0,1,0,-1},Y[4]={1,0,-1,0};
void calc()
{
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=1;
    vis[x][y]=1;
    for(int i=1;i<=k;i++)
    {
        int dx=x+X[d],dy=y+Y[d];
        if(dx>0&&dx<=n&&dy>0&&dy<=m&&a[dx][dy]=='.')
        {
            if(!vis[dx][dy])
            {
                vis[dx][dy]=1;
                ans++;
            }
            x=dx,y=dy;
        }
        else
        {
            d=(d+1)%4;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        calc();
    }
    return 0;
}
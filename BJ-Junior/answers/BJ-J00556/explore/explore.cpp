#include <bits/stdc++.h>
using namespace std;
char c[1005][1005];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
bool check(int x,int y)
{
    return x<=n&&x>=1&&y<=m&&y>=1&&c[x][y]=='.';
}
int slove(int x,int y,int d,int k)
{
    int sum=1;
    bool vis[1005][1005];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            vis[i][j]=true;
        }
    }
    vis[x][y]=false;
    while(k--)
    {
        int tx=x+dir[d][0];
        int ty=y+dir[d][1];
        if(check(tx,ty))
        {
            x=tx;
            y=ty;
            if(vis[x][y]==true)
            {
                sum++;
                vis[x][y]=false;
            }
        }
        else
        {
            d=(d+1)%4;
        }
    }
    return sum;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,d,k;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        cout<<slove(x,y,d,k)<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                c[i][j]=' ';
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

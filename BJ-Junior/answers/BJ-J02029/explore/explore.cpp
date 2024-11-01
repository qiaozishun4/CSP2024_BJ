#include<iostream>
#include<cstdio>
using namespace std;
int t;
char z[1010][1010];
int vis[1010][1010];
long long ans;
int n,m,xx,yy,dd;
long long k;
void dfs(int x,int y,int d,int k)
{
    if((z[x][y+1]=='x' ||y+1>m) &&(z[x][y-1]=='x' ||y-1<1) &&(z[x+1][y]=='x' ||x+1>n) &&(z[x-1][y]=='x' || x-1<1))
        return;
    if(k==0)
        return;
    if(d==0)
    {
        if(y+1<=m && z[x][y+1]=='.')
        {
            if(vis[x][y+1]==0)
            {
                ans++;
                vis[x][y+1]=1;
            }
            dfs(x,y+1,d,k-1);
        }
        else
        {
            dfs(x,y,(d+1)%4,k-1);
        }
    }
    else if(d==1)
    {
        if(x+1<=n &&z[x+1][y]=='.')
        {
            if(vis[x+1][y]==0)
            {
                ans++;
                vis[x+1][y]=1;
            }
            dfs(x+1,y,d,k-1);
        }
        else
        {
            dfs(x,y,(d+1)%4,k-1);
        }
    }
    else if(d==2)
    {
        if(y-1>=1 &&z[x][y-1]=='.')
        {
            if(vis[x][y-1]==0)
            {
                ans++;
                vis[x][y-1]=1;
            }
            dfs(x,y-1,d,k-1);
        }
        else
        {
            dfs(x,y,(d+1)%4,k-1);
        }
    }
    else if(d==3)
    {
        if(x-1>=1 &&z[x-1][y]=='.')
        {
            if(vis[x-1][y]==0)
            {
                ans++;
                vis[x-1][y]=1;
            }
            dfs(x-1,y,d,k-1);
        }
        else
        {
            dfs(x,y,(d+1)%4,k-1);
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >>t;
    while(t--)
    {
        cin>>n >>m >>k;
        cin >>xx>>yy >>dd;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >>z[i][j];
                vis[i][j]=0;
            }
        }
        vis[xx][yy]=1;
        ans=1;
        dfs(xx,yy,dd,k);
        cout << ans <<"\n";
    }
}

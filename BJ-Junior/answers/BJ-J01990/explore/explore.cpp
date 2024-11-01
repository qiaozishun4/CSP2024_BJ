#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T,k0,n,m,x0,d0,cnt=1;
int f;
char a[1005][1005];
bool vis[1005][1005];
void dfs(int x,int y,int d,int k)
{
    if(k<=0)
    {
        return ;
    }
    if(d==0)
    {
        if(a[x][y+1]=='.' && y+1<=m)
        {
            if(vis[x][y+1]==false)
            {
                cnt++;
                vis[x][y+1]=true;
            }
            dfs(x,y+1,d,k-1);
        }
        else
        {
            d=(d+1)%4;
            dfs(x,y,d,k-1);
        }
    }

    if(d==1)
    {
        if(a[x+1][y]=='.' && x+1<=n)
        {
            if(vis[x+1][y]==false)
            {
                cnt++;
                vis[x+1][y]=true;
            }
            dfs(x+1,y,d,k-1);
        }
        else
        {
            d=(d+1)%4;
            dfs(x,y,d,k-1);
        }
    }
    if(d==2)
    {
        if(a[x][y-1]=='.' && y-1>=1)
        {
            if(vis[x][y-1]==false)
            {
                cnt++;
                vis[x][y-1]=true;
            }
            dfs(x,y-1,d,k-1);
        }
        else
        {
            d=(d+1)%4;
            dfs(x,y,d,k-1);
        }
    }

    if(d==3)
    {
        if(a[x-1][y]=='.' && x-1>=1)
        {
            if(vis[x-1][y]==false)
            {
                cnt++;
                vis[x-1][y]=true;
            }
            dfs(x-1,y,d,k-1);
        }
        else
        {
            d=(d+1)%4;
            dfs(x,y,d,k-1);
        }
    }

}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T)
    {
        memset(a,0,sizeof(a));
        memset(vis,false,sizeof(vis));
        cnt=1;
        cin >> n >> m >> k0;
        cin >> x0 >> f >> d0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
            }
        }
        vis[x0][f]=true;
        dfs(x0,f,d0,k0);
        cout << cnt << endl;
        T--;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int m,n,k,d;
int cnt=0;
char g[N][N];
int h[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int d)
{
    for(int j=d;j<4+d;j++)
    {
        k--;
        int i=j%4;
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>n || nx<1 || ny>m || ny<1) continue;
        if(g[nx][ny]=='x') continue;
        if(k<0) continue;
        h[nx][ny]=1;
        dfs(nx,ny,i);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        memset(h,0,sizeof h);
        int x,y;
        cin >>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >>g[i][j];
            }
        }
        dfs(x,y,d);
        h[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(h[i][j])
                {
                    cnt++;
                }
            }
        }
        cout <<cnt<<'\n';
        cnt=0;
    }
    return 0;
}

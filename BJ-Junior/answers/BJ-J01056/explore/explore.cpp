#include <bits/stdc++.h>
using namespace std;
long long n, m, d, k, x, y, nx, ny, t;
bool v[1005][1005], vis[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    std::cin>>t;
    while(t--)
    {
        std::cin>>n>>m>>k;
        std::cin>>x>>y>>d;
        long long ans=0;
        memset(v, 0, sizeof(v));
        memset(vis, 0, sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char q;
                std::cin>>q;
                if(q=='x') {v[i][j]=1;}
            }
        }
        while(k--)
        {
            vis[x][y]=1;
            if(d==0) nx=x, ny=y+1;
            if(d==1) nx=x+1, ny=y;
            if(d==2) nx=x, ny=y-1;
            if(d==3) nx=x-1, ny=y;
            if(v[nx+1][ny] && v[nx-1][ny] && v[nx][ny+1] && v[nx][ny-1]) break;
            if(nx<1 || ny<1 || nx>n || ny>m || v[nx][ny])
            {
                d=(d+1)%4;
                continue;
            }
            x=nx, y=ny;
        }
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) ans++;
            }
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}

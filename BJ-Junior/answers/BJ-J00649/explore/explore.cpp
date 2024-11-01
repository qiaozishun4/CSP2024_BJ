#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,stx,sty,sd,dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
bool inb(int x,int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main()
{
    //remember to freopen
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t --)
    {
        //reset
        cin >> n >> m >> k;
        cin >> stx >> sty >> sd;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                vis[i][j] = 0;
                cin >> mp[i][j];
            }
        }
        int x = stx,y = sty,d = sd,step = 0,ans = 1;
        while(1)
        {
            vis[x][y] = 1;
            if(step == k)   break;
            int nx = x + dx[d];
            int ny = y + dy[d];
            int ch = 0;
            while((!inb(nx,ny) || mp[nx][ny] == 'x') && ch < 4)
            {
                step ++;
                if(step == k)   break;
                d = (d + 1) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
                ch ++;
            }
            if(step == k)   break;
            if(!inb(nx,ny) || mp[nx][ny] == 'x')    break;
            if(!vis[nx][ny])    ans ++;
            x = nx;
            y = ny;
            step ++;
        }
        cout << ans << '\n';
    }
    return 0;
}

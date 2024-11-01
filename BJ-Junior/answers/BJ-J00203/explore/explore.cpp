#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
bool vis[1005][1005];
char a[1005][1005];
int dx(int d,int x)
{
    if(d == 0) return x;
    else if(d == 1) return x + 1;
    else if(d == 2) return x;
    else return x - 1;
}
int dy(int d,int y)
{
    if(d == 0) return y + 1;
    else if(d == 1) return y;
    else if(d == 2) return y - 1;
    else return y;
}
bool check(int nx,int ny)
{
    if(nx < 1 || nx > n || ny < 1 || ny > m) return 0;
    if(a[nx][ny] == 'x') return 0;
    return 1;
}
void solve()
{
    memset(vis,0,sizeof vis);
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> a[i][j];
    vis[x][y] = 1;
    while(k--)
    {
        int nx = dx(d,x);
        int ny = dy(d,y);
        if(check(nx,ny))
        {
            x = nx,y = ny;
        }
        else
        {
            d = (d + 1) % 4;
        }
        vis[x][y] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            ans += vis[i][j];
    cout << ans << '\n';
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}

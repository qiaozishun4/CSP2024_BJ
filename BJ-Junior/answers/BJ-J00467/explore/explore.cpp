#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int t,n,m,k,x,y,d;
bool vis[N][N];
char g[N][N];
int dfs(int x,int y,int d,int cur,int cnt)
{
    if (cur > k) return cnt;
    if (!vis[x][y])
    {
        cnt++;
        vis[x][y] = 1;
    }
    int dx = x,dy = y;
    if (!d) dy++;
    else if (d == 1) dx++;
    else if (d == 2) dy--;
    else if (d == 3) dx--;
    if (dx < 1 || dx > n || dy < 1 || dy > m || g[dx][dy] == 'x') return dfs(x,y,(d + 1) % 4,cur + 1,cnt);
    return dfs(dx,dy,d,cur + 1,cnt);
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d", &t);
    while (t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d%d%d%d", &n,&m,&k,&x,&y,&d);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> g[i][j];
        printf("%d\n", dfs(x,y,d,0,0));
    }
    return 0;
}

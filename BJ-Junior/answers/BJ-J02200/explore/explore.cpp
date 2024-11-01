#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int n,m,k;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(int x,int y,int cur,int now)
{
    if(now == k+1) return ;
    vis[x][y] = 1;
    int nx = x + dx[cur];
    int ny = y + dy[cur];
    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
    {
        dfs(nx,ny,cur,now+1);
    }
    else dfs(x,y,(cur+1)%4,now+1);
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin >> T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(x,y,d,0);
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(vis[i][j]) cnt++;
            }
        }
        cout << cnt << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

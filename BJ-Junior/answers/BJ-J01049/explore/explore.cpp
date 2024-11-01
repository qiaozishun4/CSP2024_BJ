#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
bool vis[1005][1005];
char a[1005][1005];
bool f;
int dx[5] = {0,1,0,-1};
int dy[5] = {1,0,-1,0};

void dfs(int x,int y,int d)
{
    if(f) return;
    k--;
    if(k == -1) f = 1;
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(a[x][y] == 'x') return;
    if(!vis[x][y])
    {
        vis[x][y] = 1;
        ans++;
    }
    for(int i = 1;i <= 4;i++)
    {
        if(f) break;
        dfs(x+dx[d],y+dy[d],d);
        d = (d+1)%4;
    }
}


int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        f = 0;
        memset(vis,0,sizeof(vis));
        int x,y,d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(x,y,d);
        cout << ans << endl;
    }
    return 0;
}

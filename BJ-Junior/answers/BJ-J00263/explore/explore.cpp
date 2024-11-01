#include<bits/stdc++.h>

using namespace std;

bool vis[1002][1002];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k;
    int sx,sy,st;
    int ans = 0;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        cin >> sx >> sy >>st;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                char c;
                cin >> c;
            }
        }
        while (k--)
        {
            sx = sx + dx[st];
            sy = sy + dy[st];
            if (sx<1 || sx>n || sy<1 || sy>m )
            {
                sx = sx - dx[st];
                sy = sy - dy[st];
                st = (st+1) % 4;
            }
            else
            {
                vis[sx][sy] = true;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                ans += vis[i][j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}


/*
#include<bits/stdc++.h>

using namespace std;

int t,n,m,k,ans;
int sx,sy,st;
bool a[1002][1002];
bool vis[1002][1002];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void dfs(int d,int x,int y,int z)
{
    vis[x][y] = true;
    if (d == k)
    {
        ans = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                if (vis[i][j])
                    ans++;
            }
        }
        exit(0);
        return;
    }

    int nx = x + dx[z];
    int ny = y + dy[z];
    if (nx<1 || nx>n || ny<1 || ny>m || !a[nx][ny])
    {
        z = (z+1)%4;
        dfs(d+1,x,y,z);
    }
    else
    {
        vis[nx][ny] = true;
        dfs(d+1,nx,ny,z);
    }
    return;
}

int main()
{
    //freopen("explore.in","r",stdin);
    //freopen("explore.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        cin >> sx >> sy >> st;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                char c;
                cin >> c;
                if (c == '.')
                    a[i][j] = true;
                else
                    a[i][j] = false;
            }
        }
        for (int i = 0;i <= n;i++)
        {
            for (int j = 0;j <= m;j++)
            {
                vis[i][j] = false;
            }
        }
        cout << "output:"<< ans << "\n";
        dfs(0,sx,sy,st);
        cout << "output:"<< ans << "\n";
    }
    return 0;
}
*/

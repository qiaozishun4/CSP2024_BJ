#include <iostream>
using namespace std;

int n, m, k;
char a[1010][1010];
bool vis[1010][1010];
bool check(int x, int y)
{
    if(x <= 0 || y <= 0 || x > n || y > m)return false;
    if(a[x][y] == 'x')return false;
    return true;
}
void dfs(int step, int x, int y, int d)
{
    if(!check(x, y))return;
    if(step > k)return;
    vis[x][y] = 1;
    if(d == 0)
    {
        if(check(x, y + 1))dfs(step + 1, x, y + 1, d);
        else dfs(step + 1, x, y, (d + 1) % 4);
    }
    if(d == 1)
    {
        if(check(x + 1, y))dfs(step + 1, x + 1, y, d);
        else dfs(step + 1, x, y, (d + 1) % 4);
    }
    if(d == 2)
    {
        if(check(x, y - 1))dfs(step + 1, x, y - 1, d);
        else dfs(step + 1, x, y, (d + 1) % 4);
    }
    if(d == 3)
    {
        if(check(x - 1, y))dfs(step + 1, x - 1, y, d);
        else dfs(step + 1, x, y, (d + 1) % 4);
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(0, x0, y0, d0);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j])cnt++;
                vis[i][j] = 0;
                a[i][j] = 'x';
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

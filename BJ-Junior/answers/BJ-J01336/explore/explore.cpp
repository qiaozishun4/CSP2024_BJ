#include <iostream>
using namespace std;

const int N = 1e3 + 5;
int n, m, k, cnt, ans = 1;
char c[N][N];
bool vis[N][N];

bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] == '.';
}

void dfs(int x, int y, int d)
{
    if (cnt == k)
    {
        return;
    }
    vis[x][y] = true;
    if (!d)
    {
        cnt += 1;
        if (check(x, y + 1))
        {
            if (!vis[x][y + 1])
            {
                ans += 1;
            }
            dfs(x, y + 1, d);
        }
        else
        {
            dfs(x, y, (d + 1) % 4);
        }
    }
    else if (d == 1)
    {
        cnt += 1;
        if (check(x + 1, y))
        {
            if (!vis[x + 1][y])
            {
                ans += 1;
            }
            dfs(x + 1, y, d);
        }
        else
        {
            dfs(x, y, (d + 1) % 4);
        }
    }
    else if (d == 2)
    {
        cnt += 1;
        if (check(x, y - 1))
        {
            if (!vis[x][y - 1])
            {
                ans += 1;
            }
            dfs(x, y - 1, d);
        }
        else
        {
            dfs(x, y, (d + 1) % 4);
        }
    }
    else
    {
        cnt += 1;
        if (check(x - 1, y))
        {
            if (!vis[x - 1][y])
            {
                ans += 1;
            }
            dfs(x - 1, y, d);
        }
        else
        {
            dfs(x, y, (d + 1) % 4);
        }
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t --)
    {
        int x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; ++ i)
        {
            for (int j = 1; j <= m; ++ j)
            {
                cin >> c[i][j];
            }
        }
        dfs(x, y, d);
        cout << ans << endl;
        cnt = 0;
        ans = 1;
    }
    return 0;
}
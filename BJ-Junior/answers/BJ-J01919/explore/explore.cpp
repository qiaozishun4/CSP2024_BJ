#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
bool a[1005][1005], f[1005][1005];
int go[5][5] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y, int d, int z)
{
    if(!z)
        return;
    int nx = x + go[d][0], my = y + go[d][1];
    if(nx <= n && nx >= 1 && my <= m && my >= 1 && a[nx][my])
    {
        if(!f[nx][my])
        {
            ++ans;
            f[nx][my] = true;
        }
        dfs(nx, my, d, z-1);
    }
    else
        dfs(x, y, (d+1)%4, z-1);
    return;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                char op;
                cin >> op;
                if(op == '.')
                    a[i][j] = true;
                else
                    a[i][j] = false;
                f[i][j] = false;
            }
        }
        f[x][y] = true;
        ans = 1;
        dfs(x, y, d, k);
        printf("%d\n", ans);
    }
    return 0;
}


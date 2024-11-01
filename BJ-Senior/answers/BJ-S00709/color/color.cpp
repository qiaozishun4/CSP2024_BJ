#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T, n, a[100005], last[100005], b[2005];
long long ans, f[2005][2005], maxn[2005];
bool flag, vis[2005][2005];

void update(int x, int y, int z)
{
    if(x > y)  swap(x, y);
    if(vis[x][y])
    {
        f[x][y] += z;
        f[x][y] = max(f[x][y], maxn[x + y - z]);
        maxn[x] = max(maxn[x], f[x][y]);
        maxn[y] = max(maxn[y], f[x][y]);
        ans = max(ans, f[x][y]);
    }
    if(!vis[x][y] && vis[0][x + y - z])
    {
        vis[x][y] = true;
        f[x][y] = maxn[x + y - z];
    }
    if(!vis[0][z])
    {
        vis[0][z] = true;
        f[0][z] = maxn[z];
    }
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        ans = 0, flag = false;
        memset(b, 0, sizeof(b));
        memset(maxn, 0, sizeof(maxn));
        memset(vis, 0, sizeof(vis));

        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] > 2000)  flag = true;
            last[i] = b[a[i]];
            if(b[a[i]] > 0)  ans += a[i];
            b[a[i]] = i;
        }
        if(flag)
        {
            printf("%lld\n", ans);
            continue;
        }
        ans = 0;
        f[0][0] = 0;
        vis[0][0] = true;
        for(int i = 1; i <= n; i++)
        {
            update(a[i], a[i], a[i]);
            for(int j = 1; j <= 2000; j++)
            {
                if(j == a[i])  continue;
                update(a[i], j, a[i]);
            }
        /*printf("%d: %lld %lld\n", i, ans);
        for(int i = 0; i <= 5; i++)
        {
            for(int j = 0; j <= 5; j++)  if(vis[i][j])printf("%lld ", f[i][j]);  else  printf("* "); printf("=%lld\n", maxn[i]);
        }*/
        }
        printf("%lld\n", ans);
    }
    return 0;
}

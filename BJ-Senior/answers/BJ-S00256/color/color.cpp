#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[20], color[20], c[20], n, ans;

void dfs(int pos, int col)
{
    if (pos > n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == 1) continue;
            for (int j = i - 1; j >= 1; j--)
            {
                if (color[j] == color[i])
                {
                    if (a[j] == a[i])
                    {
                        c[i] = a[i];
                    }
                    break;
                }
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += c[i];
        }
        ans = max(ans, sum);
        return ;
    }
    color[pos] = col;
    dfs(pos + 1, 0);
    dfs(pos + 1, 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        dfs(1, 0);
        dfs(1, 1);
        printf("%d\n", ans);
    }
    return 0;
}

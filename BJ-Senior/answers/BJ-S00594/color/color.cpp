#include <bits/stdc++.h>

using namespace std;
const int MAX = 2e5;
int n, ar[MAX+5];
int ans;

void dfs(int u, int r, int b, int sco)
{
    if (u >= n) { ans = max(ans, sco); return; }
    int i = u+1;
    if (ar[r] == ar[i]) dfs(i, i, b, sco+ar[i]);
    else dfs(i, i, b, sco);
    if (ar[b] == ar[i]) dfs(i, r, i, sco+ar[i]);
    else dfs(i, r, i, sco);
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
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &ar[i]);
        }
        dfs(0, 0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}

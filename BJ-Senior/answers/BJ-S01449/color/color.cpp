#include <cstdio>
#include <iostream>
using namespace std;

int T, n, ans, a[105], c[105];
void dfs(int x)
{
    if (x > n)
    {
        int r0 = 0, b1 = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] == 0)
            {
                if (a[i] == r0)
                {
                    sum += a[i];
                }
                r0 = a[i];
            }
            else
            {
                if (a[i] == b1)
                {
                    sum += a[i];
                }
                b1 = a[i];
            }
        }
        ans = max(ans, sum);
        return;
    }
    c[x] = 0;
    dfs(x + 1);
    c[x] = 1;
    dfs(x + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}
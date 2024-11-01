#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200005], n, f[200005], maxn;
void dfs(int step)
{
    if (step > n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j; j--)
            {
                if (f[j] == f[i] && a[j] == a[i])
                {
                    sum += a[i];
                }
            }
        }
        maxn = max(maxn, sum);
        return;
    }
    f[step] = 1;
    dfs(step + 1);
    f[step] = 2;
    dfs(step + 1);
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    maxn = -1;
    dfs(1);
    cout << maxn << endl;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    for (cin >> t; t; t--)
    {
        solve();
    }
    return 0;
}

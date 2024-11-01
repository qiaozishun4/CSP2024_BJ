#include <bits/stdc++.h>
using namespace std;

int n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long ans = 1e18;

void dfs(int cnt, long long sum)
{
    if (sum > ans) return;
    if (cnt == 1) return;
    if (cnt == 0)
    {
        ans = min(ans, sum);
        return;
    }
    if (cnt == 0)
    {
        ans = min(ans, sum);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 0 && sum == 0) continue;
        if (a[i] <= cnt)
        {
            dfs(cnt - a[i], sum * 10 + i);
        }
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++) cout << 8;
            continue;
        }
        if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i < (n - 1) / 7; i++) cout << 8;
        }
        ans = 1e18;
        dfs(n, 0);
        cout << ans << endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[25], n, x[20], ans;

int check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 1; j--)
            if (x[i] == x[j])
            {
                if (a[i] == a[j]) cnt += a[i];
                break;
            }
    return cnt;
}

void dfs(int step)
{
    if (step == n)
    {
        ans = max(ans, check());
        return;
    }
    x[step + 1] = 0;
    dfs(step + 1);
    x[step + 1] = 1;
    dfs(step + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
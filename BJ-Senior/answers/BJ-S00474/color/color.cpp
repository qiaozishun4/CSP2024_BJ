#include <bits/stdc++.h>
using namespace std;

int T, n, a[20], col[20], ans;

void dfs(int step)
{
    if (step > n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int j = i - 1; j >= 1; j--)
            {
                if (col[i] == col[j])
                {
                    if (a[i] == a[j])
                        sum += a[i];
                    flag = false;
                    break;
                }
                if (!flag) break;
            }
        }
        ans = max(ans, sum);
        return ;
    }
    dfs(step + 1);
    col[step] = 1;
    dfs(step + 1);
    col[step] = 0;
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
            cin >> a[i];
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}

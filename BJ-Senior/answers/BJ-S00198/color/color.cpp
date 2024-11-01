#include <iostream>
#include <cstring>
using namespace std;
const int NR = 200010;
int f[110][110][2];
int a[NR], aft[NR], n, ans;
void dfs(int step)
{
    if (step > n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 1; j--)
                if (aft[i] == aft[j])
                {
                    if (a[i] == a[j]) sum += a[i];
                    break;
                }
        }
        ans = max(ans, sum);
        return;
    }
    aft[step] = 1; dfs(step + 1);
    aft[step] = 2; dfs(step + 1);
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T; cin >> T;
    while (T--)
    {
        cin >> n; ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n <= 15)
        {
           dfs(1);
           cout << ans << '\n';
        }
        else if (n <= 100)
        {
            memset(f, 0, sizeof f);
            for (int i = 1; i <= n; i++)
                for (int j = 0; j <= i - 1; j++)
                {
                    for (int l = 0; l <= j - 1; l++)
                    {
                        f[i][j][0] = max(f[j][l][0] + ((a[i] == a[j]) ? a[i] : 0), f[i][j][0]);
                        f[i][j][1] = max(f[j][l][1] + ((a[i] == a[j]) ? a[i] : 0), f[i][j][1]);
                    }
                    for (int k = 1; k <= i; k++)
                        for (int l = 0; l <= k - 1; l++)
                        {
                            // if (i == 6)
                            // {
                            //    cout << k << " " << l << " " << i << " " << j << '\n';
                            //    cout << (i == k) << " " << (i == l) << " " << (j == k) << " " << (j == l) << '\n';
                            // }
                            if (i == k || i == l || j == k || j == l) continue;
                            f[i][j][0] = max(f[i][j][0], f[k][l][1] + ((a[i] == a[j]) ? a[i] : 0));
                            // cout << k << " " << l << " " << f[k][l][1] << " " << f[i][j][0] << '\n';
                            f[i][j][1] = max(f[i][j][1], f[k][l][0] + ((a[i] == a[j]) ? a[i] : 0));
                        }
                    // printf("f[%d][%d][0, 1] = %d %d\n", i, j, f[i][j][0], f[i][j][1]);
                }
            int ans = 0;
            for (int i = 1; i <= n - 1; i++)
                ans = max(ans, max(f[n][i][0], f[n][i][1]));
            cout << ans << '\n';
        }
    }
    return 0;
}

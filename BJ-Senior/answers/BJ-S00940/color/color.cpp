#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010], n, ans;
int color[100010];
int add()
{
    int sum = 0;
    for (int i = 2; i <= n; ++i)
    {//1 2 1 2 1 2 1 2 1 2 1 2 1 2 1
        for (int j = 1; j < i; ++j)
        {
            if (color[i] == color[j] && a[i] == a[j])
            {
                sum += a[i];
                j = i;
            }
        }
    }
    return sum;
}
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n / 2; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                color[j] = 0;
            }
            for (int j = i + 1; j <= n; ++j) color[j] = 1;
            do
            {
                ans = max(ans, add());
            }while (next_permutation(color + 1, color + n + 1));
        }
        cout << ans << "\n";
    }
    return 0;
}

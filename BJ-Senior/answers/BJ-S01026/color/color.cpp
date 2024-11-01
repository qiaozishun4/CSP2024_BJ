//50pts. Maybe it will RE on #11
#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[2002][2002], mx[2005], s[2005], a[2005], lst[2005];
int _;
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%lld", &_);
    while (_--)
    {
        int n;
        scanf("%lld", &n);
        // if (n > 2e3)
        //     return 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            s[i] = s[i - 1] + (a[i] == a[i - 1]) * a[i];
            // printf("%lld ", s[i]);
        }
        // puts("");
        memset(f, 0, sizeof f);
        memset(lst, 0, sizeof lst);
        memset(mx, 0, sizeof mx);
        int ans = 0;
        for (int l = 1; l <= n; l++)
        {
            for (int r = l; r <= n; r++)
            {
                // for (int k = 1; k < l; k++)
                // {
                //     f[l][r] = max(f[l][r], f[k][l - 1]);
                // }
                f[l][r] = max(f[l][r], mx[l - 1]);
                if (lst[a[l]] != 0 && lst[a[l]] != l - 1)
                {
                    f[l][r] = max(f[l][r], f[lst[a[l]] + 1][l - 1] + a[l]);
                // if (l == 4 && r == 4)
                //     printf("%lld\n", f[l][r]);
                    // f[1][l][r] = max(f[1][l][r], f[0][lst[a[l]] + 1][l - 1] + a[l]);
                }
                f[l][r] += s[r] - s[l];
                ans = max(ans, f[l][r]);
                mx[r] = max(f[l][r], mx[r]);
                // printf("f[%lld, %lld] = %lld\n", l, r, f[l][r]);
            }
            lst[a[l]] = l;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
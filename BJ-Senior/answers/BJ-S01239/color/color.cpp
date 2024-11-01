#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N (200000 + 10)
typedef long long ll;

inline ll C(int a, int b)
{
    return a == b ? a : 0;
}

int a[N];
ll f[2][N];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        memset(f, 0, sizeof(f));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                f[i & 1][j] = max(f[i & 1][j], f[(i - 1) & 1][j] + C(a[i], a[i - 1]));
            }
            for (int j = 1; j < i - 1; j++)
            {
                f[i & 1][i - 1] = max(f[i & 1][i - 1], f[(i - 1) & 1][j] + C(a[i], a[j]));
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f[n & 1][i]);
        printf("%lld\n", ans);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
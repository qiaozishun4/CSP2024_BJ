#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;

const LL N = 1e5 + 5;
const LL M = 5e3 + 5;

LL a[N], ai[N], c[N], x[N];
char d[M][M];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    LL n, m;
    cin >> n >> m;
    for (LL i = 1; i <= n; i++)
        cin >> ai[i];
    for (LL i = 1; i <= m; i++)
        cin >> c[i];
    LL k = 0;
    while (pow(2, k) < n) k++;
    for (LL i = 1; i <= k; i++)
    {
        LL x = pow(2, k - i);
        for (LL j = 1; j <= x; j++)
            cin >> d[i][j];
    }
    LL T;
    cin >> T;
    for (LL tst = 1; tst <= T; tst++)
    {
        for (LL i = 0; i < 4; i++)
            cin >> x[i];
        LL ans = 0;
        for (LL i = 1; i <= n; i++)
        {
            a[i] = (ai[i] ^ x[i % 4]);
            ans += a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}

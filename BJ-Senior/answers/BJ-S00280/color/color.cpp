#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;
const int M = 1e6 + 5;

int a[N], cnt[M];
bool vis[M];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    LL T;
    cin >> T;
    for (LL tst = 1; tst <= T; tst++)
    {
        memset(cnt, 0, sizeof cnt);
        memset(vis, false, sizeof vis);
        LL n;
        cin >> n;
        for (LL i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        LL ans = 0;
        for (LL i = 1; i <= n; i++)
        {
            if (vis[a[i]]) continue;
            vis[a[i]] = true;
            ans += 1LL * (cnt[a[i]] - 1) * a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}

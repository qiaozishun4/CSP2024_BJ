#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005, M = 1000005;
int n, a[N], lst[N], pos[M], dp[N][2];
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(lst, 0, sizeof(lst));
        memset(pos, 0, sizeof(pos));
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (pos[a[i]] == 0) lst[i] = 0;
            else lst[i] = pos[a[i]];
            pos[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            int nmax = max(dp[i - 1][0], dp[i - 1][1]);
            if (lst[i] == 0) {
                dp[i][0] = dp[i][1] = nmax;
            } else {
                dp[i][0] = max(nmax, dp[i - 1][1] + a[i]);
                dp[i][1] = max(nmax, dp[i - 1][0] + a[i]);
            }
        }
        cout << max(dp[n][0], dp[n][1]) << '\n';
    }
    return 0;
}

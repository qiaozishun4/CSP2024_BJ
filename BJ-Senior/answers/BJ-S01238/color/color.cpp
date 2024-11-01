#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],dp[3][200005];
int mx;
inline void init () {
    memset(dp,0,sizeof(dp));
    return;
}
inline void slv () {
    int z = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= 10;j++) {//i & i-1 ,same color
            if ((z & (1ll << j)) == 0) {
                continue;
            }
            if (a[i] == a[i - 1]) {
                dp[i & 1][j] = max(dp[i & 1][j],dp[(i - 1) & 1][j] + a[i]);
            } else {
                dp[i & 1][j] = max(dp[i & 1][j],dp[(i - 1) & 1][j]);
            }
        }
        for (int j = 0;j <= 10;j++) {//i & i-1 ,different color
            if (a[i] == j) {
                dp[i & 1][a[i - 1]] = max(dp[i & 1][a[i - 1]],dp[(i - 1) & 1][j] + a[i]);
            } else {
                dp[i & 1][a[i - 1]] = max(dp[i & 1][a[i - 1]],dp[(i - 1) & 1][j]);
            }
        }
        z |= (1ll << a[i - 1]);
    }
    int ans = 0;
    for (int i = 0;i < n;i++) {
        ans = max(ans,dp[n & 1][i]);
    }
    cout << ans << endl;
    return;
}
signed main () {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while (T--) {
        init();
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        if (n > 2e4) {
            slv();
            continue;
        }
        for (int i = 1;i <= n;i++) {
            for (int j = 0;j < i - 1;j++) {//i & i-1 ,same color
                if (a[i] == a[i - 1]) {
                    dp[i & 1][j] = max(dp[i & 1][j],dp[(i - 1) & 1][j] + a[i]);
                } else {
                    dp[i & 1][j] = max(dp[i & 1][j],dp[(i - 1) & 1][j]);
                }
            }
            for (int j = 0;j < i - 1;j++) {//i & i-1 ,different color
                if (a[i] == a[j]) {
                    dp[i & 1][i - 1] = max(dp[i & 1][i - 1],dp[(i - 1) & 1][j] + a[i]);
                } else {
                    dp[i & 1][i - 1] = max(dp[i & 1][i - 1],dp[(i - 1) & 1][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0;i < n;i++) {
            ans = max(ans,dp[n & 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
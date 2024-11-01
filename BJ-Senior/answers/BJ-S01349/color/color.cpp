#include <bits/stdc++.h>
using namespace std;

int a[1000005], ans, b[1000005], n, dp[105][105][105];
void dfs(int step) {
    if(step > n) {
        int sum1 = 0, sum2 = 0, sum3 = 0;
        for (int i = 1; i <= n; ++i) {
            if(b[i] == 1 && a[i] == sum1) {
                sum3 += a[i];
            }
            if(b[i] == 1) sum1 = a[i];
            if(b[i] == 2 && a[i] == sum2) {
                sum3 += a[i];
            }
            if(b[i] == 2) sum2 = a[i];
        }
        ans = max(ans, sum3);
        return;
    }
    b[step] = 1;
    dfs(step + 1);
    b[step] = 2;
    dfs(step + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        if(n <= 15) {
            ans = 0;
            dfs(1);
            cout << ans << "\n";
        } else if(n <= 100) {
            for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) for (int k = 1; k <= n; ++k) dp[i][j][k] = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= i; ++j) {
                    for (int k = 1; k <= i; ++k) {
                        dp[i + 1][i + 1][k] = max(dp[i + 1][i + 1][k], dp[i][j][k] + ((a[i + 1] == a[j]) ? a[i + 1] : 0));
                        dp[i + 1][j][i + 1] = max(dp[i + 1][j][i + 1], dp[i][j][k] + ((a[i + 1] == a[k]) ? a[i + 1] : 0));
                    }

                }
            }
            int ans = 0;
            for (int i = 1; i < n; ++i) {
                ans = max(ans, max(dp[n][i][n], dp[n][n][i]));
            }
            cout << ans << "\n";
        }

    }
    return 0;
}

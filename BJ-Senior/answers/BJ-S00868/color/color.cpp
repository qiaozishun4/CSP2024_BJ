#include<iostream>
#include<cstdio>
using namespace std;

int T, n, num[200001], dp[200001][2]; // dp[i]: i ~ n

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1;i <= n;i++)
            cin >> num[i];
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1;i >= 1;i--) {
            dp[i][0] = dp[i][1] = max(dp[i + 1][0], dp[i + 1][1]);
            for (int j = i + 1;j <= n;j++) {
                if (num[j] == num[i]) {
                    dp[i][0] += num[i];
                    dp[i][1] += num[i];
                    break;
                }
            }
        }
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
    return 0;
}

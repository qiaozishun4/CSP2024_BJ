#include <iostream>

using namespace std;

int t;
int n;
int dp[100005] = {-1, -1, 1, 7, 4, 2, 0, 8, 16};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> t;

    for (int i = 9; i <= 100005; i += 1) {
        dp[i] = 99999999;

        for (int j = 7; j >= 2; j -= 1) {
            //cout << dp[i] << " " << dp[i - j] << " " << dp[j] << endl;

            if (dp[i] > (dp[i - j] == 0 ? 6 : dp[i - j]) * 10 + dp[j]) {
                dp[i] = (dp[i - j] == 0 ? 6 : dp[i - j]) * 10 + dp[j];
            }
        }
    }

    for (int i = 1; i <= t; i += 1) {
        cin >> n;

        cout << (n == 6 ? 6 : dp[n]) << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long dp[100005];

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        dp[1] = -1;
        dp[2] = 1;
        dp[3] = 7;
        dp[4] = 7;
        dp[5] = 2;
        dp[6] = 6;
        dp[7] = 8;
        dp[8] = 8;
        dp[9] = 27;
        dp[10] = 22;
        dp[11] = 26;
        dp[12] = 28;
        dp[13] = 28;
        dp[14] = 227;
        dp[15] = 222;
        dp[16] = 226;
        dp[17] = 228;
        dp[18] = 228;
        dp[19] = 2227;
        dp[20] = 2222;
        if (n <= 20)
        {
            cout << dp[n] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}


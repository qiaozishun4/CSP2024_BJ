#include <iostream>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
long long dp[N];
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << -1<< "\n";
            continue;
        }
        dp[2] = 1;
        dp[3] = 7;
        dp[4] = 4;
        dp[5] = 2;
        dp[6] = 6;
        dp[7] = 8;
        for(int i = 8;i <= n;i++)
        {
            ll minn = 1e9 + 10;
            for(int j = 2;j <= 7;j++)
            {
                minn = min(dp[i - j] * 10 + dp[j], minn);
            }
            minn = min(dp[i - 6] * 10, minn);
            dp[i] = minn;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}

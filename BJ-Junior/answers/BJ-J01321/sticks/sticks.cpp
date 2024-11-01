#include <bits/stdc++.h>
using namespace std;
string dp[10];
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    dp[0] = "";
    dp[1] = "10";
    dp[2] = "1";
    dp[3] = "7";
    dp[4] = "20";
    dp[5] = "2";
    dp[6] = "6";
    dp[7] = "6";
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if(t == 0 || t == 1) cout << "-1\n";
        else
        {
            int k = t % 7;
            int t1 = t / 7;
            if(k==1 || k==4) t1--;
            cout << dp[k];
            for(int i = 1; i <= t1; i++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}

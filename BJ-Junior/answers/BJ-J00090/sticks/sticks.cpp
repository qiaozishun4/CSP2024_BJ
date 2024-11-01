/*
    Glory Glory Man Untied
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int n, ans = 2e9 + 1;
string dp[N];
char dp1[N];
// int len[N];

bool comp(string x, string y)
{
    if (x == y) return true;
    if (x.size() < y.size()) return true;
    if (x.size() > y.size()) return false;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] < y[i]) return true;
        if (x[i] > y[i]) return false;
    }
    return true;
}

signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    dp[1] = "-1", dp1[2] = '1', dp1[3] = '7', dp1[4] = '4', dp1[5] = '2', dp1[6] = '6', dp1[7] = '8', dp1[8] = '1', dp[8] = "0", dp1[9] = '1', dp[9] = "8", dp1[10] = '2', dp[10] = "2", dp1[11] = '2', dp[11] = "0", dp[12] = "8", dp1[12] = '2';
    // len[2] = len[3] = len[4] = len[5] = len[6] = len[7] = 1, len[8] = len[9] = len[10] = len[11] = len[12] = 2;
    for (int i = 13; i <= 1e5; i++)
    {
        string x;
        x += dp1[i - 6];
        x += "0";
        //cout << dp[i - 6][0]  << " x:" << x << "-- ";
        x += dp[i - 6];
        //cout << x << " ";
        string y = dp1[i - 7] + dp[i - 7] + "8"; 
        if (comp(x, y)) 
        {
            dp[i] = "0" + dp[i - 6], dp1[i] = dp1[i - 6]; 
        }
        else 
        {
            dp[i] = dp[i - 7] + "8", dp1[i] = dp1[i - 7]; 
        }
    } 
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        cout << dp1[n] << dp[n] << endl;
    }
    return 0;
}
/*
1
100000
*/
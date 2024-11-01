#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int NR = 2e5 + 5;
int n;
int a[NR];
int dp[103][103][103];
int dfs(int pos, int red, int blue)
{
    if(pos > n) return 0;
    if(dp[pos][red][blue] != -1) return dp[pos][red][blue];
    int ret1 = (red == a[pos]) * a[pos] + dfs(pos + 1, a[pos], blue);
    int ret2 = (blue == a[pos]) * a[pos] + dfs(pos + 1, red, a[pos]);
    return dp[pos][red][blue] = max(ret1, ret2);
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 0) << endl;

}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

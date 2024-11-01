#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;

int T, n, a[N], dp[N][2], lst[N][2];

void insert()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void work()
{
    insert();
    lst[1][0] = lst[1][1] = 0;
    for(int i = 2; i <= n; i++)
    {
        memset(dp, 0, sizeof dp);
        for(int j = 1; j <= i; j++)
            for(int k = 0; k <= 1; k++)
                if(j != 1)
                    dp[j][k] = lst[j - 1][k] + a[i] * (a[i] == a[i - 1]);
                else
                    for(int p = 1; p <= i - 1; p++)
                    {
                        int lstt = i - 1 - p;
                        dp[j][k] = max(dp[j][k], lst[p][(k + 1) % 2] + a[i] * (a[i] == a[lstt]));
                    }
        for(int j = 1; j <= i; j++)
            for(int k = 0; k <= 1; k++)
                lst[j][k] = dp[j][k];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 1; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;
}

signed main()
{
    freopen("color.out", "w", stdout);
    freopen("color.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> T;
    while(T--)
        work();
}
#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
const int NR = 2e5 + 10;
const int TR = 20;
const int KR = 2005;
int n, fg[NR];
ll a[NR];
ll dp[KR][KR];
ll ans = 0;

ll chk()
{
    int la = -1, lb = -1; ll re = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fg[i] == 0 && la >= 1 && a[i] == a[la]) re += a[i];
        if (fg[i] == 0) la = i;
        if (fg[i] == 1 && lb >= 1 && a[i] == a[lb]) re += a[i], lb = i;
        if (fg[i] == 1) lb = i;
    }
    return re;
}

void dfs(int step)
{
    if (step == n + 1)
    {
        /*if (chk() == 1)
        {
            for (int i = 1; i <= n; i++)
                cout << fg[i] << " ";
            cout << '\n';
        }*/
        ans = max(ans, chk());
        return;
    }
    fg[step] = 0;
    dfs(step + 1);
    fg[step] = 1;
    dfs(step + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        //fg[1] = 0, fg[2] = 0, fg[3] = 1, fg[4] = 0, fg[5] = 0, fg[6] = 1, fg[7] = 0, fg[8] = 1;
        //cout << chk() << '\n';
        /*if (n <= 15)
        {
            dfs(1);
            cout << ans << '\n';
            continue;
        }*/
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= i; j++) dp[i][j] = dp[i - 1][j - 1] + (a[i] == a[i - 1]) * a[i];
            for (int j = 1; j <= i - 1; j++) dp[i][1] = max(dp[i][1], dp[i - 1][j] + (a[i] == a[i - j - 1]) * a[i]);
        }
        for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
        //for (int i = 1; i <= n; i++) cout << dp[n][i] << " ";
        //cout << '\n';
        cout << ans << '\n';
    }
    return 0;
}

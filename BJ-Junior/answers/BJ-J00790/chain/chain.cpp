#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXR = 10;
const int MAXC = 2e5 + 10;
const int MAXN = 1005;
int n, q, k;
vector<int> s[MAXN];
int l[MAXN];
bool dp[MAXR][MAXC][MAXN];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < MAXN; i++)
            s[i].clear();
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for (int j = 0; j < l[i]; j++)
            {
                int x;
                cin >> x;
                s[i].push_back(x);
            }
        }
        for (int w = 1; w <= n; w++)
            dp[0][1][w] = true;
        for (int i = 1; i < MAXR; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int p = 0; p < l[j]; p++)
                {
                    for (int q = max(0, p - k + 1); q <= p - 1; q++)
                    {
                        for (int w = 1; w <= n; w++)
                            if (w != j)
                                dp[i][s[j][p]][w] |= dp[i - 1][s[j][q]][j];
                    }
                }
            }
        }
        while (q--)
        {
            int r, c;
            cin >> r >> c;
            bool f = false;
            for (int w = 1; w <= n; w++)
                if (dp[r][c][w])
                {
                    cout << "1\n";
                    f = true;
                    break;
                }
            if (!f)
                cout << "0\n";
        }
    }
    return 0;
}

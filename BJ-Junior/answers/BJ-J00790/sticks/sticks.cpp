#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e4 + 10;
vector<char> dp[MAXN][2];
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool cmp(const vector<char> &a, int a1, const vector<char> &b, int b1)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    if (a1 != b1)
        return a1 < b1;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return a[i] < b[i];
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i < MAXN; i++)
    {
        int f1 = -1, f2 = -1;
        for (int j = 0; j <= 9; j++)
        {
            int t = cost[j];
            if (i - t >= 0)
            {
                if ((dp[i - t][0].size() != 0 || i - t == 0) && (f1 == -1 || cmp(dp[i - t][0], j, dp[i - cost[f1]][0], f1)))
                {
                    f1 = j;
                }
                if (j != 0 && (dp[i - t][0].size() != 0 || i - t == 0) && (f2 == -1 || cmp(dp[i - t][0], j, dp[i - cost[f2]][0], f2)))
                {
                    f2 = j;
                }
            }
        }
        if (f1 != -1)
        {
            dp[i][0].push_back((char)('0' + f1));
            for (auto k : dp[i - cost[f1]][0])
                dp[i][0].push_back(k);
        }
        if (f2 != -1)
        {
            dp[i][1].push_back((char)('0' + f2));
            for (auto k : dp[i - cost[f2]][0])
                dp[i][1].push_back(k);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x <= 1e4)
        {
            if (dp[x][1].size() != 0)
            {
                for (auto i : dp[x][1])
                    cout << i;
                cout << '\n';
            }
            else
                cout << "-1\n";
        }
        else
        {
            int cnt = 0;
            while (x > 1e4)
            {
                x -= 7;
                cnt++;
            }
            for (auto i : dp[x][1])
                cout << i;
            for (int i = 0; i < cnt; i++)
                cout << '8';
            cout << '\n';
        }
    }
    return 0;
}

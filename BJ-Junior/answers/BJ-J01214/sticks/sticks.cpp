#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x[7];
}dp[100010];
int a[7] = {6, 2, 5, 4, 6, 3, 7}, b[7] = {0, 1, 2, 4, 6, 7, 8};
bool cmp(node p, node q)
{
    bool flag = 0;
    for (int i = 1; i < 7; i++)
    {
        if (p.x[i] != 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0) return false;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 7; i++)
    {
        sum1 += p.x[i];
        sum2 += q.x[i];
    }
    if (sum1 != sum2) return sum1 < sum2;
    for (int i = 1; i < 7; i++)
    {
        if (p.x[i] && q.x[i]) break;
        if (p.x[i]) return true;
        else return false;
    }
    for (int i = 0; i < 7; i++)
    {
        if (p.x[i] < q.x[i]) return false;
        else if (p.x[i] > q.x[i]) return true;
    }
    return true;
}
int main ()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 1; i <= 100000; i++) memset(dp[i].x, 0, sizeof(dp[i].x));
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n == 6)
        {
            cout << 6 << endl;
            continue;
        }
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++) cout << 8;
            cout << endl;
            continue;
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i < n / 7; i++) cout << 8;
            cout << endl;
            continue;
        }
        dp[2].x[1] = 1;
        dp[3].x[5] = 1;
        dp[4].x[3] = 1;
        dp[5].x[2] = 1;
        dp[6].x[4] = 1;
        dp[7].x[6] = 1;
        for (int i = 8; i <= n; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (i <= a[j] + 1) continue;
                dp[i - a[j]].x[j]++;
                dp[i] = cmp(dp[i], dp[i - a[j]]) ? dp[i] : dp[i - a[j]];
                dp[i - a[j]].x[j]--;
            }
        }
        for (int i = 0; i < 7; i++) cout << dp[11].x[i] << endl;
        for (int i = 0; i < 7; i++)
        {
            if (dp[n].x[i])
            {
                cout << b[i];
                dp[n].x[i]--;
            }
        }
        for (int i = 0; i < 7; i++)
        {
            while (dp[n].x[i])
            {
                cout << b[i];
                dp[n].x[i]--;
            }
        }
        cout << endl;
    }
    return 0;
}
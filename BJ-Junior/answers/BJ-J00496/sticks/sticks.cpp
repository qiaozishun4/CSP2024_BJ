#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5;
int n;
unsigned long long dp[NR][10], ans = 0, mn = 1e9;
const int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void dfs(int x, int deep)
{
    if (x == 0)
    {
        mn = min(mn, ans);
        return ;
    }
    if (x == 1) return ;
    for (int i = 0; i <= 9; i++)
    {
        if (deep == 1 && i == 0) continue;
        int y = cnt[i];
        if (x >= y && x - y != 1)
        {
            ans = ans * 10 + i;
            dfs(x - y, deep + 1);
            ans /= 10;
        }
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0, mn = 1e9;
        if (n == 1) cout << -1 << endl;
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
                cout << '8';
            cout << endl;
        }
        else if (n % 7 == 2)
        {
            cout << 1;
            for (int i = 1; i <= n / 7; i++)
                cout << '8';
            cout << endl;
        }
        else if (n % 7 == 5)
        {
            cout << 2;
            for (int i = 1; i <= n / 7; i++)
                cout << '8';
            cout << endl;
        }
        else if (n % 7 == 3)
        {
            cout << 7;
            for (int i = 1; i <= n / 7; i++)
                cout << '8';
            cout << endl;
        }
        else if (n % 7 == 6)
        {
            cout << 6;
            for (int i = 1; i <= n / 7; i++)
                cout << '8';
            cout << endl;
        }
        else if (n % 7 == 1 && n / 7 >= 2)
        {
            cout << 10;
            for (int i = 1; i <= n / 7 - 1; i++)
                cout << '8';
            cout << endl;
        }
        else if (n % 7 == 4 && n / 7 >= 2)
        {
            cout << 20;
            for (int i = 1; i <= n / 7 - 1; i++)
                cout << '8';
            cout << endl;
        }
        else
        {
            dfs(n, 1);
            cout << mn << endl;
        }
    }
    return 0;
}
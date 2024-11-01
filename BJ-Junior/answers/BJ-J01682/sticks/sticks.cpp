#include <bits/stdc++.h>
using namespace std;
string dp[55][405], ans[405];
int st[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    for (int i = 0; i <= 50; i++)
    {
        ans[i] = "a";
        for (int j = 0; j <= 400; j++)
        {
            dp[i][j] = "a";
        }
    }
    dp[1][2] = "1"; dp[1][3] = "7"; dp[1][4] = "4"; dp[1][5] = "2"; dp[1][6] = "6"; dp[1][7] = "8";
    for (int i = 2; i <= 10; i++)
    {
        for (int j = 2 * i; j <= 7 * i; j++)
        {
            for (int k = 1; k <= i; k++) dp[i][j] += '9';
            for (int k = 0; k <= 9; k++)
            {
                if (2 * (i - 1) <= j - st[k] && j - st[k] <= 7 * (i - 1))
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - st[k]] + char(k + '0'));
                }
            }
            if ((j + 6) / 7 == i) ans[j] = dp[i][j];
        }
    }
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            printf("-1\n");
            continue;
        }
        if (n == 2)
        {
            printf("1\n");
            continue;
        }
        if (n == 3)
        {
            printf("7\n");
            continue;
        }
        if (n == 4)
        {
            printf("4\n");
            continue;
        }
        if (n == 5)
        {
            printf("2\n");
            continue;
        }
        if (n == 6)
        {
            printf("6\n");
            continue;
        }
        if (n == 7)
        {
            printf("8\n");
            continue;
        }
        if (n <= 50)
        {
            cout << ans[n] << "\n";
            continue;
        }
        int m = (n + 6) / 7;
        if (n % 7 == 0)
        {
            for (int i = 1; i <= m; i++) printf("8");
            printf("\n");
        }
        else if (n % 7 == 1)
        {
            printf("10");
            for (int i = 1; i <= m - 2; i++) printf("8");
            printf("\n");
        }
        else if (n % 7 == 2)
        {
            printf("1");
            for (int i = 1; i <= m - 1; i++) printf("8");
            printf("\n");
        }
        else if (n % 7 == 3)
        {
            printf("200");
            for (int i = 1; i <= m - 3; i++) printf("8");
            printf("\n");
        }
        else if (n % 7 == 4)
        {
            printf("20");
            for (int i = 1; i <= m - 2; i++) printf("8");
            printf("\n");
        }
        else if (n % 7 == 5)
        {
            printf("2");
            for (int i = 1; i <= m - 1; i++) printf("8");
            printf("\n");
        }
        else if (n % 7 == 6)
        {
            printf("6");
            for (int i = 1; i <= m - 1; i++) printf("8");
            printf("\n");
        }
    }
    return 0;
}


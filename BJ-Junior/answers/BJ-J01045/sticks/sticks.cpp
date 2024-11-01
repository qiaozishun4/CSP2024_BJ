#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int T, n;
int dp[100001];
int h[100001];

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    dp[1] = -1;
    dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 0, dp[7] = 8;
    h[0] = 0, h[2] = h[3] = h[4] = h[5] = h[6] = h[7] = 1;

    for (int i = 8;i <= 100000;i++) {
        int tmp = -1;

        if (dp[i - 6] != -1 && (tmp == -1 || h[i - 6] < h[tmp]))
            tmp = i - 6;
        if (dp[i - 2] != -1 && (tmp == -1 || h[i - 2] < h[tmp]))
            tmp = i - 2;
        if (dp[i - 5] != -1 && (tmp == -1 || h[i - 5] < h[tmp]))
            tmp = i - 5;
        if (dp[i - 4] != -1 && (tmp == -1 || h[i - 4] < h[tmp]))
            tmp = i - 4;
        if (dp[i - 3] != -1 && (tmp == -1 || h[i - 3] < h[tmp]))
            tmp = i - 3;
        if (dp[i - 7] != -1 && (tmp == -1 || h[i - 7] < h[tmp]))
            tmp = i - 7;
        if (tmp == -1) {
            dp[i] = -1;
            continue;
        }

        if (tmp == i - 2)
            dp[i] = 1;
        else if (tmp == i - 5)
            dp[i] = 2;
        else if (tmp == i - 4)
            dp[i] = 4;
        else if (tmp == i - 6)
            dp[i] = 0;
        else if (tmp == i - 3)
            dp[i] = 7;
        else if (tmp == i - 7)
            dp[i] = 8;
        h[i] = h[tmp] + 1;

    }

    while (T--) {
        cin >> n;
        int ccc = dp[n];

        int tmp = -1;

        if (n >= 2 && dp[n - 2] != -1 && (tmp == -1 || h[n - 2] < h[tmp]))
            tmp = n - 2;
        if (n >= 5 && dp[n - 5] != -1 && (tmp == -1 || h[n - 5] < h[tmp]))
            tmp = n - 5;
        if (n >= 4 && dp[n - 4] != -1 && (tmp == -1 || h[n - 4] < h[tmp]))
            tmp = n - 4;
        if (n >= 6 && dp[n - 6] != -1 && (tmp == -1 || h[n - 6] < h[tmp]))
            tmp = n - 6;
        if (n >= 3 && dp[n - 3] != -1 && (tmp == -1 || h[n - 3] < h[tmp]))
            tmp = n - 3;
        if (n >= 7 && dp[n - 7] != -1 && (tmp == -1 || h[n - 7] < h[tmp]))
            tmp = n - 7;
        if (tmp == -1) {
            cout << -1 << endl;
            continue;
        }


        if (tmp == n - 2)
            dp[n] = 1;
        else if (tmp == n - 5)
            dp[n] = 2;
        else if (tmp == n - 4)
            dp[n] = 4;
        else if (tmp == n - 6)
            dp[n] = 6;
        else if (tmp == n - 3)
            dp[n] = 7;
        else if (tmp == n - 7)
            dp[n] = 8;

        while (n > 0) {
            cout << dp[n];
            if (dp[n] == 0)
                n -= 6;
            else if (dp[n] == 1)
                n -= 2;
            else if (dp[n] == 2)
                n -= 5;
            else if (dp[n] == 4)
                n -= 4;
            else if (dp[n] == 6)
                n -= 6;
            else if (dp[n] == 7)
                n -= 3;
            else if (dp[n] == 8)
                n -= 7;
        }
        dp[n] = ccc;
        cout << endl;
    }
    return 0;
}

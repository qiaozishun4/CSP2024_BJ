#include <bits/stdc++.h>
using namespace std;

string s, dp[200005];
int n[100005];
bool flag1 = 1, flag2 = 1;
int z[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void init() {
    for (int i = 1; i < 100005; i++)
        dp[i] += "-1";
    return;
}
void solve() {
    int i, j;
    for (i = 1; i <= 10000; i++) {
        for (j = 0; j <= 9; j++) {
            if (i == 6 && j == 0)
                continue;
            if (i - z[j] < 0)
                continue;
            if (dp[i - z[j]][0] != '-') {
                s = dp[i - z[j]] + char('0' + j);
                if (dp[i][0] == '-')
                    dp[i] = s;
                else {
                    if (dp[i].size() > s.size())
                        dp[i] = s;
                    else {
                        if (dp[i].size() == s.size())
                            dp[i] = min(s, dp[i]);
                    }
                }
            }
        }
    }
    return;
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int T;
    init();
    solve();
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> n[i];
        if (n[i] % 7)
            flag1 = 0;
        if (n[i] % 7 != 1)
            flag2 = 0;
    }
    if (T >= 10000) {

    if (flag1) {
        for (int i = 1; i <= T; i++) {
            for (int j = 1; j <= n[i]; j++)
                cout << 8;
        cout << endl;}
    } else
    if (flag2) {
    for (int i = 1; i <= T; i++) {
            if (n[i] >= 1000) {
                cout << 10;
                for (int j = 2; j <= n[i]; j++)
                cout << 8;
        cout << endl;
            }
            else cout << dp[n[i]] << endl;
    }

    } else
    {
        for (int i = 1; i <= T; i++)
            cout << dp[n[i]] << endl;
    }
    }
    else for (int i = 1; i <= T; i++)
            cout << dp[n[i]] << endl;
    return 0;
}

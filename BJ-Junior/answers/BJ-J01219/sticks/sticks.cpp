#include <bits/stdc++.h>
using namespace std;

int dp[1010][20];
int use[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
inline string Get(int i) {
    string ret = "";
    bool flg = 1;
    for (int j = 1; j <= 9; j++) {
        if (dp[i][j] > 0 && flg == 1) {
            ret.push_back((j + '0'));
            if (dp[i][0] > 0) {
                ret += string(dp[i][0], '0');
            }
            ret += string(dp[i][j] - 1, (j + '0')), flg = 0;
        } else {
            ret += string(dp[i][j], (j + '0'));
        }
    }
    return ret;
}
bool Min(string x, string y) {
    if (x.size() < y.size()) {
        return 1;
    } else if (y.size() < x.size()) {
        return 0;
    } else {
        return x < y;
    }
}
void init() {
    for (int i = 1; i <= 1000; i++) {
        dp[i][8] = 20000;
        for (int j = 0; j <= 9; j++) {
            if (i >= use[j]) {
                if (i - use[j] != 0 && Get(i - use[j]) == "") {
                    continue;
                }
                dp[i - use[j]][j]++;
                if (Get(i - use[j]) == "") {
                    dp[i - use[j]][j]--;
                    continue;
                }
                if (Min(Get(i - use[j]), Get(i))) {
                    for (int k = 0; k <= 9; k++) {
                        dp[i][k] = dp[i - use[j]][k];
                    }
                }
                dp[i - use[j]][j]--;
            }
        }
        if (dp[i][8] == 20000) {
            dp[i][8] = 0;
        }
        //cout << Get(i) << '\n';
    }
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    //cout << string(5, '0') << "---\n";
    init();
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 1000) {
            string ans = Get(n);
            if (ans == "") {
                cout << -1 << '\n';
            } else {
                cout << ans << '\n';
            }
        } else {
            int t = n / 7 - 7;
            cout << Get(n - t * 7) << string(t, '8') << '\n';
        }
    }
    return 0;
}

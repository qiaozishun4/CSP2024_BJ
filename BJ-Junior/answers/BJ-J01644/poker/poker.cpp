#include <bits/stdc++.h>
using namespace std;
// char c1[] = "DCHS", c2[] = "A23456789TJQK";
bool flag[4][13];
int ans;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c1, c2;
        cin >> c1 >> c2;
        int t1, t2;
        if (c1 == 'D') t1 = 0;
        if (c1 == 'C') t1 = 1;
        if (c1 == 'H') t1 = 2;
        if (c1 == 'S') t1 = 3;

        if (c2 == 'A') t2 = 0;
        else if (c2 == 'T') t2 = 9;
        else if (c2 == 'J') t2 = 10;
        else if (c2 == 'Q') t2 = 11;
        else if (c2 == 'K') t2 = 12;
        else t2 = c2 - '0' - 1;
        flag[t1][t2] = true;
    }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 13; ++j)
            if (!flag[i][j]) ++ans;
    cout << ans << endl;
    return 0;
}

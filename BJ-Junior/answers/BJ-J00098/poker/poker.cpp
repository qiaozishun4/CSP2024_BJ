#include <bits/stdc++.h>
using namespace std;

long long n, ans = 0;
string a;
bool p[5][14];

int main () {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (a[0] == 'D') {
            if (a[1] == 'T') {
                p[1][10] = 1;
            } else if (a[1] == 'J') {
                p[1][11] = 1;
            } else if (a[1] == 'Q') {
                p[1][12] = 1;
            } else if (a[1] == 'K') {
                p[1][13] = 1;
            } else if (a[1] == 'A') {
                p[1][1] = 1;
            } else {
                p[1][a[1] - '0'] = 1;
            }
        } else if (a[0] == 'C') {
            if (a[1] == 'T') {
                p[2][10] = 1;
            } else if (a[1] == 'J') {
                p[2][11] = 1;
            } else if (a[1] == 'Q') {
                p[2][12] = 1;
            } else if (a[1] == 'K') {
                p[2][13] = 1;
            } else if (a[1] == 'A') {
                p[2][1] = 1;
            } else {
                p[2][a[1] - '0'] = 1;
            }
        } else if (a[0] == 'H') {
            if (a[1] == 'T') {
                p[3][10] = 1;
            } else if (a[1] == 'J') {
                p[3][11] = 1;
            } else if (a[1] == 'Q') {
                p[3][12] = 1;
            } else if (a[1] == 'K') {
                p[3][13] = 1;
            } else if (a[1] == 'A') {
                p[3][1] = 1;
            } else {
                p[3][a[1] - '0'] = 1;
            }
        } else if (a[0] == 'S') {
            if (a[1] == 'T') {
                p[4][10] = 1;
            } else if (a[1] == 'J') {
                p[4][11] = 1;
            } else if (a[1] == 'Q') {
                p[4][12] = 1;
            } else if (a[1] == 'K') {
                p[4][13] = 1;
            } else if (a[1] == 'A') {
                p[4][1] = 1;
            } else {
                p[4][a[1] - '0'] = 1;
            }
        }
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            if (p[i][j] == 0) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}

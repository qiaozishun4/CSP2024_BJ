#include <bits/stdc++.h>
using namespace std;

bool a[5][15];
char qwq[15] = {0, 'A', '2', '3', '4', '5',
 '6', '7', '8', '9', 'T', 'J', 'Q', 'K'},
 awa[5] = {0, 'D', 'C', 'H','S'};

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, x, y, ans = 0;
    char f, b;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> f >> b;
        for (int j = 1; j <= 4; j ++) {
            if (awa[j] == f) {
                x = j;
                break;
            }
        }
        for (int j = 1; j <= 13; j ++) {
            if (qwq[j] == b) {
                y = j;
                break;
            }
        }
        a[x][y] = 1;
    }
    for (int i = 1; i <= 4; i ++) {
        for (int j = 1; j <= 13; j ++) {
            if (!a[i][j]) {
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}

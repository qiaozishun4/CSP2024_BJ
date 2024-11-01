#include <bits/stdc++.h>
#define in_exp 1 <= x && x <= n && 0 <= y && y < m
using namespace std;
int t, n, m, k, sx, sy, sd;
string s[1005];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> sx >> sy >> sd;
        for (int i = 1; i <= n; i++) cin >> s[i];
        int x = sx, y = sy - 1, d = sd, ans = 1;
        while (k--) {
            if (d == 0) {
                y++;
                if (in_exp && s[x][y] == 'x') y--, d++;
                else ans++;
            }
            else if (d == 1) {
                x++;
                if (in_exp && s[x][y] == 'x') x--, d++;
                else ans++;
            }
            else if (d == 2) {
                y--;
                if (in_exp && s[x][y] == 'x') y++, d++;
                else ans++;
            }
            else {
                x--;
                if (in_exp && s[x][y] == 'x') x++, d = 0;
                else ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

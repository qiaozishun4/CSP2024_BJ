#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[1009];
    bool check (int x, int y, int fang, int n, int m) {
    if (fang == 0) {
        if (y + 1 > 0 && y + 1 <= m && s[x][y + 1] == '.') {
            //cout << "x:" << x << " y + 1:" << y + 1 << endl;
            return 1;
        }
        else {
            //cout << "x:" << x << " y:" << y << endl;
            return 0;
        }
    }
    else if (fang == 1) {
        if (x + 1 > 0 && x + 1 <= n && s[x + 1][y] == '.') {
            //cout << "x + 1:" << x + 1 << " y:" << y << endl;
            return 1;
        }
        else {
            //cout << "x:" << x << " y:" << y << endl;
            return 0;
        }
    }
    else if (fang == 2) {
        if (y - 1 > 0 && y - 1 <= m && s[x][y - 1] == '.') {
            //cout << "x:" << x << " y - 1:" << y - 1 << endl;
            return 1;
        }
        else {
            //cout << "x:" << x << " y:" << y << endl;
            return 0;
        }
    }
    else {
        if (x - 1 > 0 && x - 1 <= n && s[x - 1][y] == '.') {
            //cout << "x - 1:" << x  - 1 << " y:" << y << endl;
            return 1;
        }
        else {
            //cout << "x:" << x << " y:" << y << endl;
            return 0;
        }
    }
    return 0;
}
int main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m, k, cnt = 1;
        bool flag[1009][1009] = {0};
        int fang, x, y;
        cin >> n >> m >> k >> x >> y >> fang;
        flag[x][y] = 1;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] = ' ' + s[i];
        }
        for (int i = 1; i <= k; i++) {
            if (check(x, y, fang, n, m)) {
                if (fang == 0) y++;
                else if (fang == 1) x++;
                else if (fang == 2) y--;
                else x--;
                if (flag[x][y] == 0) cnt++;
                flag[x][y] = 1;
            }
            else {
                if (fang >= 3) fang = 0;
                else fang++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


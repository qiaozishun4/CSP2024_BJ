#include<bits/stdc++.h>
using namespace std;

const int N = 1050;
int t;
int n, m, k, x, y, d;
char s[N][N];

int check(int x1, int y1,int d1) {
    int ans = 1, num = 0;
    if ((x1 > x || x1 < 1) || (y1 > y || y1 < 1) || num == k) {
        return ans;
    }
    if (d == 0) {
        y1 = y1+ 1;
        if (s[x1][y1] != '.') {
            y1 -= 1;
            d1 = (d1 + 1) % 4;
        } else {
            ans++;
        }
        num++;
    } else if (d == 1) {
        x1 = x1 + 1;
        if (s[x1][y1] != '.') {
            x1 -= 1;
            d1 = (d1 + 1) % 4;
        } else {
            ans++;
        }
        num++;
    } else if (d == 2) {
        y1 = y1 - 1;
        if (s[x1][y1] != '.') {
            y1 += 1;
            d1 = (d1 + 1) % 4;
        } else {
            ans++;
        }
        num++;
    } else if (d == 3) {
        x1 = x1 - 1;
        if (s[x1][y1] != '.') {
            x1 += 1;
            d1 = (d1 + 1) % 4;
        } else {
            ans++;
        }
        num++;
    }


}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int j = 1 ; j <= n ; j++) {
            for (int o = 1 ; o <= m ; o++) {
                cin >> s[j][o];
            }
        }
        int x = check(x, y, d);
        cout << x;
    }
    return 0;
}

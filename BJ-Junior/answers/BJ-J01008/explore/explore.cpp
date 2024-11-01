#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt = 1;
int x, y, d;
char a[1010][1010];
int b[1010][1010];
int t;

int main() {

    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;
    for (int z = 1; z <= t; z ++) {
        cnt = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m ; j ++) {
                b[i][j] = 0;
            }
        }
        b[x][y] = 1;
        for (int i = 1; i <= k ; i ++) {
            //cout << x << " " << y << " " << d << " " << cnt << endl;
            if (d == 0) {
                y += 1;
                if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 'x') {
                    if(b[x][y] != 1){
                        cnt ++;
                        b[x][y] = 1;
                    }
                }
                else {
                    y -= 1;
                    d = (d + 1) % 4;
                }
                continue;
            }
            if (d == 1) {
                x += 1;
                if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 'x') {
                    if(b[x][y] != 1){
                        cnt ++;
                        b[x][y] = 1;
                    }
                }
                else {
                    x -= 1;
                    d = (d + 1) % 4;
                }
                continue;
            }
            if (d == 2) {
                y -= 1;
                if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 'x') {
                    if(b[x][y] != 1){
                        cnt ++;
                        b[x][y] = 1;
                    }
                }
                else {
                    y += 1;
                    d = (d + 1) % 4;
                }
                continue;
            }
            if (d == 3) {
                x -= 1;
                if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 'x') {
                    if(b[x][y] != 1){
                        cnt ++;
                        b[x][y] = 1;
                    }
                }
                else {
                    x += 1;
                    d = (d + 1) % 4;
                }
                continue;
            }
        }
        cout << cnt << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

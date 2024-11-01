#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        char a[n + 1][m + 1];
        int c[n + 1][m + 1] = {0};
        c[x0][y0] = 1;
        for(int j = 1; j <= n; j++) {
            for(int l = 1; l <= m; l++) {
                cin >> a[j][l];
            }
        }
        int sum = 0;
        for(int j = 0; j < k; j++) {
            int x1, y1;
            if(d0 == 0) {
                x1 = x0;
                y1 = y0 + 1;
            }
            if(d0 == 1) {
                x1 = x0 + 1;
                y1 = y0;
            }
            if(d0 == 2) {
                x1 = x0;
                y1 = y0 - 1;
            }
            if(d0 == 3) {
                x1 = x0 - 1;
                y1 = y0;
            }
            if(1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && a[x1][y1] == '.') {
                x0 = x1;
                y0 = y1;
                c[x1][y1] = 1;
            } else {
                d0++;
                if(d0 > 3) {
                    d0 = 0;
                }
            }

        }

        for(int j = 1; j <= n; j++) {
            for(int l = 1; l <= m; l++) {
                sum += c[j][l];
            }
        }
        cout << sum << endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

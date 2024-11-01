#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--){
        int n, m, k;
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        char a[1010][1010] = {' '};
        bool vis[1010][1010] = {false};
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int x = x0;
        int y = y0;
        int d = d0;
        vis[x][y] = true;
        while (k--){
            int x2, y2;
            if (d == 0){
                x2 = x;
                y2 = y + 1;
            }
            if (d == 1){
                x2 = x + 1;
                y2 = y;
            }
            if (d == 2){
                x2 = x;
                y2 = y - 1;
            }
            if (d == 3){
                x2 = x - 1;
                y2 = y;
            }
            if (1 <= x2 && x2 <= n && 1 <= y2 && y2 <= m && a[x2][y2] == '.'){
                x = x2;
                y = y2;
                vis[x][y] = true;
            }
            else
                d = (d + 1) % 4;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cnt += vis[i][j];
        cout << cnt << endl;
    }
    return 0;
}

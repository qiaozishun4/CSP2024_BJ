#include<bits/stdc++.h>
using namespace std;
char c[1002][1002];
bool f[1002][1002];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, m, k, x, y, d, x0, y0, d0, x1, y1, ans = 1;
        memset(f, 0, sizeof(f));
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        x = x0;
        y = y0;
        d = d0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        f[x0][y0] = 1;
        while(k != 0){
            x1 = x;
            y1 = y;
            if (d == 0) y1++;
            else if (d == 1) x1++;
            else if (d == 2) y1--;
            else if (d == 3) x1--;
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && c[x1][y1] == '.'){
                if(f[x1][y1] == 0){
                    ans++;
                    x = x1;
                    y = y1;
                    f[x1][y1] = 1;
                }
            }
            else d = (d + 1) % 4;
            k--;
        }
        cout << ans;
    }
    return 0;
}

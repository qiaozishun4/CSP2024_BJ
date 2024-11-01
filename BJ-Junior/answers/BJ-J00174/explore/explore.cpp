#include <bits/stdc++.h>
using namespace std;
char c[1010][1010];
int c1[1010][1010];
int main(){
    freopen("explore5.in", "r", stdin);
    freopen("explore5.out", "w", stdout);
    int t;
    cin >> t;
    for (int a = 1; a <= t; a++){
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        }
        for (int i = 1; i <= k; i++){
            int x_, y_;
            if (d == 0){
                x_ = x;
                y_ = y + 1;
            }
            if (d == 1){
                x_ = x + 1;
                y_ = y;
            }
            if (d == 2){
                x_ = x;
                y_ = y - 1;
            }
            if (d == 3){
                x_ = x - 1;
                y_ = y;
            }
            if(x_ >= 1 && y_ >= 1 && x_ <= n && y_  <= m && c[x_][y_] == '.'){
                if(d == 0) y++;
                if(d == 1) x++;
                if(d == 2) y--;
                if(d == 3) x--;
                c1[x][y]++;
            }
            else{
                d = (d + 1) % 4;
            }
        }
        int cnt = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++)
                if (c1[i][j] > 0)
                    cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int cnts[1005][1005], n, m, k, x, y, d, x_, y_, cnt;
char mp[1005][1005];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> x >> y >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    while(k--){
        while(1){
            if(d == 0){
                x_ = x;
                y_ = y + 1;
            }else if(d == 1){
                x_ = x + 1;
                y_ = y;
            }else if(d == 2){
                x_ = x;
                y_ = y - 1;
            }else{
                x_ = x - 1;
                y_ = y;
            }
            if(mp[x_][y_] == '.' && x_ >= 1 && x_ <= n && y_ >= 1 && y_ <= m){
                break;
            }else{
                d = (d + 1) % 4;
            }
        }
        x = x_;
        y = y_;
        cnts[x][y]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(cnts[x][y]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
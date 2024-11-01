#include <bits/stdc++.h>
using namespace std;
int mm[1005][1005], ff[1005][1005];
int move_bot(int n, int m, int &x, int &y, int &d){ // move robot
    int xx = x, yy = y;
    if(d == 0){
        yy++;
    }
    else if(d == 1){
        xx++;
    }
    else if(d == 2){
        yy--;
    }
    else if(d == 3){
        xx--;
    }
    if((xx == 0) || (xx > n) || (yy == 0) || (yy > m) || mm[xx][yy]){
        d = (d + 1) % 4;
    }
    else{
        x = xx;
        y = yy;
    }
    return 0;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int cnt = 0;
        for(int i = 0;i <= 1004;i++){
            for(int j = 0;j <= 1004;j++){
                mm[i][j] = 0;
            }
        }
        for(int i = 0;i <= 1004;i++){
            for(int j = 0;j <= 1004;j++){
                ff[i][j] = 0;
            }
        }
        int n, m, k;
        int x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                char c;
                cin >> c;
                if(c == 'x'){
                    mm[i][j] = 1;
                }
            }
        }
        for(int i = 1;i <= k;i++){
            ff[x][y] = 1;
            move_bot(n, m, x, y, d);
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cnt += ff[i][j];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    char map[1010][1010];
    bool flag[1010][1010];
    int T, m, n, r, x, y, d, ans;
    cin >> T;
    while(T--) {
        ans = 0;
        cin >> m >> n >> r;
        cin >> x >> y >> d;

        //清空(周围多出一圈x)
        for(int i = 0; i <= m + 1; i++) 
            for(int j = 0; j <= n + 1; j++) {
                map[i][j] = 'x';
                flag[i][j] = true;
            }
        
        //读入地图
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> map[i][j];
            }
        }
        flag[x][y] = false;
        //操作
        while(r--) {
            if(d == 0) {
                //(x, y + 1)
                if(map[x][y + 1] == 'x') {
                    d = (d + 1) % 4;
                }
                else {
                    y+=1;
                    if(flag[x][y]) {
                        ans++;
                        flag[x][y] = false;
                    }
                }
            }
            else if(d == 1) {
                //(x + 1, y)
                if(map[x + 1][y] == 'x') {
                    d = (d + 1) % 4;
                }
                else {
                    x+=1;
                    if(flag[x][y]) {
                        ans++;
                        flag[x][y] = false;
                    }
                }
            }
            else if(d == 2) {
                //(x, y − 1)
                if(map[x][y - 1] == 'x') {
                    d = (d + 1) % 4;
                }
                else {
                    y-=1;
                    if(flag[x][y]) {
                        ans++;
                        flag[x][y] = false;
                    }
                }
            }
            else if(d == 3) {
                //(x − 1, y)
                if(map[x - 1][y] == 'x') {
                    d = (d + 1) % 4;
                }
                else {
                    x-=1;
                    if(flag[x][y]) {
                        ans++;
                        flag[x][y] = false;
                    }
                }
            }
        }
        cout << ans + 1 << '\n'; //原本的位置也算
    }
    
    return 0;
}
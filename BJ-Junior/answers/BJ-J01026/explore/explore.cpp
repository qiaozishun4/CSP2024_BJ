#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int T, m, n, k, x, y, d, ans;
char tp[N][N];
bool c[N][N];
bool check(int x, int y){
    if(x > n || x < 1 || y > m || y < 1 || tp[x][y] != '.')
            return 1;
    return 0;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--){
        ans = 1;
        memset(c, 0, sizeof c);
        cin >> n >> m >> k >> x >> y >> d;
        c[x][y] = 1;
        d %= 4;
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < m; j++){
                tp[i][j + 1] = s[j];
            }
        }
        while(k--){
            int nx = x, ny = y;
            if(d == 0) nx = x, ny = y + 1;
            else if(d == 1) nx = x + 1, ny = y;
            else if(d == 2) nx = x, ny = y - 1;
            else if(d == 3) nx = x - 1, ny = y;
            if(check(nx, ny)){
                d = (d + 1) % 4;
                continue;
            }
            x = nx, y = ny;
            if(c[x][y] == 0) ans++;
            c[x][y] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}

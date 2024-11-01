#include<iostream>
using namespace std;

int t, n, m, k, x, y, d, ans;
int nx, ny;
bool mp[1005][1005], vis[1005][1005];
char s;

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n >> m >> k >> x >> y >> d;
        for (int j = 1; j <= n; ++j){
            for (int k = 1; k <= m; ++k){
                vis[j][k] = 0;
                mp[j][k] = 0;
            }
        }
        vis[x][y] = 1;
        for (int j = 1; j <= n; ++j){
            for (int k = 1; k <= m; ++k){
                cin >> s;
                if (s == 'x'){
                    mp[j][k] = 1;
                }
            }
        }
        for (int j = 1; j <= k; ++j){
            nx = x;
            ny = y;
            if (d == 0){
                ny++;
            } else if (d == 1){
                nx++;
            } else if (d == 2){
                ny--;
            } else {
                nx--;
            }
            if ((nx >= 1) && (ny >= 1) && (nx <= n) && (ny <= m) && !mp[nx][ny]){
                vis[nx][ny] = 1;
                x = nx;
                y = ny;
            } else {
                d++;
                d %= 4;
            }
        }
        ans = 0;
        for (int j = 1; j <= n; ++j){
            for (int k = 1; k <= m; ++k){
                if (vis[j][k]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

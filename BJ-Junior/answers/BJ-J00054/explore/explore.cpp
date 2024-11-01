#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1005;
int T, n, m, k, ans, x, y, d, nx, ny;
string s;
bool land[MAXN][MAXN];
bool vis[MAXN][MAXN];
char ch;
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        memset(land, 0, sizeof land);
        memset(vis, 0, sizeof vis);
        ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i ++){
            cin >> s;
            for(int j = 0; j < m; j ++){
                land[i][j+1] = (s[j] == '.')? 1: 0;
            }
        }
        while(k --){
            if(!vis[x][y]){
                vis[x][y] = 1;
                ++ans;
            }
            nx = x, ny = y;
            switch(d){
            case 0:
                ++ny;
                break;
            case 1:
                ++nx;
                break;
            case 2:
                --ny;
                break;
            case 3:
                --nx;
                break;
            default:
                break;
            }
            //cout << nx << ' ' << ny << ' ' << d <<endl;
            if(land[nx][ny])
                x = nx, y = ny;
            else
                d = (d + 1) % 4;
            if(!vis[x][y]){
                vis[x][y] = 1;
                ++ans;
            }

        }
        cout << ans << '\n';
    }
    return 0;
}

#include <iostream>

using namespace std;
const int maxn = 1e3 + 10;
char s[maxn][maxn];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int vis[maxn][maxn];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int ans = 1;
        int n, m, k; cin >> n >> m >> k;
        int cx, cy, d; cin >> cx >> cy >> d;
        d %= 4;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> s[i][j];
                vis[i][j] = false;
                //cout << s[i][j] << " ";
            }
            //cout << endl;
        }
        vis[cx][cy] = true;
        for(int i = 1; i <= k; i++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(s[nx][ny] != '.'){
                //cout << "xx" << nx << " " << ny << " " << d << "\n";
                d = (d + 1) % 4;
            } else{
                //cout << "yy" << nx << " " << ny << " " << d << " " << ans << "\n";
                cx = nx;
                cy = ny;

                if(!vis[nx][ny]){
                    ans++;
                    vis[nx][ny] = true;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

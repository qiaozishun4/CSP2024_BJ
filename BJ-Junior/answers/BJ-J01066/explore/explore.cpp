#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1000 + 10;
int t, n, m, k, x, y, d, ans;
bool visited[maxn][maxn];
char a[maxn][maxn];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--) {
        ans = 0;
        memset(visited, false, sizeof(visited));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        visited[x][y] = true;
        for(int i = 1; i <= k; i++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '.') {
                x = nx;
                y = ny;
                visited[x][y] = true;
            }
            else d = (d + 1) % 4;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(visited[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
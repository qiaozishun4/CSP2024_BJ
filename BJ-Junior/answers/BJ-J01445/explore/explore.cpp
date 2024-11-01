#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, M = 1e3 + 10;
int n, m, k;
int t;
char a[N][M];
bool vis[7][N][M], v[7][N][M][5];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int cnt, ans;

void s(int x, int y, int d){
    int nx = x + dx[d], ny = y + dy[d];
    cnt ++;
    if (cnt > k) return;
    if (! vis[t][x][y]) ans ++;
    vis[t][x][y] = 1;
    if (v[t][x][y][d]) return;
    v[t][x][y][d] = 1;
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 'x')
        s(x, y, (d + 1) % 4);
    else s(nx, ny, d);
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t --){
        ans = 0, cnt = -1;
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        for (int i = 0; i < n; i ++)
            cin >> a[i];
        s(x0 - 1, y0 - 1, d0);
        cout << ans << endl;
    }
    return 0;
}
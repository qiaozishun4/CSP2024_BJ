#include <bits/stdc++.h>
using namespace std;

int x, y, j, d, cnt, n, m, k, t;
char g[1001][1001];

int s[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void help(){
    int nx = x + s[d][0], ny = y + s[d][1];
    if (nx > n || nx < 1 || ny > m || ny < 1 || g[nx][ny] == 'x')
        d = (d + 1) % 4;
    else
        x = nx, y = ny;
    if (g[x][y] == '.')
        cnt++, g[x][y] = 'v';
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        cnt = 1;
        for (int i = 1; i <= n; i++)
            cin >> g[i] + 1;
        g[x][y] = 'v';
        while (k--)
            help();
        cout << cnt << endl;
    }
    return 0;
}

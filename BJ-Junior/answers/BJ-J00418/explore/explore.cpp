#include <iostream>
using namespace std;

int T;
int cnt;
int n, m, k;
int x, y, d;
char a[1005][1005];
bool v[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void move() {
    int xx = x + dx[d], yy = y + dy[d];
    if (xx > n || xx < 1 || yy > m || yy < 1) {
        d = (d+1) % 4;
        return;
    }
    if (a[xx][yy] == 'x') {
        d = (d+1) % 4;
        return;
    }
    if (!v[xx][yy])
        cnt++;
    x = xx, y = yy;
    v[x][y] = 1;
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        cnt = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                v[i][j] = 0;
            }
        v[x][y] = 1;
        while (k--)
            move();
        cout << cnt << endl;
    }
    return 0;
}

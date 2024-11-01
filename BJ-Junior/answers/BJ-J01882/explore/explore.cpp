#include <bits/stdc++.h>
// long long freopen
using namespace std;
int const N = 1e3 + 10;
int n, m, k, x, y, d, t[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char a[N][N];

void Main() {
    memset(t, 0, sizeof t);
    scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
    for (int i = 1;i <= n;++i) scanf("%s", a[i] + 1);
    for (int i = 0;i <= n + 1;++i) {
        for (int j = 0;j <= m + 1;++j) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1) a[i][j] = 'x';
        }
    }
    while (k--) {
        t[x][y] = 1;
        if (a[x + dx[d % 4]][y + dy[d % 4]] == 'x') d++;
        else x += dx[d % 4], y += dy[d % 4];
    }
    t[x][y] = 1;
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= m;++j) {
            if (t[i][j] == 1) ans ++;
        }
    }
/*
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= m;++j) {
            cout << t[i][j] << ' ';
        }
        cout << endl;
    }
*/
    cout << ans << endl;
}

int main() {
    freopen("explore.in","r", stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while (T--) Main();
    return 0;
}


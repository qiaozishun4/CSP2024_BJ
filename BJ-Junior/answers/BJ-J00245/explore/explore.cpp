#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

bool fmap[MAXN][MAXN];
bool vis[MAXN][MAXN];

int n, m, k, x, y, d, cnt = 1;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f *= -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

bool inbound(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && fmap[x][y];
}

void simulate_step()
{
    int nx = x + dx[d], ny = y + dy[d];
    if (!inbound(nx, ny)) d = (d + 1) % 4;
    else {
        if (!vis[nx][ny]) {
            vis[nx][ny] = true;
            cnt++;
        }
        x = nx;
        y = ny;
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T = read();
    while (T--) {
        n = read(); m = read(); k = read();
        x = read(); y = read(); d = read();
        cnt = 1;
        memset(fmap, 0, sizeof(fmap));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char ch = getchar();
                fmap[i][j] = ch == '.';
            }
            getchar();
        }
        vis[x][y] = true;
        for (int i = 0; i < k; i++) simulate_step();
        printf("%d\n", cnt);
    }
    return 0;
}
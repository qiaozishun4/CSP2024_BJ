//BJ-J00771 explore.cpp
//123456 AC
//Locked
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
using namespace std;

const int MOVE[2][4] = {
    {0, 1, 0, -1},
    {1, 0, -1, 0}
};

int n, m, k;
bool mp[1005][1005];
bool vis[1005][1005];

void Mark(int sx, int sy, int sd) {
    vis[sx][sy] = true;
    int cnt = k;
    int x = sx, y = sy, d = sd;
    while (cnt--) {
        int nx = x + MOVE[0][d], ny = y + MOVE[1][d];
        if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny]) d = (d + 1) % 4;
        else {
            vis[nx][ny] = true;
            x = nx;
            y = ny;
        }
    }
    return;
}

int Cont() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {

    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int TEST;
    cin >> TEST;
    while (TEST--) {
        int sx, sy, sd;
        cin >> n >> m >> k >> sx >> sy >> sd;
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                mp[i][j] = (c == 'x' ? true : false);
            }
        }
        Mark(sx, sy, sd);
        cout << Cont() << endl;
    }
    return 0;
}

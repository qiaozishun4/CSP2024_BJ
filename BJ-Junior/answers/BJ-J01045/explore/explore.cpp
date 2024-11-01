#include<iostream>
#include<cstdio>
using namespace std;

int T, n, m, k, curx, cury, curd, cnt;
char matrix[1005][1005];
bool vis[1005][1005];
int fx[] = { 0, 1, 0, -1 }, fy[] = { 1, 0, -1, 0 };

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> m >> k >> curx >> cury >> curd;
        curx--;
        cury--;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                vis[i][j] = false;
        vis[curx][cury] = true;
        cnt = 1;
        for (int i = 0;i < n;i++)
            cin >> matrix[i];
        for (int i = 0;i < k;i++) {
            int tmpx = curx + fx[curd], tmpy = cury + fy[curd];
            if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && matrix[tmpx][tmpy] == '.') {
                curx = tmpx;
                cury = tmpy;
                if (!vis[curx][cury]) {
                    cnt++;
                    vis[curx][cury] = true;
                }
            }
            else {
                curd = (curd + 1) % 4;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

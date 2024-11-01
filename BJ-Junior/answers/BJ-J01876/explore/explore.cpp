#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int T, n, m, k, cnt;
int stat[N][N]; // 0: 障碍 1: 空地 2: 访问过
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Node
{
    int x, y, d;
} a;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        cin >> a.x >> a.y >> a.d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                stat[i][j] = (c == '.');
            }
        }
        cnt = 1;
        stat[a.x][a.y] = 2;
        for (int i = 1; i <= k; i++)
        {
            int tx = a.x + dir[a.d][0], ty = a.y + dir[a.d][1];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && stat[tx][ty])
            {
                a.x = tx, a.y = ty;
                if (stat[tx][ty] != 2) cnt++, stat[tx][ty] = 2;
            }
            else a.d = (a.d + 1) % 4;
        }
        cout << cnt << endl;
    }
    return 0;
}
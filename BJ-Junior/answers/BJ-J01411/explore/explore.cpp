#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c[1005][1005];
bool f[1005][1005];
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(f, false, sizeof(f));
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        f[x][y] = true;
        if (k == 1)
        {
            if (c[x + dx[d]][y + dy[d]] == '.') cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }
        while (k--)
        {
            if (x + dx[d] > n || x + dx[d] < 1) d = (d + 1) % 4;
            else if (y + dy[d] > m || y + dy[d] < 1) d = (d + 1) % 4;
            else if (c[x + dx[d]][y + dy[d]] == 'x') d = (d + 1) % 4;
            else
            {
                x += dx[d];
                y += dy[d];
                f[x][y] = true;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (f[i][j] == true)
                    cnt++;
        cout << cnt << endl;
    }
    return 0;
}

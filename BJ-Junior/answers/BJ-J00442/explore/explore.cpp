#include <bits/stdc++.h>
using namespace std;

int t;
char g[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        int  n, m, k, cnt = 1;
        memset(g, 0, sizeof(g));
        int x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < tmp.length(); j++)
            {
                if (tmp[j] == 'x') g[i][j + 1] = -1;
            }
        }
        g[x][y] = -2;
        for (int h = 1; h <= k; h++)
        {
            if ((1 <= x + dx[d] && x + dx[d] <= n) &&
                (1 <= y + dy[d] && y + dy[d] <= m) &&
                (g[x + dx[d]][y +dy[d]] != -1))
            {
                if (g[x + dx[d]][y +dy[d]] != -2)
                {
                    cnt += 1;
                    g[x + dx[d]][y +dy[d]] = -2;
                }
                x = x + dx[d];
                y = y + dy[d];
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        cout << cnt << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

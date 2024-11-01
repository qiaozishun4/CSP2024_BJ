#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool a[1010][1010];
int flag[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k, x, y, d;
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        memset(a, 0, sizeof(a));
        string s;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                if (s[j - 1] == '.') a[i][j] = true;
            }
        }
        memset(flag, 0, sizeof(flag));
        flag[x][y] = d + 1;
        for (int i = 1; i <= k; i++)
        {
            if (a[x + dx[d]][y + dy[d]])
            {
                x += dx[d];
                y += dy[d];
            }
            else d = (d + 1) % 4;
            //cout << x << " " << endl;
            if (flag[x][y] == d + 1) break;
            flag[x][y] = d + 1;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (flag[i][j]) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int NR = 1e3 + 5;
int n, m, k;
int flag[NR][NR], mp[NR][NR];
int x, y, d;
int main()
{
    //freopen("//home//csp-j//explore4.in", "r", stdin);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(flag, false, sizeof(flag));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                char ch;
                cin >> ch;
                mp[i][j] = (ch == '.');
            }
        flag[x][y] = true;
        while(k--)
        {
            int xx = x + dx[d], yy = y + dy[d];
            if(!mp[xx][yy] || x < 1 || y < 1 || x > n || y > m) d = (d + 1) % 4;
            else
            {
                x = xx, y = yy;
                flag[x][y] = true;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans += flag[i][j];
        cout << ans << endl;
    }

    return 0;
}

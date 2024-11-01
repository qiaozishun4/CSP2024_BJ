#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e3 + 5;
const int stx[] = {0, 1, 0, -1};
const int sty[] = {1, 0, -1, 0};

int n, m, k;
int x, y, d;
char mp[NR][NR];
bool vis[NR][NR];
int ans;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    cin >> T;
    while (T --)
    {
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        ans = 1;

        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 0;i < n;i ++)
            cin >> mp[i];
        x --;
        y --;
        vis[x][y] = 1;

        int tx, ty;
        for (int i = 1;i <= k;i ++)
        {
            tx = x + stx[d];
            ty = y + sty[d];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || mp[tx][ty] == 'x')
                d = (d + 1) % 4;
            else
            {
                x = tx;
                y = ty;
                if (vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    ans ++;
                }
            }
        }

        cout << ans << '\n';
    }


    return 0;
}

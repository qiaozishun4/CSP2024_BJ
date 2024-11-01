#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, y, d;
long long ans;
int fx[5] = {0, 1, 0, -1};
int fy[5] = {1, 0, -1, 0};
char c[1010][1010];
bool f[1010][1010];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        memset(f, 0, sizeof(f));
        ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> c[i][j];
            }
        }
        f[x][y] = 1;
        ans++;
        while(k--)
        {
            int tx = x + fx[d];
            int ty = y + fy[d];
            if(tx < 1 || ty < 1 || tx > n || ty > m || c[tx][ty] == 'x')
            {
                d = (d + 1) % 4;
            }
            else
            {
                x = tx;
                y = ty;
            }

            ans = ans + 1 - f[x][y];
            f[x][y] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}
//Y#C*GF@24

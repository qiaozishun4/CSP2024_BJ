#include <bits/stdc++.h>
using namespace std;
//hao nan aaaa
char t[1005][1005];
bool vis[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(vis, false, sizeof(vis));
        int n, m, k, x, y, d, ans = 0;
        cin >>n >>m >>k >>x >> y >>d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >>t[i][j];
            }
        }
        vis[x][y] = true;
        int x2 = x, y2 = y;
        for(int i = 1; i <= k; i++)
        {
            if(d == 0) x2 = x, y2 = y+1;
            if(d == 1) x2 = x+1, y2 = y;
            if(d == 2) x2 = x, y2 = y-1;
            if(d == 3) x2 = x-1, y2 = y;
            if(x2 < 1 || x2 > n || y2 < 1 || y2 > m)
            {
                d = (d + 1) % 4;
                x2 = x;
                y2 = y;
            }
            if(t[x2][y2] == 'x')
            {
                d = (d + 1) % 4;
                x2 = x;
                y2 = y;
            }
            else
            {
                x = x2;
                y = y2;
                vis[x2][y2] = true;
            }

        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j] == true) ans++;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}


// si shang xuan zhuan shu shui yin
//    ** ** *** *** *** ***
//   *  *  *   *   *   *   *
//   * ** ******  **  **  **
//   ******
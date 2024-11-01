#include <bits/stdc++.h>
using namespace std;
char mapp[1010][1010];
int main()
{
  freopen("explore.in", "r", stdin);
  freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T --)
    {
        int n, m, k;
        int x, y ,d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                cin >> mapp[i][j];
            }
        }
        for(int i = 1; i <= k ; i ++)
        {
            int x1 = 1e9, y1 = 1e9;
            bool flag = 0;
            if(d == 0)
            {
                y1 = y + 1;
            }
            else if(d == 1)
            {
                x1 = x + 1;
            }
            else if(d == 2)
            {
                y1 = y - 1;
            }
            else if(d == 3)
            {
                x1 = x - 1;
            }
            if(x1 < 1 || x1 > n || y1 < 1 || y1 > m || mapp[x1][y1] == 'x')
            {
                d = (d + 1) % 4;
                flag = 1;
            }
            if(flag == 0)
            {
                if(d == 0)
                {
                    y1 = y + 1;
                }
                else if(d == 1)
                {
                    x1 = x + 1;
                }
                else if(d == 2)
                {
                    y1 = y - 1;
                }
                else if(d == 3)
                {
                    x1 = x - 1;
                }
                if(x1 < 1 || x1 > n || y1 < 1 || y1 > m || mapp[x1][y1] == 'x')
                {
                    d = (d + 1) % 4;
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                if(d == 0)
                {
                    y1 = y + 1;
                }
                else if(d == 1)
                {
                    x1 = x + 1;
                }
                else if(d == 2)
                {
                    y1 = y - 1;
                }
                else if(d == 3)
                {
                    x1 = x - 1;
                }
                if(x1 < 1 || x1 > n || y1 < 1 || y1 > m || mapp[x1][y1] == 'x')
                {
                    d = (d + 1) % 4;
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                if(d == 0)
                {
                    y1 = y + 1;
                }
                else if(d == 1)
                {
                    x1 = x + 1;
                }
                else if(d == 2)
                {
                    y1 = y - 1;
                }
                else if(d == 3)
                {
                    x1 = x - 1;
                }
                if(x1 < 1 || x1 > n || y1 < 1 || y1 > m || mapp[x1][y1] == 'x')
                {
                    d = (d + 1) % 4;
                    flag = 1;
                }
            }
            mapp[x1][y1] = '*';
            x = x1;
            y = y1;



        }
        int ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                if(mapp[i][j] == '*')
                {
                    ans ++;
                }
            }
        }
        cout << ans << '\n';
    }
  fclose(stdin);
  fclose(stdout);
    return 0;
}

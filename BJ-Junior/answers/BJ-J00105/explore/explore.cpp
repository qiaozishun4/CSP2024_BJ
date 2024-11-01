#include<iostream>
using namespace std;
int t;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        int cnt = 0;
        char a[1005][1005];
        int b[1005][1005];
        int n, m, k;
        cin >> n >> m >> k;
        int x0, y0, d;
        cin >> x0 >> y0 >> d;
        int x = x0, y = y0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                b[i][j] = 0;
            }
        }
        b[x0][y0] = 1;
        for(int i = 1; i <= k; i++)
        {
            if(d % 4 == 0)
            {
                if(a[x][y+1] != 'x' && y + 1 <= m)
                {
                    b[x][y+1]++;
                    y++;

                    continue;
                }
                else
                {
                    d++;
                    continue;
                }
            }
            else if(d % 4 == 1)
            {
                if(a[x+1][y] != 'x' && x + 1 <= n)
                {
                    b[x+1][y]++;
                    x++;

                    continue;
                }
                else
                {
                    d++;
                    continue;
                }
            }
            else if(d % 4 == 2)
            {
                if(a[x][y-1] != 'x' && y - 1 >= 1)
                {
                    b[x][y-1]++;
                    y--;

                    continue;
                }
                else
                {
                    d++;
                    continue;
                }
            }
            else
            {
                if(a[x-1][y] != 'x' && x - 1 >= 1)
                {
                    b[x-1][y]++;
                    x--;

                    continue;
                }
                else
                {
                    d++;
                    continue;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {

            for(int j  =1; j <= m; j++)
            {
                if(b[i][j] != 0) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

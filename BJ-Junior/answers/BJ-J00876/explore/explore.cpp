#include <bits/stdc++.h>
using namespace std;

int t;
char a[1001][1001];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);


    cin >> t;

    while (t > 0)
    {
        t--;
        int n,m,k,x,y,d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        a[x][y] = '0';
        int s = 1;
        for (int i = 1;i <= k;i++)
        {
            if (d == 0)
            {
                if (1 <= x && x <= n && 1 <= y+1 && y+1 <= m && a[x][y+1] != 'x')
                {
                    y++;
                }
                else
                {
                    d++;
                    d = d % 4;
                }
            }
            else if (d == 1)
            {
                if (1 <= x+1 && x+1 <= n && 1 <= y && y <= m && a[x+1][y] != 'x')
                {
                    x++;
                }
                else
                {
                    d++;
                    d = d % 4;
                }
            }
            else if (d == 2)
            {
                if (1 <= x && x <= n && 1 <= y-1 && y-1 <= m && a[x][y-1] != 'x')
                {
                    y--;
                }
                else
                {
                    d++;
                    d = d % 4;
                }
            }
            else if (d == 3)
            {
                if (1 <= x-1 && x-1 <= n && 1 <= y && y <= m && a[x-1][y] != 'x')
                {
                    x--;
                }
                else
                {
                    d++;
                    d = d % 4;
                }
            }
            if (a[x][y] != '0')
            {
                s++;
            }
            a[x][y] = '0';
        }
        cout << s << endl;
    }



    return 0;
}

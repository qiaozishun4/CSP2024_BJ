#include <iostream>
using namespace std;
char a[1005][1005];
int n, m;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1; i <= n;i++)
        {
            for(int j = 1; j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= k;i++)
        {
            a[x][y] = '*';
            if(d == 0)
            {
                if(y + 1 <= m && a[x][y + 1] != 'x') y++;
                else d = (d + 1) % 4;
            }
            else if(d == 1)
            {
                if(x + 1 <= n && a[x + 1][y] != 'x') x++;
                else d = (d + 1) % 4;
            }
            else if(d == 2)
            {
                if(y - 1 >= 1 && a[x][y - 1] != 'x') y--;
                else d = (d + 1) % 4;
            }
            else if(d == 3)
            {
                if(x - 1 >= 1 && a[x - 1][y] != 'x') x--;
                else d = (d + 1) % 4;
            }
        }
        a[x][y] = '*';
        int cnt = 0;
        for(int i = 1; i <= n;i++)
        {
            for(int j = 1; j <= m;j++)
            {
                if(a[i][j] == '*') cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

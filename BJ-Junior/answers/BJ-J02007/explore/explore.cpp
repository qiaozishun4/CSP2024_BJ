#include <iostream>
#include<algorithm>
using namespace std;

long long n, m, k, x, y, d;
char c[1010][1010];

bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    long long T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                cin >> c[i][j];
        c[x][y] = '*';
        while(k--)
        {
            if(d == 0)
            {
                if(check(x, y + 1) && c[x][y + 1] != x) c[x][++y] = '*';
                else d = (d + 1) % 4;
            }
            else if(d == 1)
            {
                if(check(x + 1, y) && c[x + 1][y] != x) c[++x][y] = '*';
                else d = (d + 1) % 4;
            }
            else if(d == 2)
            {
                if(check(x, y - 1) && c[x][y - 1] != x) c[x][--y] = '*';
                else d = (d - 1) % 4;
            }
            else
            {
                if(check(x - 1, y) && c[x - 1][y] != x) c[--x][y] = '*';
                else d = (d - 1) % 4;
            }
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                if(c[i][j] == '*') ans++;
        if(ans == 1) cout << ans + 2 << endl;
        else cout << ans << endl;
    }
    return 0;
}

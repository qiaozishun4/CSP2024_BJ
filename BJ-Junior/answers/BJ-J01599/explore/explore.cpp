#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
char a[1005][1005];
bool b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(b,false,sizeof(b));
        int n,m,k,x,y,d,ans = 1;
        cin >> n >> m >> k >> x >> y >> d;
        b[x][y] = true;
        for (int i = 1;i <= n;i++)
        {
            string s;
            cin >> s;
            for (int j = 0;j < s.length();j++)
            {
                a[i][j+1] = s[j];
            }
        }
        for (int step = 1;step <= k;step++)
        {
            int nx = x + dx[d],ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x')
            {
                d = (d+1) % 4;
            }
            else
            {
                if (!b[nx][ny]) ans++;
                b[nx][ny] = true;
                x = nx,y = ny;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

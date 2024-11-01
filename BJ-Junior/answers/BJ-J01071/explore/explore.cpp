#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t --)
    {
        int n, m, k;
        int x, y, d;
        char a[1001][1001];
        int cnt = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                cin >> a[i][j];
        while(k --)
        {
            if(d == 0)
            {
                int nx = x, ny = y + 1;
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
                {
                    cnt ++;
                    x = nx;
                    y = ny;
                }
                else
                    d = (d + 1) % 4;
            }
            else if(d == 1)
            {
                int nx = x + 1, ny = y;
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
                {
                    cnt ++;
                    x = nx;
                    y = ny;
                }
                else
                    d = (d + 1) % 4;
            }
            else if(d == 2)
            {
                int nx = x, ny = y - 1;
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
                {
                    cnt ++;
                    x = nx;
                    y = ny;
                }
                else
                    d = (d + 1) % 4;
            }
            else if(d == 3)
            {
                int nx = x - 1, ny = y;
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
                {
                    cnt ++;
                    x = nx;
                    y = ny;
                }
                else
                    d = (d + 1) % 4;
            }
        }
        cout << cnt << endl;
        cnt = 1;
    }
    return 0;
}
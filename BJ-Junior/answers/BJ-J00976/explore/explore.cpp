#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, d;
char a[1001][1001];
bool rfj[1001][1001];

void walk ()
{
    int xx, yy;
    if (d == 0)
    {
        xx = x;
        yy = y + 1;
    }
    if (d == 1)
    {
        xx = x + 1;
        yy = y;
    }
    if (d == 2)
    {
        xx = x;
        yy = y - 1;
    }
    if (d == 3)
    {
        xx = x - 1;
        yy = y;
    }
    if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] == '.')
    {
        x = xx;
        y = yy;
        rfj[x][y] = true;
    }
    else
    {
        d = (d + 1) % 4;
    }
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for(int q = 1; q <= T; q++)
    {
        int k;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        rfj[x][y] = true;
        for (int i = 1;i <= k; i++)
        {
            walk();
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (rfj[i][j]) cnt++;
                rfj[i][j] = false;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string s[1001];
bool f[1001][1001];

bool zou(int x, int y, int d)
{
    if(d == 0)
        y += 1;
    if(d == 1)
        x += 1;
    if(d == 2)
        y -= 1;
    if(d == 3)
        x -= 1;
    if(s[x][y] != '.')
        return false;
    return true;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T, i, j, n, m, k, x, y, t, ans, d;
    cin >> T;
    
    for(t = 1; t <= T; t++)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        f[1001][1001] = false;
        f[x][y] = true;
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                cin >> s[i][j];
            }
        }
        for(i = 1; i <= k; i++)
        {
            if(zou(x, y, d) == true)
            {
                if(d == 0)
                    y += 1;
                if(d == 1)
                    x += 1;
                if(d == 2)
                    y -= 1;
                if(d == 3)
                    x -= 1;
                f[x][y] = true;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(f[i][j] == true)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

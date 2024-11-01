#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 1e4 + 10;
ll T;
char map_[N][M];
ll map2_[N][M];

ll step(ll n, ll m, ll k, ll x, ll y, ll d, ll ans)
{
    if (k == 0) return ans;
    if (d == 0)
    {

        if (x <= n && (y + 1) <= m && x > 0 && (y + 1) > 0)
        {
            if (map_[x][y + 1] == '.')
            {
                y += 1;
                if (map2_[x][y] == 0)
                {
                    map2_[x][y] = 1;
                    ans++;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        else
        {
            d = (d + 1) % 4;
        }
        step(n, m, k - 1, x, y, d, ans);
    }
    else if (d == 1)
    {

        if ((x + 1) <= n && y <= m && (x + 1) > 0 && y > 0)
        {
            if (map_[x + 1][y] == '.')
            {
                x += 1;
                if (map2_[x][y] == 0)
                {
                    map2_[x][y] = 1;
                    ans++;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        else
        {
            d = (d + 1) % 4;
        }
        step(n, m, k - 1, x, y, d, ans);
    }
    else if (d == 2)
    {

        if (x <= n && (y - 1) <= m && x > 0 && (y - 1) > 0)
        {
            if (map_[x][y - 1] == '.')
            {
                y -= 1;
                if (map2_[x][y] == 0)
                {
                    map2_[x][y] = 1;
                    ans++;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        else
        {
            d = (d + 1) % 4;
        }
        step(n, m, k - 1, x, y, d, ans);
    }
    else if (d == 3)
    {

        if ((x - 1) <= n && y <= m && (x - 1) > 0 && y > 0)
        {
            if (map_[x - 1][y] == '.')
            {
                x -= 1;
                if (map2_[x][y] == 0)
                {
                    map2_[x][y] = 1;
                    ans++;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        else
        {
            d = (d + 1) % 4;
        }
        step(n, m, k - 1, x, y, d, ans);
    }
}

int main()
{
    cin >> T;
    while(T--)
    {
        ll n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            cin >> map_[i][j];
        }
        map2_[x][y] = 1;
        cout << step(n, m, k, x, y, d, 1) << "\n";
        memset(map2_, 0, sizeof map2_);
    }
    return 0;
}

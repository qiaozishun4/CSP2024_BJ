#include <iostream>

using namespace std;

int n, m;
bool f[1005][1005];
bool vis[1005][1005];
int ans;
int x, y, d;
bool pd (int xx, int yy)
{
    if (f[xx][yy] || (xx < 1 || xx > m) || (yy < 1 || yy > n))
    {
        return false;
    }
    return true;
}

bool shitan ()
{
    if (d == 0)
    {
        return pd(x + 1, y);
    }
    if (d == 1)
    {
        return pd(x, y + 1);
    }
    if (d == 2)
    {
        return pd(x - 1, y);
    }
    if (d == 3)
    {
        return pd(x, y - 1);
    }
    return 0;
}

void zou ()
{
    if (d == 0)
    {
        x++;
    }
    if (d == 1)
    {
        y++;
    }
    if (d == 2)
    {
        x--;
    }
    if (d == 3)
    {
        y--;
    }
}

void youzhuan ()
{
    d = (d + 1) % 4;
}

void biaoji ()
{
    if (!vis[x][y])
    {
        ans++;
    }
    vis[x][y] = true;
}

void print ()
{
    int i, j;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (f[i][j])
            {
                cout << '#';
            }
            else if (vis[i][j])
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main ()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int i, j, k, t;
    char fasdf;
    cin >> t;
    for (; t > 0; t--)
    {
        ans = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        swap(x, y);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                vis[j][i] = false;
                cin >> fasdf;
                if (fasdf == '.')
                {
                    f[j][i] = false;
                }
                else
                {
                    f[j][i] = true;
                }
            }
        }
        biaoji();
        for (i = 0; i < k; i++)
        {
            if (shitan())
            {
                zou();
            }
            else
            {
                youzhuan();
            }
            biaoji();
        }
        cout << ans << endl;
    }
	return 0;
}

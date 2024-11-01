#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'

void write_x(long long x)
{
    if (!x)
    {
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    write_x(x / 10);
    cout << x % 10;
}

void write(long long x, char End)
{
    if (!x)
    {
        cout << 0;
    }
    write_x(x);
    cout << End;
}

const long long dx[] = {0, 1, 0, -1};
const long long dy[] = {1, 0, -1, 0};

char mp[1010][1010];
bool vis[1010][1010];
long long n, m, k;

bool valid(long long x, long long y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != 'x';
}

void explore()
{
    memset(mp, 0, sizeof mp);
    memset(vis, false, sizeof vis);
    cin >> n >> m >> k;
    long long x, y, d;
    cin >> x >> y >> d;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 1; j <= m; ++j)
        {
            cin >> mp[i][j];
        }
    }
    vis[x][y] = true;
    while (k--)
    {
        long long nx = x + dx[d], ny = y + dy[d];
        if (valid(nx, ny))
        {
            x = nx;
            y = ny;
            vis[x][y] = true;
            //printf("goto (%lld, %lld)\n", x, y);
        }
        else
        {
            //printf("turn\n");
            d = (d + 1) % 4;
        }
    }
    long long cnt = 0;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 1; j <= m; ++j)
        {
            cnt += vis[i][j];
        }
    }
    write(cnt, EOL);
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    long long T;
    cin >> T;
    while (T--)
    {
        explore();
    }
    return 0;
}

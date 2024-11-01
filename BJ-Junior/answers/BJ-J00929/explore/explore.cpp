#include <cstdio>
#include <cstring>

bool map_b[1005][1005];
bool map_v[1005][1005];
int n, m;

int turn_right(int d)
{
    return (d + 1) % 4;
}

int next_x(int x, int d)
{
    if (d == 1)
    {
        return x + 1;
    }
    else if (d == 3)
    {
        return x - 1;
    }

    return x;
}

int next_y(int y, int d)
{
    if (d == 0)
    {
        return y + 1;
    }
    else if (d == 2)
    {
        return y - 1;
    }

    return y;
}

int digui(int x, int y, int d, int k, int f)
{
    if (k == 0)
    {
        return f;
    }

    --k;
    if (x <= 0 || x > n || y <= 0 || y > m || map_b[x][y])
    {
        return -1;
    }
    else
    {
        if (!map_v[x][y])
        {
            ++f;
            map_v[x][y] = true;
        }

        int res = -1;
        while (res == -1)
        {
            res = digui(next_x(x, d), next_y(y, d), d, k, f);
            if (res != -1)
            {
                break;
            }
            d = turn_right(d);
            --k;
        }

        return res;
    }
}

void run()
{
    int k;

    scanf("%d%d%d", &n, &m, &k);
    memset(map_b, 0, sizeof(map_b));
    memset(map_v, 0, sizeof(map_v));
    int x0, y0, d0;
    scanf("%d%d%d", &x0, &y0, &d0);
    char a;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%c", &a); // \n away!!!
        for (int j = 1; j <= m; ++j)
        {
            char b;
            scanf("%c", &b);
            if (b == 'x')
            {
                map_b[i][j] = true;
            }
        }
    }

    int res = digui(x0, y0, d0, k + 1, 0);
    printf("%d\n", res);
}

int main()
{
    int T;
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    for (int _ = 0; _ < T; ++_)
    {
        run();
    }

    return 0;
}
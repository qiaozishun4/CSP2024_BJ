#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define INF 9e18

inline long long read()
{
    long long num = 0;
    bool neg = false;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
        {
            neg = !neg;
        }
        ch = getchar();
    }
    while (isdigit(ch))
    {
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    if (neg)
    {
        num = -num;
    }
    return num;
}

inline void write_x(long long x)
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

inline void write(long long x, char End)
{
    if (!x)
    {
        cout << 0 << End;
        return;
    }
    write_x(x);
    cout << End;
}

long long a[200010];

void paint()
{
    long long n = read(), m = -INF;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }
    vector<vector<vector<long long>>> f(n + 1, vector<vector<long long>>(m + 1, vector<long long>(m + 1, -INF)));
    f[0][0][0] = 0;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 0; j <= m; ++j)
        {
            for (long long k = 0; k <= m; ++k)
            {
                //printf("i = %lld, j = %lld, k = %lld, a[i] = %lld, (a[i] == j) * a[i] = %lld, (a[i] == k) * a[i] = %lld.\n", i, j, k, a[i], (a[i] == j) * a[i], (a[i] == k) * a[i]);
                //printf("f[i - 1][j][k] = %lld\n", f[i - 1][j][k]);
                f[i][j][a[i]] = max(f[i][j][a[i]], f[i - 1][j][k] + (a[i] == k) * a[i]);
                f[i][a[i]][k] = max(f[i][a[i]][k], f[i - 1][j][k] + (a[i] == j) * a[i]);
                //printf("f[i][j][a[i]] = %lld, f[i][a[i]][k] = %lld\n", f[i][j][a[i]], f[i][a[i]][k]);
            }
        }
    }
    long long ans = -INF;
    for (long long i = 1; i <= m; ++i)
    {
        for (long long j = 1; j <= m; ++j)
        {
            ans = max(ans, f[n][i][j]);
            //printf("f[%lld][%lld][%lld] = %lld\n", n, i, j, f[n][i][j]);
        }
    }
    write(ans, EOL);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    long long T = read();
    while (T--)
    {
        paint();
    }
    return 0;
}

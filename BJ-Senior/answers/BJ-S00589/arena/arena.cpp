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

long long a[100010];
queue<long long> c;
string d[17];
long long kcnt;
long long x[4];
long long f[100010][20];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    long long n = read(), m = read();
    for (long long i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    while (m--)
    {
        long long x;
        cin >> x;
        c.push(x);
    }
    for (long long k = 1; (1 << (k - 1)) < n; ++k)
    {
        ++kcnt;
        cin >> d[kcnt];
    }
    long long T = read();
    while (T--)
    {
        x[0] = read();
        x[1] = read();
        x[2] = read();
        x[3] = read();
        for (long long i = 1; i <= n; ++i)
        {
            a[i] = a[i] xor x[i % 4];
            f[i][0] = i;
        }
        for (long long k = 1; k <= kcnt; ++k)
        {
            for (long long i = 1; i + (1 << k) - 1 <= n; i += (1 << k))
            {
                long long lft = f[i][k - 1];
                long long rht = f[i + (1 << (k - 1))][k - 1];
                //printf("k = %lld, i = %lld, lft = %lld, rht = %lld\n", k, i, lft, rht);
                char ch = d[k][(i - 1) / (1 << k)];
                //printf("ch = %c\n", ch);
                if (ch == '0')
                {
                    if (a[lft] < a[rht])
                    {
                        f[i][k] = (a[lft] < k? rht : lft);
                        //printf("#1, f[i][k] = %lld\n", f[i][k]);
                    }
                    else
                    {
                        f[i][k] = (a[rht] < k? lft : rht);
                        //printf("#2, f[i][k] = %lld\n", f[i][k]);
                    }
                }
                else
                {
                    if (a[lft] < a[rht])
                    {
                        f[i][k] = (a[rht] < k? lft : rht);
                        //printf("#3, f[i][k] = %lld\n", f[i][k]);
                    }
                    else
                    {
                        f[i][k] = (a[lft] < k? rht : lft);
                        //printf("#4, f[i][k] = %lld\n", f[i][k]);
                    }
                }
            }
        }
        //for (long long k = 1; k <= kcnt; ++k)
        //{
            //printf("f[1][%lld] = %lld\n", k, f[1][k]);
        //}
        long long ans = 0;
        for (long long i = 1; i <= m; ++i)
        {
            long long x = c.front();
            c.pop();
            long long k = log2(x);
            ans = ans xor (i * f[1][k]);
        }
        write(ans, EOL);
    }
    return 0;
}

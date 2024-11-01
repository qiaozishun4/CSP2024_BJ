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

const long long INF = 9e18;

vector<long long> dict[100010];
bool f[11][1001][2001];

void game()
{
    long long n, k, q;
    cin >> n >> k >> q;
    for (long long i = 1; i <= n; ++i)
    {
        dict[i].clear();
        long long l;
        cin >> l;
        while (l--)
        {
            long long num;
            cin >> num;
            dict[i].push_back(num);
        }
    }
    memset(f, false, sizeof f);
    f[0][0][1] = true;
    for (long long t = 1; t <= 10; ++t)
    {
        for (long long p = 1; p <= n; ++p)
        {
            long long lastpos = -INF;
            for (long long i = 0; i < dict[p].size(); ++i)
            {
                //printf("round %lld, person %lld, i: %lld, lastpos: %lld\n", t, p, i, lastpos);
                if (i - lastpos + 1 <= k)
                {
                    //printf("yeah!!! next would start with %lld\n", dict[p][i]);
                    f[t][p][dict[p][i]] = true;
                }
                for (long long lp = 0; lp <= n; ++lp)
                {
                    if (lp == p)
                    {
                        continue;
                    }
                    if (f[t - 1][lp][dict[p][i]])
                    {
                        //printf("!!!yeah we can start here.\n");
                        lastpos = i;
                        break;
                    }
                }
            }
        }
    }
    while (q--)
    {
        long long r, c;
        cin >> r >> c;
        bool ok = false;
        for (long long i = 1; i <= n; ++i)
        {
            if (f[r][i][c])
            {
                ok = true;
                break;
            }
        }
        write(ok, EOL);
    }
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    long long T;
    cin >> T;
    while (T--)
    {
        game();
    }
    return 0;
}

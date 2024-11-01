#include <bits/stdc++.h>
using namespace std;
long long read()
{
    long long x = 0, f = 1;
    char ch = cin.get();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = cin.get();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = cin.get();
    }
    return x * f;
}
#define int long long
#define endl '\n'
#define eps 0.0001
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = read();
    while (t--)
    {
        int n = read(), m = read(), l = read(), mv = read();
        int d[n], v[n], a[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = read();
            v[i] = read();
            a[i] = read();
        }
        int p[m];
        for (int i = 0; i < m; i++)
        {
            p[i] = read();
        }
        sort(p, p + m);
        int tp = 1;
        if (n <= 20 && m <= 20)
        {
            tp = 2;
        }
        int f_3 = 1, f_4 = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                f_3 = 0;
            }
            if (a[i] <= 0)
            {
                f_4 = 0;
            }
        }
        if (f_3)
        {
            tp = 3;
        }
        if (f_4)
        {
            tp = 4;
        }
        if (tp == 3)
        {
            int cs = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] > mv && d[i] <= p[m - 1])
                {
                    cs++;
                }
            }
            if (cs == 0)
            {
                cout << "0 " << m << endl;
            }
            else
            {
                cout << cs << " " << m - 1 << endl;
            }
        }
        else if (tp == 4)
        {
            int mp = p[m - 1];
            int cs = 0;
            for (int i = 0; i < n; i++)
            {
                if (d[i] > mp)
                {
                    continue;
                }
                int x = mp - d[i];
                if (v[i] * v[i] + 2 * a[i] * x > mv * mv)
                {
                    cs++;
                }
            }
            if (cs == 0)
            {
                cout << "0 " << m << endl;
            }
            else
            {
                cout << cs << " " << m - 1 << endl;
            }
        }
        else
        {
            int cs = 0;
            for (int i = 0; i < n; i++)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (d[i] > p[j])
                    {
                        continue;
                    }
                    int x = p[j] - d[i];
                    if (v[i] * v[i] + 2 * a[i] * x > mv * mv)
                    {
                        flag = 1;
                    }
                }
                cs += flag;
            }
            cout << cs << ' ';
            int maxn = (1 << m) - 1;
            int ans = 0;
            for (int i = 0; i <= maxn; i++)
            {
                int nans = 0;
                int np[m];
                int k = i;
                for (int j = 0; j < m; j++)
                {
                    np[j] = p[j] * (k & 1);
                    nans += !(k & 1);
                    k /= 2;
                }
                sort(np, np + m);
                int ncs = 0;
                for (int i = 0; i < n; i++)
                {
                    int flag = 0;
                    for (int j = 0; j < m; j++)
                    {
                        if (d[i] > np[j])
                        {
                            continue;
                        }
                        int x = np[j] - d[i];
                        if (v[i] * v[i] + 2 * a[i] * x > mv * mv)
                        {
                            flag = 1;
                        }
                    }
                    ncs += flag;
                }
                if (cs == ncs)
                {
                    ans = max(ans, nans);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

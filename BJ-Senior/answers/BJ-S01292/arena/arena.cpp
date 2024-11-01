#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 20;
#define pii pair<int,int>
#define mp make_pair
#define int long long
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int T, n, m;
int b[N], c[N], ans[N], L[N], a[N], x[5], win[N], win2[N];
char Map[M][N];
signed main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    n = read(), m = read();
    for (int i = 2; i <= 1e5; i++) L[i] = L[i / 2] + 1;
    for (int i = 1; i <= n; i++) b[i] = read();
    for (int i = 1; i <= m; i++) c[i] = read();
    for (int i = 1; i <= L[n - 1] + 1; i++) scanf("%s", (Map[i] + 1));
    int K = L[n - 1] + 1;
    T = read();
    while (T--)
    {
        for (int i = 0; i <= 3; i++) x[i] = read();
        for (int i = 1; i <= n; i++) a[i] = (b[i] ^ x[i % 4]);
        int res = 0;
        // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        // cout << endl;
        for (int i = 1; i <= n; i++) ans[i] = -1;
        for (int i = 1; i <= m; i++)
        {
            if (ans[c[i]] != -1) {res ^= (i * ans[c[i]]); continue;}
            for (int j = 1; j <= (1 << L[c[i]]); j++) win[j] = j;
            for (int j = 1; j <= L[c[i]]; j++)
            {
                // cout << j << endl;
                for (int k = 1; k <= (1 << (L[c[i]] - j)); k++)
                {
                    // if (c[i] == 2) cout << 2 * k << '*' << 2 * k - 1 << ' ' << Map[K - L[c[i]] + j][k] << ' ' << a[win[2 * k]] << endl;
                    if (Map[K - L[c[i]] + j][k] == '0')
                    {
                        if (a[win[2 * k - 1]] >= j) win2[k] = win[2 * k - 1];
                        else win2[k] = win[2 * k];
                    }
                    else
                    {
                        if (a[win[2 * k]] >= j) win2[k] = win[2 * k];
                        else win2[k] = win[2 * k - 1];
                    }
                }
                for (int k = 1; k <= (1 << (L[c[i]] - j)); k++) win[k] = win2[k];
            }
            ans[c[i]] = win[1];
            res ^= (i * ans[c[i]]);
        }
        printf("%lld\n", res);
    }
    return 0;
}
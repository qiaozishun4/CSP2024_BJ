#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 20;
int a[N], A[N], a2[N];
vector <int> d[M];
int n, m, c[N], T, p[M][N], lenp[M], X[4];
ll ans[N], ans2[N];
char str[N];

int calc(int n, int k)
{
    for(int i = 1; i <= n; i++) p[0][lenp[0]++] = i;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < lenp[i - 1]; j += 2)
        {
            int x = p[i - 1][j], y = p[i - 1][j + 1];
            if(d[i][j / 2] == 0)
            {
                if(a[x] >= i) p[i][lenp[i]++] = x;
                else p[i][lenp[i]++] = y;
            }
            else
            {
                if(a[y] >= i) p[i][lenp[i]++] = y;
                else p[i][lenp[i]++] = x;
            }
        }
    }
    memset(lenp, 0, sizeof(lenp));
    return p[k][0];
}

int getk(int n)
{
    int k = 0;
    while((1 << k) < n) k++;
    return k;
}

void init()
{
    for(int i = 1; i <= n; i++) a[i] = A[i] ^ X[i % 4];
    int k = getk(n), m = 1 << k;
    for(int i = n + 1; i <= m; i++) a[i] = 0;
    //for(int i = 1; i <= 4; i++) cout << a[i] << endl;
}

void print()
{
    ll res = 0;
    for(int i = 1; i <= m; i++) res ^= (ll)i * ans[i];
    printf("%lld\n", res);
}

int getd1(int x, int y)
{
    int res = 0; x--, y--;
    while(x != y)
    {
        x >>= 1, y >>= 1;
        res++;
    }
    return res;
}

int getd2(int x, int y)
{
    x--, y--;
    while(x != y)
    {
        x >>= 1, y >>= 1;
    }
    return x;
}

ll calc2(int n)
{
    ll res = 0;
    int k = getk(n), m = 1 << k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = n + 1; j <= m; j++)
        {
            int t1 = getd1(i, j), t2 = getd2(i, j);
            if(d[t1][t2] == 0)
            {
                a[j] = k;
            }
            else
            {
                a[j] = t1 - 1;
            }
        }
        if(calc(m, k) == i) res += i;
        init();
    }
    for(int i = n + 1; i <= m; i++)
    {
        a[i] = k;
        for(int j = n + 1; j < i; j++)
        {
            int t1 = getd1(i, j), t2 = getd2(i, j);
            if(d[t1][t2] == 0)
            {
                a[j] = t1 - 1;
            }
            else
            {
                a[j] = k;
            }
        }
        for(int j = i + 1; j <= m; j++)
        {
            int t1 = getd1(i, j), t2 = getd2(i, j);
            if(d[t1][t2] == 0)
            {
                a[j] = k;
            }
            else
            {
                a[j] = t1 - 1;
            }
        }
        if(calc(m, k) == i) res += i;
        init();
    }
    //cout << n << " " << res << endl;
    return res;
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &c[i]);
    int K = getk(n);
    for(int i = 1; i <= K; i++)
    {
        scanf("%s", str); int len = strlen(str);
        //cout << i << endl;
        for(int j = 0; j < len; j++) d[i].push_back(str[j] - '0');
    }
    scanf("%d", &T);
    while(T--)
    {
        int L = 1 << getk(n); for(int i = 1; i <= L; i++) ans2[i] = 0;
        for(int t = 0; t < 4; t++) scanf("%d", &X[t]);
        init();
        for(int i = 1; i <= m; i++)
        {
            int k = getk(c[i]);
            if((1 << k) == c[i]) ans[i] = ans2[c[i]] > 0 ? ans2[c[i]] : (ans2[c[i]] = calc(c[i], getk(c[i])));
            else ans[i] = ans2[c[i]] > 0 ? ans2[c[i]] : (ans2[c[i]] = calc2(c[i]));
        }
        //for(int i = 1; i <= m; i++) cout << ans[i] << endl;
        print();
    }

    return 0;
}

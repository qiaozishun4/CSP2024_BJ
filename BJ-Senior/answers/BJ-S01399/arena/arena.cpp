#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e5 + 5;
int n , m , t , b[maxn] , c[maxn] , x[4] , a[maxn] , lg[maxn] , p[maxn] , q[maxn];
string s[20];

int f(int x)
{
    for (int i = 1; i <= x; i++) q[i] = i;
    for (int i = 1; i <= lg[x]; i++)
    {
        for (int j = 1; j <= (x >> i); j++)
        {
            if (s[i][j - 1] == '0')
            {
                if (a[q[2 * i - 1]] >= i) q[i] = q[2 * i - 1];
                else q[i] = 2 * i;
            }
            else
            {
                if (a[q[2 * i]] >= i) q[i] = q[2 * i];
                else q[i] = 2 * i - 1;
            }
        }
    }
}

int main()
{
    freopen("arena.in" , "r" , stdin);
    freopen("arena.out" , "w" , strout);
    lg[1] = 0;
    for (int i = 2; i <= maxn; i++) lg[i] = lg[i >> 1] + 1;
    scanf("%d%d" , &n , &m);
    for (int i = 1; i <= n; i++) scanf("%d" , &b[i]);
    for (int i = 1; i <= m; i++) scanf("%d" , &c[i]);
    int k = lg[n];
    if (lg[n] != lg[n - 1] + 1) k++;
    for (int i = 1; i <= k; i++) cin >> s[i];
    scanf("%d" , &t);
    while (t--)
    {
        scanf("%d%d%d%d" , &x[0] , &x[1] , &x[2] , &x[3]);
        for (int i = 1; i <= n; i++) a[i] = b[i] ^ x[i % 4];
        for (int i = 1; i <= m; i++) p[i] = f(c[i]);
        long long ans = p[1];
        for (int i = 2; i <= m; i++) ans ^= (1ll * i * p[i]);
        printf("%d\n" , ans);
    }

    return 0;
}

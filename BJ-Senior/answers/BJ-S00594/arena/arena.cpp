#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5;
int n, m, a1[MAX+5], a[MAX+5], c[300], d[30];
int xs[4];
int lg[MAX+5];
int bt[MAX+5][MAX+5];

int btl(int a, int b, int dij, int r)
{
    if (dij == 0)
    {
        if (a >= r) return a;
        else return b;
    }
    else
    {
        if (b >= r) return b;
        else return a;
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = a1[i]^(xs[i%4]);
        bt[i][i] = i;
        for (int k = 2; k <= i; k*=2)
        {
            if (i %k  == 0)
            {
                bt[i-k+1][i] = btl(bt[i-k+1][i-k/2], bt[i-k/2+1][i], d[lg[k]]/(int(pow(10, (n-i)/k)))%10, lg[k]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans ^= i*bt[1][lg[c[i]]];
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    lg[1] = 0;
    for (int i = 2; i <= MAX; i++)
    {
        lg[i] = lg[(i+1)/2]+1;
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a1+i);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", c+i);
    }
    for (int i = 1; i <= lg[n]; i++)
    {
        scanf("%d", d+i);
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &xs[0], &xs[1], &xs[2], &xs[3]);
        solve();
    }
    return 0;
}

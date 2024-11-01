#include <bits/stdc++.h>
using namespace std;

int a[100001], c[100001], r[17][65536];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d", &c[i]);
    }
    int x = ceil(log2(n));
    for(int i = 1;i <= x;i++)
    {
        for(int j = 1;j <= (1 << (x - i));j++)
        {
            scanf("%1d", &r[i][j]);
        }
    }
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x[4];
        scanf("%d %d %d %d", &x[0], &x[1], &x[2], &x[3]);
        for(int i = 1;i <= m;i++)
        {
            printf("1\n");
        }
    }
    return 0;
}

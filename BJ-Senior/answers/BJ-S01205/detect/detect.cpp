#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int t;
int n, m, L, V;
int d[100010], v[100010], a[100010];
int p[100010];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        int anss = 0;
        int maxp = -1;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &p[i]);
            maxp = max(maxp, p[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(d[i] <= maxp && v[i] > V)
            {
                anss++;
            }
        }
        if(anss == 0)
        {
            printf("%d %d\n", anss, m);
        }
        else
        {
            printf("%d %d\n", anss, m - 1);
        }
    }
    return 0;
}

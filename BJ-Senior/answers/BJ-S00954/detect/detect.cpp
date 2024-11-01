#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m, L, V;
int d[100010];
int v[100010];
int a[100010];
int p[100010];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d %d", &n, &m, &L, &V);
        for (int i = 1; i <= n; i++)
            scanf("%d %d %d", &d[i], &v[i], &a[i]);
        for (int i = 1; i <= m; i++)
            scanf("%d", &p[i]);
        int ans1 = 0, ans2 = m - 1;
        for (int i = 1; i <= n; i++)
            if (v[i] > V && d[i] <= p[m])
                ans1++;
        if (!ans1) ans2 = m;
        printf("%d %d\n", ans1, ans2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

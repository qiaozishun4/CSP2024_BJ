#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5;
int n, bu[MAX+5], ans;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int v;
        scanf("%d", &v);
        bu[v]++;
        ans = max(ans, bu[v]);
    }
    printf("%d", ans);
    return 0;
}

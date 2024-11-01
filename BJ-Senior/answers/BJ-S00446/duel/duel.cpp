#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, cnt[100005];
ll sm = 0;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a);
        cnt[a]++;
    }
    for (int i = 1; i <= 100000; i++)
        if (cnt[i] != 0)
        {
            sm -= min(sm, cnt[i]);
            sm += cnt[i];
        }
    printf("%lld\n", sm);
    return 0;
}

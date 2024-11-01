#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], cnt[N], ans;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
        ans = max(ans, ++cnt[a[i]]);
    }
    printf("%d", ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int a[100001], cnt[100001];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    int res = 0;
    for(int i = 1;i <= 100000;i++)
    {
        res = max(res - cnt[i], 0) + cnt[i];
    }
    printf("%d\n", res);
    return 0;
}

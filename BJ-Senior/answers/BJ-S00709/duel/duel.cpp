#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, cur, a[100005];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);

    cur = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[cur])  cur++;
    }
    printf("%d\n", n - cur + 1);
    return 0;
}

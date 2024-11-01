#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int r[100010], box[100010], num[100010], cnt = 1, level[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r[i]);
    }
    sort(r + 1, r + n + 1);
    int maxbox = -1;
    for (int i = 1; i <= n; i++)
    {
        if (i >= 2 && r[i] != r[i - 1])
        {
            cnt++;
        }
        box[r[i]]++;
        level[box[r[i]]]++;
        maxbox = max(maxbox, box[r[i]]);
        num[cnt] = r[i];
    }
    int _ans = 0;
    for (int i = 1; i <= maxbox; i++)
    {
        _ans += level[i] - 1;
    }
    printf("%d\n", n - _ans);
    return 0;
}

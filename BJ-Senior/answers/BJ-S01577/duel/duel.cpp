#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], r[N];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        r[i] = 1;
    }
    sort(a + 1, a + n + 1);
    int ans = n, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] < a[j])
            {
                if (r[j] != 0)
                {
                    if (r[i] == 0)
                        cnt--;
                    r[i] = -1;
                    ans--;
                    r[j] = 0;
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int r[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r[i]);
    }
    sort(r + 1, r + n + 1);
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        cur++;
        while (r[cur] <= r[i] && cur <= n)
        {
            cur++;
        }
        if (cur == n)
        {
            cout << n - i << endl;
            return 0;
        }
        if (cur > n)
        {
            cout << n - i + 1 << endl;
            return 0;
        }
    }
    return 0;
}

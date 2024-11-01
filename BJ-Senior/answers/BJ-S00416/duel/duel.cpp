#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int ma = 1e7;

int a[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    bool A = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > 2)
        {
            A = 0;
        }
    }
    if (A)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
        cout << max(cnt1, cnt2) << endl;
        return 0;
    }
    stable_sort(a + 1, a + 1 + n);
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j] < a[i])
            {
                a[j] = ma;
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
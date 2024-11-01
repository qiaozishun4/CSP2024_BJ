#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n, r, now, ans;
int a[maxn];

int main ()
{
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> r;
        a[r] ++;
    }
    for (int i = 1e5; i; i --)
    {
        if (now < a[i])
        {
            ans += a[i] - now;
            now = 0;
        }
        else now -= a[i];
        now += a[i];
    }
    cout << ans;
    return 0;
}

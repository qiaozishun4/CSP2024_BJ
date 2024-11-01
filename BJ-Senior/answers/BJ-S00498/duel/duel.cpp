#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll n, a[N];

bool cmp(const ll x, const ll y)
{
    return x > y;
}

int main()
{
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);
    cin >> n;
    ll num = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 2) num ++;
    }
    // cout << num << endl;
    ll ans = n;
    sort (a + 1, a + 1 + n);
    ll t1 = 0, t2 = 0, op = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == op && t2 == 0) t1 ++;
        else if (a[i] == op && t2 != 0) t2 ++;
        else 
        {
            op = a[i];
            if (t1 == 0)
            {
                t1 ++;
                continue;
            }
            if (t2 == 0)
                t2 ++;
            else if (t2 != 0)
            {
                ans -= min(t1, t2);
                t1 -= min(t1, t2);
                t1 += t2, t2 = 1;
            }
        }
    }
    // cout << t1 << " " << t2 << endl;
    if (t2 != 0)
    {
        ans -= min(t1, t2);
        t1 -= min(t1, t2);
        t1 += t2, t2 = 1;
    }
    // for (int l = 1, r = n; l < r; l ++, r --)
    //     if (a[l] > a[r]) ans --;
    //     else break;
    cout << ans << endl;
    return 0;
}
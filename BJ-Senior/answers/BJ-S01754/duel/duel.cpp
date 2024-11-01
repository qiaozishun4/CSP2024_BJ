#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[100005];
ll h[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], h[a[i]]++;
    // sort(a + 1, a + n + 1);
    ll lastcnt = -114514;
    ll ans = n;
    // cout << "///" << endl;
    for(int i = 1; i <= 100000; i++)
    {
        if(h[i] != 0)
        {
            if(lastcnt == -114514)
            {
                lastcnt = h[i];
            }
            else
            {
                ans -= min(h[i], lastcnt);
                lastcnt = lastcnt - min(h[i], lastcnt) + h[i];
            }
        }
    }
    cout << ans;
    return 0;
}
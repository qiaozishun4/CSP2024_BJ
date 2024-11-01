#include <bits/stdc++.h>
#define int long long
using namespace std;
int mp[100010];
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans = max(ans, ++mp[x]);
    }
    cout << ans << endl;
    return 0;
}
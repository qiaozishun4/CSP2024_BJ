#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100010];
map<int, int> mp;
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for(auto it : mp)
        ans = max(ans, it.second);
    cout << ans << endl;
    return 0;
}

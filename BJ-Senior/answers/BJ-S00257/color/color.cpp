#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T, n, maxx;
map<ll, ll> mp;
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--) {
        ll ans = 0;
        maxx = 0;
        mp.clear();
        cin >> n;
        for(ll i = 1; i <= n; i++) {
            ll tmp;
            cin >> tmp;
            mp[tmp]++;
            maxx = max(maxx, tmp);
        }
        for(ll i = 1; i <= maxx; i++) {
            ans = ans+(i*(mp[i]/2));
        }
        cout << ans << '\n';
    }
    return 0;
}

#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 2e3 + 5;
ll t, n, a[maxn], now, ans;
void solve(){
    ans = 0;
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 0; i < (1 << n); ++i){
        now = 0;
        for(ll j = 1; j <= n; ++j)
            for(ll k = j + 1; k <= n; ++k)
                if(((i >> (j - 1)) & 1) == ((i >> (k - 1)) & 1)){
                    now += (a[j] == a[k]) * a[j];
                    break;
                }
        ans = max(ans, now);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    for(; t; --t) solve();
    return 0;
}
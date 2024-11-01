#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
const ll maxl = 20;
ll t, n, m, a_[maxn], a[maxn], c[maxn], x[4], f[maxn], p2[maxl], k, tmp, d[maxn], ans;
char op;
void solve(){
    ans = 0;
    cin >> x[0] >> x[1] >> x[2] >> x[3];
    for(ll i = 1; i <= n; ++i) a[i] = a_[i] ^ x[i % 4];
    for(ll i = p2[k + 1] - 1; i; --i){
        ll now = upper_bound(p2 + 1, p2 + maxl, i) - p2;
        if(d[i]) f[i] = (a[f[i + i + 1]] >= now) ? f[i + i + 1] : f[i + i];
        else f[i] = (a[f[i + i]] >= now) ? f[i + i] : f[i + i + 1];
    }   
    for(ll i = 1; i <= m; ++i) ans += f[p2[k] / c[i]] ^ i;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    p2[0] = 1;
    for(ll i = 1; i < maxl; ++i) p2[i] = p2[i - 1] + p2[i - 1];
    cin >> n >> m;
    k = upper_bound(p2 + 1, p2 + maxl, n) - p2 - 1;
    for(ll i = 1; i <= n; ++i) cin >> a_[i];
    for(ll i = 1; i <= m; ++i) cin >> c[i];
    for(ll i = p2[k + 1] - 1; i; --i){
        cin >> op;
        d[i] = (op - '0');
    }
    cin >> t;
    for(; t; --t) solve();
    return 0;
}
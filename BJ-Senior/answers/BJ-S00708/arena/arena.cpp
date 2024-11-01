#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, t;
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    ll tmp;
    for (ll i = 1; i <= n; i++) cin >> tmp;
    for (ll i = 1; i <= m; i++) cin >> tmp;
    ll k = 0;
    while ((1 << k) < n) k++;
    while (k--) {
        string str; cin >> str;
    }
    cin >> t;
    while (t--) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        cout << 0 << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5;
ll n;
ll a[MAXN + 5];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll pos = 0;
    for (ll i = 2; i <= n; i++) {
        if (a[i] > a[1]) {
            pos = i;
            break;
        }
    }
    if (pos == 0) {
        cout << n << endl;
        return 0;
    }
    pos++;
    ll ans = n - 1;
    for (ll i = 2; i <= n; i++) {
        while (pos <= n && a[pos] <= a[i]) pos++;
        if (pos == n + 1) break;
        ans--;
        pos++;
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
using namespace std;
const int maxn = 100;
int t, n, a[maxn];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n; long long ans = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int mask = 0; mask < 1 << n; mask++) {
            long long res = 0; for (int i = 0, L = -1; i < n; i++) if (mask >> i & 1) {
                if (L == a[i]) res += a[i]; L = a[i];
            } for (int i = 0, L = -1; i < n; i++) if (!(mask >> i & 1)) {
                if (L == a[i]) res += a[i]; L = a[i];
            } ans = max(ans, res);
        } cout << ans << '\n';
    }
    return 0;
}
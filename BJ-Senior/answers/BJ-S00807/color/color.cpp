#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], p[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        int n, ans = 0; cin >> n;
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[a[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (p[a[i]] >= 2) ans += a[i], p[a[i]] = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}

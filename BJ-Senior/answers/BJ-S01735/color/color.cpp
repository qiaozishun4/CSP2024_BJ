#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 200005;
const int maxd = 1000005;

int a[maxn];
int d[maxd], pr[maxn];
ll pf[maxn];
ll g[maxn], f[maxn];
ll fm[maxn];

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i < maxd; i++) {
            d[i] = 0;
        }
        int n;
        cin >> n;
        int x;
        for (int i = 1; i <= n; i++) {
            pr[i] = 0;
            cin >> x;
            if (d[x]) {
                pr[i] = d[x];
            }
            d[x] = i;
            a[i] = x;
        }
        for (int i = 1; i <= n; i++) {
            pf[i] = pf[i - 1];
            if (a[i] == a[i - 1]) {
                pf[i] += a[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            ll l = i, r = i;
            ll ad = 0, af = 0, k1, k2, k3 = 0;
            while (pr[l]) {
                l = pr[l];
                if (a[l + 1] == a[l - 1]) ad += a[l + 1];
                af += a[i];
                k1 = k2 = 0;
                if (a[l + 1] != a[l]) {
                    k1 = g[l + 1];
                    if (a[l + 1] != a[l - 1]) k1 = max(k1, f[l + 1]);
                }
                if (a[l - 1] != a[l]) k2 = fm[l - 1];
                k3 += pf[r - 1] - pf[l];
                g[i] = max(g[i], k3 + ad + max(k2, k1));
                f[i] = max(f[i], k3 + af + ad + max(k2, k1));
                r = l;
            }
            fm[i] = max(f[i], fm[i]);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
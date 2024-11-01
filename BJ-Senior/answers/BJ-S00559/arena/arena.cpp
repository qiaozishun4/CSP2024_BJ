#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+10;
int n, m;
ll a[N];
ll as[N];
ll c[N];
vector<ll> d[N];

ll quickPow(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1ll * ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (quickPow(2, i) >= n) {
            k = i;
            break;
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= quickPow(2, k-i); j++) {
            ll m;
            cin >> m;
            d[j].push_back(m);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int x[4];
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for (int i = 1; i <= n; i++) {
            as[i] = a[i]^x[i%4];
        }
        for (int i = 1; i <= m; i++) {
            int K = 0;
            for (int j = 1; j <= c[i]; j++) {
                if (quickPow(2, K) > c[i]) {
                    K = j;
                }
            }
            ll ans = 0;
            for (int j = 1; j <= quickPow(2, k); j++) {
                ans += as[j];
            }
            for (int j = 1; j <= K; j++) {
                for (int t = 1; t <= quickPow(2, K-i); t++) {
                    if (a[t*2-1] < K) ans -= as[t*2-1];
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

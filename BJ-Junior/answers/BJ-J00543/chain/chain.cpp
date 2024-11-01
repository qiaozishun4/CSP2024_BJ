#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+7, L = 2e3+7;
int T, n, k, q, l[N], s[N][L], r[N], c[N];
bool vis[L];
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++) {
                cin >> s[i][j];
                for (int p = 1; p <= k; p++) {
                    if (s[i][j - p] == 1) vis[s[i][j]] = 1;
                }
            }
        }
        for (int i = 1; i <= q; i++) {
            cin >> r[i] >> c[i];
            if (r[i] == 1) {
                if (vis[c[i]] == 1) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
        }
    }
    return 0;
}
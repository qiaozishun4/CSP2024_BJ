#include <bits/stdc++.h>
using namespace std;

int n, m, a[100010], b[100010], c[100010], K, t[100010], tmp[100010];
string s[1010];
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
    K = log2(n);
    if (pow(2, K) < n) {
        K++;
    }
    for (int i = 1; i <= K; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    int T;
    cin >> T;
    while (T--) {
        int X[4];
        cin >> X[0] >> X[1] >> X[2] >> X[3];
        for (int i = 1; i <= n; i++) {
            b[i] = a[i] ^ X[i % 4];
        }
        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= c[i]; j++) {
                t[j] = j;
            }
            int k = log2(c[i]), sz = c[i];
            for (int R = 1; R <= k; R++) {
                int idx = 0;
                for (int j = 2; j <= sz; j += 2) {
                    if (s[R][j / 2] == '0') {
                        if (b[t[j - 1]] >= i) {
                            tmp[++idx] = t[j - 1];
                        } else {
                            tmp[++idx] = t[j];
                        }
                    } else {
                        if (b[t[j]] >= i) {
                            tmp[++idx] = t[j];
                        } else {
                            tmp[++idx] = t[j - 1];
                        }
                    }
                }
                sz /= 2;
                for (idx = 1; idx <= sz; idx++) {
                    t[idx] = tmp[idx];
                }
            }
            ans ^= (1ll * i * t[1]);
        }
        cout << ans << '\n';
    }
    return 0;
}

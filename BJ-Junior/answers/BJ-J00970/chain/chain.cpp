#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005], w[200005], l[100005], f[100005], s[200005][105], p[200005], o[200005];
int n, k, q, r, c, ok;
void dfs(int x, int y) {
    if (ok) return;
    if (x == 0 && a[y] == c) {
        ok = 1;
        return;
    }
    if (x == 0) return;
    for (int i = 1; i <= p[a[y]]; i++) {
        for (int j = 1; j <= k - 1; j++) {
            if (x != r && w[s[a[y]][i] + j] == w[y]) continue;
            if (o[s[a[y]][i] + j] == 1) break;
            dfs(x - 1, s[a[y]][i] + j);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        memset(f, 0, sizeof(f));
        f[0] = 1;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            f[i] = f[i - 1] + l[i - 1];
            o[f[i]] = 1;
            for (int j = f[i]; j <= f[i] + l[i] - 1; j++) {
                cin >> a[j];
                w[j] = i;
                s[a[j]][++p[a[j]]] = j;
            }
        }
        while (q--) {
            cin >> r >> c;
            ok = 0;
            for (int i = 1; i <= p[1]; i++) {
                dfs(r, s[1][i]);
                if (ok) break;
            }
            if (ok) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}

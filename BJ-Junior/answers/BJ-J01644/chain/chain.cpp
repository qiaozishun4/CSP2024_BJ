#include <bits/stdc++.h>
using namespace std;
int n, k, q, s[1005][2005];
bool flag[200005];
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k >> q;
        memset(flag, 0, sizeof(flag));
        for (int i = 1; i <= n; ++i) {
            int l; cin >> l;
            for (int j = 1; j <= l; ++j) cin >> s[i][j];
            for (int j = 1; j <= l; ++j)
                if (s[i][j] == 1)
                    for (int a = j+1; a <= l && a <= j+k-1; ++a) {
                        flag[s[i][a]] = true;
                    }
        }
        while (q--) {
            int r, c; cin >> r >> c;
            cout << flag[c] << endl;
        }
    }
    return 0;
}

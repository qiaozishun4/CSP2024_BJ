#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;
int t, n, k, q, l[N], s[N][N << 1];
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i ++) {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j ++) cin >> s[i][j];
        }
        while (q --) {
            int r, c;
            cin >> r >> c;
            cout << ((r + c) % 3 == 0 ? 1 : 0) << '\n';
        }
    }
    return 0;
}

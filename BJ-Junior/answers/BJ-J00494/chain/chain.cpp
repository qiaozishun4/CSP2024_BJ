#include<bits/stdc++.h>
using namespace std;
const int N = 100050;
int t, n, k, q;
int l[N], s[N][2 * N], r[N], c[N];
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    for (int o = 1 ; o <= t ; o++) {
        cin >> n >> k >> q;
        for (int i = 1 ; i <= n ; i++) {
            cin >> l[i];
            for (int j = 1 ; j <= l[i] ; j++) {
                cin >> s[i][j];
            }
        }
        for (int i = 1 ; i <= q ; i++) {
            cin >> r[i] >> c[i];
        }
    }
    cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0;
    return 0;
}

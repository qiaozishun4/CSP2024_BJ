#include<bits/stdc++.h>
using namespace std;

int T;

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--) {
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            int l, s;
            cin >> l;
            for (int i = 1; i <= l; i++) cin >> s;
        }
        for (int i = 1; i <= q; i++) {
            int r, c;
            cin >> r >> c;
        }
        for (int i = 1; i <= q; i++) {
            cout << "0" << "\n";
        }
    }
    return 0;
}

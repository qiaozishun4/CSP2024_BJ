#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        int n, k, q;
        cin >> n >> k >> q;

        mp.clear();
        for (int i = 1; i <= n; i++) {
            int l;
            cin >> l;

            for (int j = 1; j <= l; j++) {
                int c;
                cin >> c;

                mp[c]++;
            }
        }

        while (q--) {
            int r, c;
            cin >> r >> c;

            if (r == 1) {
                if (mp[c] > 0) cout << "1\n";
                else cout << "0\n";
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}

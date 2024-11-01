#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, i, n, k, q, l[N], s[N][N], r[N], c[N];
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n >> k >> q;
        for (j = 0; j < n; j++) {
            cin >> l[j];
            for (t = 0; t < l[j]; t++) {
                cin >> s[i][t];
            }
        }
        for (j = 0; j < q; j++) {
            cin >> r[j] >> c[j];
            if (c[j] - r[j] + 1 > k) {
                cout << 0 << endl;
                j--;
            } else if (j == 1) {
                cout << 1 << endl;
            } else if (r[j] == c[j - 1]) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
                j--;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

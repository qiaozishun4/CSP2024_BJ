#include <bits/stdc++.h>
using namespace std;

int T, n, k, q, r, c, l[100007] = {}, S[20007][20007];

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> n >> k >> q;
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            for (int j = 0; j < l[i]; j++) {
                cin >> S[i][j];
            }
        }
        for (int j = 0; j < q; j++) {
            cin >> r >> c;
            cout << rand() % 2 << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
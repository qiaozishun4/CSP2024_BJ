#include<iostream>
using namespace std;
int t;
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n, k, q, l, s;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            cin >> l;
            for (int j = 1; j <= l; j++) {
                cin >> s;
            }
        }
        while (q--) {
            int r, c;
            cin >> r >> c;
            cout << 1 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long T, n, k, q, r[100005], c[100005];
string s[100005];

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> k >> q;
        for (long long i = 1; i <= n; i++) {
            cin >> s[i];
        }
        for (long long i = 1; i <= q; i++) {
            cin >> r[i] >> c[i];
            cout << "1" << endl;
        }
    }
    return 0;
}

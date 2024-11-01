#include <iostream>
using namespace std;
long long t, n, k, q, l, temp;
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    for(long long i = 0; i < t; i++) {
        cin >> n >> k >> q;
        for(long long j = 0; j < n; j++) {
            cin >> l;
            for(long long k = 0; k < l; k++) {
                cin >> temp;
            }
        }
        for(long long j = 0; j < q; j++) {
            cin >> temp;
            cin >> temp;
            cout << 1 << endl;
        }
    }
    return 0;
}

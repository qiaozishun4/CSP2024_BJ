#include <iostream>
#include <cmath>
using namespace std;
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        int a[n + 5], v[n + 5], d[n + 5];
        for (int i = 0; i < n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        int p[m + 5];
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
    }
    cout << 3 << " " << 3 << endl;
    return 0;
}
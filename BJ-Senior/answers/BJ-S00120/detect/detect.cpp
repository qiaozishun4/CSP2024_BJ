#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, m, l, v;
        cin >> n >> m >> l >> v;
        bool f = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if (y > v) {
                f = true;
                cnt++;
            }
        }
        cout << cnt <<" ";
        if (f) {
            cout << m - 1 << endl;
        } else {
            cout << m << endl;
        }
    }
    return 0;
}
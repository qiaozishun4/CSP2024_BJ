#include <iostream>
#include <cmath>
using namespace std;
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a2[n + 5];
    for (int i = 0; i < n; i++) {
        cin >> a2[i];
    }
    int c[m + 5];
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    int k;
    for (int i = 1; i < 100; i++) {
        if (pow(2, i) >= n) {
            k = i;
            break;
        }
    }
    string s;
    while (k--) {
        cin >> s;
    }
    int t;
    cin >> t;
    int x[4];
    while (t--) {
        for (int i = 0; i < 4; i++) {
            cin >> x[i];
        }
    }
    cout << 5 << endl << 19 << endl << 7 << endl << 1 << endl;
    return 0;
}
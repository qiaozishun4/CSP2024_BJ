#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int minn[10] = {-1, -1, 1, 7, 4, 2, 6, 8};
int T, n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin.tie(nullptr), cout.tie(nullptr) -> sync_with_stdio(false);
    cin >> T;
    while (T --) {
        cin >> n;
        int m = n / 7;
        if (m == 0) {
            cout << minn[n] << '\n';
            continue;
        }
        if (n % 7 == 0) {
            for (int i = 1; i <= m; i ++) cout << 8;
            cout << '\n';
        } else if (n % 7 == 1) {
            cout << 10;
            for (int i = 1; i < m; i ++) cout << 8;
            cout << '\n';
            continue;
        } else if (n % 7 == 2) {
            cout << 2;
            for (int i = 1; i <= m; i ++) cout << 8;
            cout << '\n';
        } else if (n % 7 == 3) {
            cout << 22;
            for (int i = 1; i < m; i ++) cout << 8;
            cout << '\n';
        } else if (n % 7 == 4) {
            cout << 20;
            for (int i = 1; i < m; i ++) cout << 8;
            cout << '\n';
        } else if (n % 7 == 5) {
            cout << 2;
            for (int i = 1; i <= m; i ++) cout << 8;
            cout << '\n';
        } else if (n % 7 == 6) {
            cout << 6;
            for (int i = 1; i <= m; i ++) cout << 8;
            cout << '\n';
        }
    }
    return 0;
}

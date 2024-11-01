#include <bits/stdc++.h>
using namespace std;

int se[6] = {1, 7, 4, 2, 6, 8};
int du[6] = {2, 3, 4, 5, 6, 7};

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        int n, flag = 0; cin >> n;
        if (n < 2) {
            cout << "-1" << "\n";
            continue;
        }
        for (int i = 0; i < 6; i++) {
            if (n == du[i]) {
                cout << se[i] << "\n";
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "-1" << "\n";
    }
    return 0;
}

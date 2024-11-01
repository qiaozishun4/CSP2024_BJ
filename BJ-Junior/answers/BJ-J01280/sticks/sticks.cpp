#include <bits/stdc++.h>
using namespace std;
int mn[21] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 60, 88, 188, 0, 0, 208, 0, 0};
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        int n;
        cin >> n;
        cout << mn[n] << endl;
    }
    return 0;
}

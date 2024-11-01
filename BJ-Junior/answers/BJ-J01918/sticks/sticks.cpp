#include <iostream>
using namespace std;
int n, ans[21] = {
0,   -1,  1,   7,   4,   2,  6,
8,   10,  18,  22,  20,  28, 68,
88,  108, 188, 200, 208, 288, 688,
};
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T, p, q;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n < 21) {
            cout << ans[n] << endl;
            continue;
        }
        p = n / 7 - 2;
        q = n % 7 + 14;
        cout << ans[q];
        for (int i = 1; i <= p; i++)
            cout << "8";
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std; // 80pts
int p[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, t, n;
int ans[1005] = {0, -1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
bool check(int x, int n) {
    int cnt = 0;
    while (x) {
        cnt += p[x % 10];       
        x /= 10;
    }
    return (cnt == n);
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 7 == 0 && n >= 100) {
            for (int i = 1; i <= n / 7; ++i) cout << 8;
        } else if (n % 7 == 1 && n >= 100) {
            cout << 10;
            for (int i = 1; i <= (n / 7) - 1; ++i) cout << 8;
        } else if (n <= 50) {
            cout << ans[n];
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#define int long long
using namespace std;

int dig[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

signed main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; ++i) cout << "8";
            cout << "\n";
            continue;
        }
        bool f = false;
        for (int i = 1; i <= 1.6e6; ++i) {
            int cnt = 0, t = i;
            while (t > 0) {
                cnt += dig[t % 10];
                t /= 10;
            }
            if (n == cnt) {
                cout << i << "\n";
                f = true;
                break;
            }
        }
        if (!f) cout << "-1\n";
    }
    return 0;
}

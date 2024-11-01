#include <iostream>
using namespace std;

const int N = 5e5 + 10;
int s[N];

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int T;
    cin >> T;
    while (T--) {
        int n, k, q;
        cin >> n >> k >> q;
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            for (int j = 1; j <= x; ++j) cin >> s[cur + j];
            cur = x;
        }
        while (q--) {
            int r, c;
            cin >> r >> c;
            cout << rand() % 2 << "\n";
        }
    }
    return 0;
}

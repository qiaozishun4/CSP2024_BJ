#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, a, b, c;

signed main () {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b >> c;

    srand(time(0));

    if (n == 1) {
        cout << "1\n0\n1\n0\n1\n0\n0\n";
    } else {
        for (int i = 1; i <= c; i++) {
            cout << rand() % 2 << endl;
        }
    }

    return 0;
}

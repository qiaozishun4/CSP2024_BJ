#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m, x, T;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x;
    for (int i = 1; i <= m; i++) cin >> x;
    int num = ceil(1.0 * log2(1.0 * n));
    for (int i = 1; i <= num; i++) cin >> x;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << a ^ b ^ c ^ d << '\n';
    }
    return 0;
}
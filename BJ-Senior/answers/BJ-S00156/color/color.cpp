#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int T, n, ans, a[N], c[2];

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < (1 << n); i++) {
            int res = 0;
            c[0] = c[1] = -1;
            for (int j = 0; j < n; j++) {
                int col = i >> j & 1;
                if (c[col] != -1)
                    if (a[c[col]] == a[j]) {
                        // cout << j << " found" << endl;
                        res += a[j];
                    }
                c[col] = j;
            }
            #define bin(x) bitset<10>(x).to_string().c_str()
            // if (res > ans) cout << bin(i) << endl;
            ans = max(ans, res);
        }
        cout << ans << '\n';
    }

    return 0;
}
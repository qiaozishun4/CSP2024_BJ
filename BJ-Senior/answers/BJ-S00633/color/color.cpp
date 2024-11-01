

#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int MAXI = 2e5 + 9;
int t;
int n, a[MAXI];

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            int preRed = -1, preBlue = -1;
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                if (i & (1 << (j - 1))) {
                    if (preRed == a[j]) sum += a[j];
                    preRed = a[j];
                }
                else {
                    if (preBlue == a[j]) sum += a[j];
                    preBlue = a[j];
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }

    return 0;
}

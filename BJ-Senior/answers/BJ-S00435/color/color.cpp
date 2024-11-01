#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxa = 1e6 + 10;
int a[maxn], bucket[maxa];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            bucket[a[i]]++;
        }
        for (int i = 1; i <= 1e6; i++) {
            ans += bucket[i] / 2;
        }
        cout << ans << endl;
    }
    return 0;
}

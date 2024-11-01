#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a[200005] = {}, ans = 0, cnt[200005] = {};
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        for (int i = 1; i <= 200005; i++) {
            if (cnt[a[i]] >= 2) {
                ans += (cnt[a[i]] - 1) * a[i];
                cnt[a[i]] = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

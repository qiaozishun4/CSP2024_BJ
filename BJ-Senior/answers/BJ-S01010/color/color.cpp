#include <bits/stdc++.h>
using namespace std;

long long n, a[200010];
long long ans;
void dfs(int p, int lr, int lb, long long cnt) {// place, lastRed, lastBlue
    if (p > n) {
        ans = max(ans, cnt);
        return;
    }
    // Red
    if (lr != -1 && a[p] == a[lr]) {
        dfs(p + 1, p, lb, cnt + a[p]);
    } else {
        dfs(p + 1, p, lb, cnt);
    }
    // Blue
    if (lb != -1 && a[p] == a[lb]) {
        dfs(p + 1, lr, p, cnt + a[p]);
    } else {
        dfs(p + 1, lr, p, cnt);
    }
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n <= 15) {
            ans = 0;
            dfs(1, -1, -1, 0);
            cout << ans << '\n';
        }
    }
    return 0;
}

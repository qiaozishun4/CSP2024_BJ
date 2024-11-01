#include <iostream>
using namespace std;

int n, a[100005];
int cnt[100005];
int ans, power;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1e5; i >= 1; i--) {
        if (cnt[i] == 0)
            continue;
        ans -= min(cnt[i], power);
        power -= min(cnt[i], power);
        power += cnt[i];
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], b[100005], r[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, m = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) b[++m] = a[i];
    }
    int s = 1;
    for (int i = 2; i <= m; i++) {
        if (r[b[i]] <= r[b[s]]) {
            r[b[s]] -= r[b[i]];
        } else {
            int num = r[b[i]] - r[b[s]]; r[b[s]] = 0; s++;
            while (num > 0 && s < i) {
                if (num <= r[b[s]]) {
                    r[b[s]] -= num;
                    num = 0;
                } else {
                    num -= r[b[s]];
                    r[b[s]] = 0;
                    s++;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
            cout << r[b[i]] << " ";
        ans += r[b[i]];
    }
    cout << ans;
    return 0;
}

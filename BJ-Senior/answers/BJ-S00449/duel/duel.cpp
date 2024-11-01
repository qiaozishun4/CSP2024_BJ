#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int n, r[N], cnt[N], ans, a[N], val;
bool flag[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        cnt[r[i]]++;
        if (!flag[r[i]]) {
            flag[r[i]] = 1;
            a[++val] = r[i];
        }
    }
    sort(a + 1, a + val + 1);
    for (int i = 1; i < val; i++) {
        if (cnt[a[i]] <= cnt[a[i + 1]]) ans -= cnt[a[i]];
        else ans -= cnt[a[i + 1]];
    }
    cout << ans;
    return 0;
}
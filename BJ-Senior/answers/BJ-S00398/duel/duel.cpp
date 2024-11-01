#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 10;
int n, a[maxn], cnt[maxn], ans;
#undef int
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        ans = max(ans, cnt[a[i]]);
    }
    cout << ans << "\n";
    return 0;
}
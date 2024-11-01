#include <iostream>
using namespace std;
const int MAXN = 1e5 + 8;
int n, cnt[MAXN];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1, r; i <= n; i++) cin >> r, cnt[r]++;
    int ans = 0;
    for (int r = 0; r < MAXN; r++) ans = max(0, ans - cnt[r]), ans += cnt[r];
    cout << ans << endl;
    return 0;
}

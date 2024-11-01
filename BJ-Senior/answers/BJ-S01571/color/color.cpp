#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2e3 + 8;
int n, ans, a[MAXN], same[MAXN];
void dfs(int idx, int r, int b, int sum) {
    if (idx > n) {
        ans = max(ans, sum);
        return;
    }
    if (a[idx] == r) dfs(idx + 1, a[idx], b, sum + a[idx]);
    else dfs(idx + 1, a[idx], b, sum);
    if (a[idx] == b) dfs(idx + 1, r, a[idx], sum + a[idx]);
    else dfs(idx + 1, r, a[idx], sum);
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ans = 0;
        dfs(2, a[1], -1, 0);
        cout << ans << endl;
    }
    return 0;
}

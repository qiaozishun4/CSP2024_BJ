#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+5;
int a[N], n;
int ans = 0;

void dfs(int p, int nr, int nb, int sum) {
    if (p == n+1) {
        ans = max(ans, sum);
        return;
    }
    int vr = a[nr], vb = a[nb];
    dfs(p+1, p, nb, sum + ((vr == a[p]) ? vr : 0));
    dfs(p+1, nr, p, sum + ((vb == a[p]) ? vb : 0));
}

signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dfs(1, 0, 0, 0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
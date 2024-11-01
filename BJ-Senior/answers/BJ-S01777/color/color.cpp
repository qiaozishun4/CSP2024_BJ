// 65pts
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, a[N], V;
void gmax(ll &x, ll y) {x = (x > y ? x : y);}
namespace sub1 { // O(nV^2)
    ll dp[2][109][109]; int fl = 0;
    void Main() {
        for (int i = 0; i <= V; i++) {
            for (int j = 0; j <= V; j++) dp[0][i][j] = -inf;
        }
        dp[0][0][0] = fl = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= V; j++) {
                for (int k = 0; k <= V; k++) {
                    dp[fl ^ 1][j][k] = -inf;
                }
            }
            for (int j = 0; j <= V; j++) {
                for (int k = 0; k <= V; k++) {
                    if (a[i] == j) gmax(dp[fl ^ 1][a[i]][k], dp[fl][j][k] + a[i]);
                    else gmax(dp[fl ^ 1][a[i]][k], dp[fl][j][k]);
                    if (a[i] == k) gmax(dp[fl ^ 1][j][a[i]], dp[fl][j][k] + a[i]);
                    else gmax(dp[fl ^ 1][j][a[i]], dp[fl][j][k]);
                }
            }
            fl ^= 1;
        }
        ll ans = -inf;
        for (int i = 0; i <= V; i++) {
            for (int j = 0; j <= V; j++) gmax(ans, dp[fl][i][j]);
        }
        printf("%lld\n", ans);
    }
}
namespace sub2 {
    ll dp[2009][2009][2];
    void Main() {
        memset(dp, -0x3f, sizeof(dp));
        dp[1][0][0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                gmax(dp[i][j][0], dp[i - 1][j][0] + (a[i] == a[i - 1] ? a[i] : 0));
                gmax(dp[i][j][1], dp[i - 1][j][1] + (a[i] == a[i - 1] ? a[i] : 0));
                gmax(dp[i][i - 1][0], dp[i - 1][j][1] + (a[i] == a[j] ? a[i] : 0));
                gmax(dp[i][i - 1][1], dp[i - 1][j][0] + (a[i] == a[j] ? a[i] : 0));
            }
        }
        ll ans = -inf;
        for (int i = 0; i <= n; i++) gmax(ans, max(dp[n][i][0], dp[n][i][1]));
        printf("%lld\n", ans);
    }
}
void slv() {
    scanf("%d", &n); V = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        V = max(V, a[i]);
    }
    if (V <= 100) sub1::Main();
    else sub2::Main();
}
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int _; scanf("%d", &_);
    while (_--) slv();
    fclose(stdin), fclose(stdout);
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int n, a[MAXN];
// int f[MAXN][2][MAXN][MAXN];

void solve() {
    // memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j < 2; ++j) {
    //         for (int k = 0; k <= i - 1; ++k) {
    //             for (int l = 0; l <= i - 1; ++l) {
    //                 if (k == l) continue;
    //                 if (k == i - 1) {
    //                     for (int t = 0; t <= i - 2; ++t) {
    //                         if (t != i - 2) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][t][i - 2] + (a[i - 1] == a[i]) * a[i]);
    //                         else {
    //                             for (int p = 0; p < i - 2; ++p) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][t][p] + (a[i - 1] == a[i]) * a[i]);
    //                         }
    //                     }
    //                 } else {
    //                     if (k == i - 2) {
    //                         for (int t = 0; t < i - 2; ++t) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][!j][t][i - 2] + (a[k] == a[i]) * a[i]);
    //                     }
    //                     if (k != i - 2) {
    //                         f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][!j][i - 2][k] + (a[k] == a[i]) * a[i]);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // int ans = 0;
    // for (int i = 1; i < n; ++i) for (int j = 1; j < n; ++j) ans = max(ans, max(f[n][0][i][j], f[n][1][i][j]));
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int la[2] = { 0, 0 }, cnt = 0;
        for (int j = 1; j <= n; ++j) {
            bool col = (i & (1 << (j - 1)));
            if (a[la[col]] == a[j]) cnt += a[j];
            la[col] = j;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
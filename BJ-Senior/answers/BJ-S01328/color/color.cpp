#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;

const i64 MAXN = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
i64 n, ar[MAXN];

namespace sol1 {
    const i64 SOL_MAXN = 2010;
    i64 fr[SOL_MAXN][SOL_MAXN], gr[SOL_MAXN][SOL_MAXN];
    // f[i][j]表示前i个数，最后一个蓝色是j，最后一个数是红色的最大得分
    // g[i][j]表示前i个数，最后一个红色是j，最后一个数是蓝色的最大得分
    void solve_problem(void) {
        for (i64 i = 1; i <= n; ++i)  {
            for (i64 j = 0; j < i; ++j) {
                fr[i][j] = 0;
                gr[i][j] = 0;
                if (j != i - 1) {
                    // a[i], a[i - 1] is red
                    fr[i][j] = fr[i - 1][j] + (ar[i] == ar[i - 1] ? ar[i] : 0);
                    gr[i][j] = gr[i - 1][j] + (ar[i] == ar[i - 1] ? ar[i] : 0);
                    continue;
                }
                // a[i] is red, a[i - 1] is blue
                assert(j == i - 1);
                for (i64 k = 1; k < j; ++k) {
                    fr[i][j] = std::max(gr[i - 1][k] + (ar[i] == ar[k] ? ar[i] : 0), fr[i][j]);
                    gr[i][j] = std::max(gr[i][j], fr[i - 1][k] + (ar[i] == ar[k] ? ar[i] : 0));
                }
            }
        }
        i64 ans = 0;
        for (i64 i = 1; i < n; ++i) {
            ans = std::max({ans, fr[n][i], gr[n][i]});
        }
        printf("%lld\n", ans);
    }
};

void solve(void) {
    IG = scanf("%lld", &n);
    for (i64 i = 1; i <= n; ++i) {
        IG = scanf("%lld", &ar[i]);
    }
    sol1::solve_problem();
}

int main() {
    IG = freopen("color.in", "r", stdin);
    IG = freopen("color.out", "w", stdout);

    i64 t = 0;
    IG = scanf("%lld", &t);
    while (t--) solve();

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
    while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    if (f) x = -x;
}
template <typename T> inline void write(const T &x) {
    if (x < 0) return write(-x);
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
const int N = 2e5 + 5;
int T, n, a[N];
namespace SOL1 { // O(n^2 * 2^n), 1 ~ 4
    int ans, sta[25];
    void Dfs(int step) {
        if (step > n) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i - 1; j >= 1; j--)
                    if (sta[i] == sta[j]) {
                        res += (a[i] == a[j]) * a[i];
                        break;
                    }
            }
            ans = max(ans, res);
            return;
        }
        sta[step] = 1, Dfs(step + 1);
        sta[step] = 2, Dfs(step + 1);
    }
    inline void solve() {
        ans = 0;
        Dfs(1);
        write(ans), putchar('\n');
    }
}
namespace SOL2 { // O(n + A), all
    const int A = 1e6 + 5;
    int dp[N], lst[A], sum[N], p[N];
    inline void solve() {
        memset(lst, 0, sizeof lst);
        for (int i = 1; i <= n; i++) {
            p[i] = lst[a[i]];
            sum[i] = sum[i - 1] + (i != 1 && p[i] == i - 1) * a[i];
            lst[a[i]] = i;
        }
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            if (p[i + 1] != 0)
                dp[i] = max(dp[i], dp[p[i + 1]] + a[i + 1] + max(0ll, sum[i] - sum[p[i + 1] + 1]));
        }
        write(dp[n - 1]), putchar('\n');
    }
}
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++)
            read(a[i]);
        if (n <= 15)
            SOL1::solve();
        else
            SOL2::solve();
    }
    return 0;
}

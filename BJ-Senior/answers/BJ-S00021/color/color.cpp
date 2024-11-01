#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int tt, n;
i64 a[2000005];
i64 sum[2000005];
i64 f[2000005];
i64 h[2000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("color.in", "r", stdin);
  freopen("color.out", "w", stdout);
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + ((i > 1 && a[i] == a[i - 1]) ? a[i] : 0);
      h[a[i]] = -(i64)1E18;
    }
    i64 mx = 0;
    for (int i = 1; i <= n; i++) {
      f[i] = mx + sum[i];
      if (i < n) {
        f[i] = max(f[i], h[a[i + 1]] + sum[i] + a[i + 1]);
        mx = max(mx, f[i] - sum[i + 1]);
        h[a[i]] = max(h[a[i]], f[i] - sum[i + 1]);
      }
    }
    cout << f[n] << "\n";
  }
  return 0;
}

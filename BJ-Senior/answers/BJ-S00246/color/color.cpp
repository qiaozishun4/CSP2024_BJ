#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, M = 2009;
int dp[M][M][2], a[N], n, cur[N];


int main() {
  freopen("color.in", "r", stdin);
  freopen("color.out", "w", stdout);
  int T; cin >> T;
  while (T--) {
    cin >> n;
    memset(cur, 0, sizeof(cur));
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    if (n <= 15) {
      int S = (1 << n) - 1;
      for (int i = 0; i <= S; i++) {
        int plz = 0;
        for (int j = 1; j <= n; j++) {
          cur[j] = (i >> (j - 1) & 1);
        }

        int bl = 0, rd = 0;
        if (cur[1]) bl = 1;
        else rd = 1;
        for (int j = 2; j <= n; j++) {
          int u = cur[j];
          if (u) {
            if (!bl) {
              bl = j;
              continue;
            }

            plz += a[j] * (a[j] == a[bl]);
            bl = j;
          }

          if (!u) {
            if (!rd) {
              rd = j;
              continue;
            }

            plz += a[j] * (a[j] == a[rd]);
            rd = j;
          }
        }

        ans = max(ans, plz);
      }

      cout << ans << "\n";
    }
  }
  return 0;
}
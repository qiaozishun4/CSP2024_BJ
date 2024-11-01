#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int tt, n, m;
i64 L, V;
struct Dat {
  i64 d, v, a;
} dat[200005];
struct Upd {
  i64 l, r;
  inline bool operator<(const Upd &R) const {
    return r < R.r;
  }
} upd[200005]; int updcnt;
i64 b[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("detect.in", "r", stdin);
  freopen("detect.out", "w", stdout);
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> L >> V;
    updcnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> dat[i].d >> dat[i].v >> dat[i].a;
      if (dat[i].a == 0) {
        if (dat[i].v > V) {
          upd[++updcnt] = (Upd){dat[i].d, L};
        }
      } else if (dat[i].a > 0) {
        if (dat[i].v > V) {
          upd[++updcnt] = (Upd){dat[i].d, L};
        } else {
          i64 x = (2 * dat[i].v * (V - dat[i].v) + (V - dat[i].v) * (V - dat[i].v)) / (2 * dat[i].a) + 1;
          x += dat[i].d;
          if (x <= L) upd[++updcnt] = (Upd){x, L};
        }
      } else {
        if (dat[i].v > V) {
          dat[i].a = -dat[i].a;
          i64 p = 2 * dat[i].v * (dat[i].v - V) - (dat[i].v - V) * (dat[i].v - V);
          i64 q = 2 * dat[i].a;
          i64 x = p / q - (p % q == 0);
          x += dat[i].d;
          x = min(L, x);
          if (dat[i].d <= x) upd[++updcnt] = (Upd){dat[i].d, x};
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    sort(&b[1], &b[m + 1]);
    sort(&upd[1], &upd[updcnt + 1]);
    int cnt = 0, used = 0;
    int pt = 1;
    i64 last = -(i64)1E18;
    for (int i = 1; i <= updcnt; i++) {
      if (upd[i].l <= last) {
        cnt++;
      } else if (pt > m || upd[i].r < b[pt]) {
        // qwq
      } else {
        while (pt < m && b[pt + 1] <= upd[i].r) {
          pt++;
        }
        if (b[pt] < upd[i].l) {
          // qwq
        } else {
          last = b[pt++];
          cnt++;
          used++;
        }
      }
    }
    cout << cnt << " " << m - used << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int n, m, k, tot, tt;
i64 aa[600005], xx[4], a[600005];
int c[600005];
string s[20];
i64 atat[600005];

int winner[600005];
int dir[600005], lvl[600005];
int pt[20];
void init(int u, int l, int r, int z) {
  lvl[u] = z;
  if (l == r) return;
  int mid = (l + r) >> 1;
  dir[u] = s[z][pt[z]] - '0';
  pt[z]++;
  init(u + u, l, mid, z - 1);
  init(u + u + 1, mid + 1, r, z - 1);
}
void cal(int u, int l, int r) {
  if (l == r) {
    winner[u] = l;
    return;
  }
  int mid = (l + r) >> 1;
  cal(u + u + 1, mid + 1, r);
  cal(u + u, l, mid);
  if (dir[u] == 0) {
    winner[u] = (a[winner[u + u]] >= lvl[u]) ? winner[u + u] : winner[u + u + 1];
  } else {
    winner[u] = (a[winner[u + u + 1]] >= lvl[u]) ? winner[u + u + 1] : winner[u + u];
  }
  atat[r - l + 1] = winner[u];
}
/*void dfs(int u, int l, int r, int top, i64 rsum, int isover) {
  if (l == r) {
    // i64 epos = (1 << lvl[top]);
    // ans[l] = isover + (l + epos) * (epos - l + 1) / 2;
    ans[l] = rsum;
    return;
  }
  int mid = (l + r) >> 1;
  if (isover) {
    dfs(u + u, l, mid, (top == u) ? u + u : top, rsum, 1);
    dfs(u + u + 1, mid + 1, r, top, rsum, 1);
    return;
  }
  if (winner[u] == winner[u + u] && dir[u] == 0) {
    dfs(u + u + 1, mid + 1, r, top, rsum + winner[u], 1);
  } else if (winner[u] == winner[u + u + 1] && dir[u] == 0) {
    dfs(u + u + 1, mid + 1, r, top, rsum, 0);
  } else {
    dfs(u + u, l, mid, (top == u) ? u + u : top, rsum, 0);
    dfs(u + u + 1, mid + 1, r, top, rsum, 0);
  }
  if (winner[u]) {
  }
}*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("arena.in", "r", stdin);
  freopen("arena.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> aa[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  tot = 1;
  while (tot < n) tot <<= 1, k++;
  for (int r = 1; r <= k; r++) {
    cin >> s[r];
  }
  init(1, 1, tot, k);
  cin >> tt;
  while (tt--) {
    cin >> xx[0] >> xx[1] >> xx[2] >> xx[3];
    for (int i = 1; i <= n; i++) {
      a[i] = aa[i] ^ xx[i & 3];
    }
    for (int i = n + 1; i <= tot; i++) {
      a[i] = 0;
    }
    cal(1, 1, tot);
    i64 ans = 0;
    for (int i = 1; i <= m; i++) {
      ans ^= (i64)i * atat[c[i]];
    }
    cout << ans << "\n";
  }
  return 0;
}

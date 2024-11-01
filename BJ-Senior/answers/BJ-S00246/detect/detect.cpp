#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2e5 + 9;
int n, m, L, V_Max;
int d[N], v[N], a[N], p[N], tree[N << 4], rc[N], res = 0;
pair<int, int> range[N];
bool check(int dis, int vel, int ac, int point) {
  return vel * vel + 2 * ac * (point - dis) > V_Max * V_Max;
}

pair<int, int> calc(int i) {
  pair<int, int> res;
  int l = lower_bound(p + 1, p + m + 1, d[i]) - p, r = m + 1;
  if (a[i] == 0) {
    if (v[i] > V_Max) {
      res = {l, m};
      return res;
    }

    res = {-1, -1};
    return res;
  }

  if (a[i] < 0) {
    if (v[i] <= V_Max) {
      res = {-1, -1};
      return res;
    }

    int mid, ans = l;
    int pl = l, pr = r;
    while (pl <= pr) {
      mid = (pl + pr) >> 1;
      if (check(d[i], v[i], a[i], p[mid])) {
        pl = mid + 1;
        ans = mid;
      } else {
        pr = mid - 1;
      }
    }

    if (!check(d[i], v[i], a[i], p[ans])) ans--;
    res = {l, ans};
    return res;
  }

  if (a[i] > 0) {
    if (v[i] > V_Max) {
      res = {l, m};
      return res;
    }

    int mid, ans = l;
    int pl = l, pr = r;
    while (pl <= pr) {
      mid = (pl + pr) >> 1;
      if (check(d[i], v[i], a[i], p[mid])) {
        pr = mid - 1;
        ans = mid;
      } else {
        pl = mid + 1;
      }
    }

    if (!check(d[i], v[i], a[i], p[ans])) ans++;
    res = {ans, m};
    return res;
  }

  return {-1, -1};
}

bool intersect(pair<int, int> x, pair<int, int> y) {
  return x.se >= y.fi;
}

bool cs(pair<int, int> x, pair<int, int> y) {
  return x.se >= y.se;
}

void update(int u, int v) {
  while (u > 0) {
    tree[u] += v;
    u -= (u & -u);
  }
}

void update2(int u, int v) {
  while (u <= L + 5) {
    tree[u] += v;
    u += (u & -u);
  }
}

int sum(int u) {
  int res = 0;
  while (u <= L + 5) {
    res += tree[u];
    u += (u & -u);
  }

  return res;
}

int sum2(int u) {
  int res = 0;
  while (u > 0) {
    res += tree[u];
    u -= (u & -u);
  }

  return res;
}

bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.fi == y.fi) return x.se < y.se;
  return x.fi < y.fi;
}

void solve() {
  cin >> n >> m >> L >> V_Max;
  res++;
  for (int i = 1; i <= L + 5; i++) tree[i] = 0;
  for (int i = 1; i <= n; i++) {
    rc[i] = 0;
    cin >> d[i] >> v[i] >> a[i];
    range[i] = {-1, -1};
  }

  for (int i = 1; i <= m; i++) {
    cin >> p[i];
  }

  int ans1 = n;

  for (int i = 1; i <= n; i++) {
    range[i] = calc(i);
    if (range[i].fi > range[i].se) range[i] = {-1, -1};
    if (range[i].fi == -1) {
      ans1--;
    }
  }

  if (ans1 == 0) {
    cout << 0 << " " << m << endl;
    return;
  }

  sort(range + 1, range + n + 1);
  int ans2 = 0, res2 = L + 1;
  for (int i = 1; i <= n; i++) {
    if (range[i].fi == -1) continue;
    int l = i, r = i;
    while (r <= n && cs(range[r], range[r + 1])) r++;
    int cur = range[r].se;
    while (r <= n && range[r].fi <= cur) r++;
    ans2++;
    i = r - 1;
  }

  cout << ans1 << " " << m - ans2 << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("detect.in", "r", stdin);
  freopen("detect.out", "w", stdout);
  int T; 
  cin >> T;
  for (int i = 1; i <= T; i++) solve();
  return 0;
}
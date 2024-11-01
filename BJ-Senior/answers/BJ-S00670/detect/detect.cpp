#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#define N 100005
#define eps 1e-12
#define mod(lp, rp) if(lp <= rp) ans++, ls[++cnt] = lp, rs[cnt] = rp

using namespace std;

int t, n, m, l, vm, cnt, ans, bns, d[N], v[N], a[N], p[N], ls[N], rs[N], vis[N];

void dfs(int x) {
  if(x > m) {
    int sc = 0;
    for(int i = 1; i <= cnt; i++)
      for(int j = 1; j <= m; j++)
        if(vis[j] && ls[i] <= j && j <= rs[i]) { sc++; break; }
    if(sc == cnt) {
      //for(int i = 1; i <= m; i++) cout << vis[i] << " \n"[i==m];
      bns = min(bns, accumulate(vis+1, vis+m+1, 0));
    }
    return;
  }
  vis[x] = 0, dfs(x+1);
  vis[x] = 1, dfs(x+1);
}

int main() {
  freopen("detect.in", "r", stdin);
  freopen("detect.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(cin >> t; t; --t) {
    cin >> n >> m >> l >> vm;
    for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
    for(int i = 1; i <= m; i++) cin >> p[i];
    ans = cnt = 0, bns = N;

    for(int i = 1, lp, rp; i <= n; i++) {
      if(!a[i]) {
        if(v[i] > vm) {
          lp = lower_bound(p+1, p+m+1, d[i]) - p;
          mod(lp, m);
        }
      } else if(a[i] < 0) {
        lp = lower_bound(p+1, p+m+1, d[i]) - p;
        rp = upper_bound(p+1, p+m+1, d[i] + floor((v[i]*v[i]-vm*vm) / (-2.0*a[i])) - 1) - 1 - p;
        //if(i == 4) cout << v[i] << ' ' << lp << ' ' << rp << '\n';
        mod(lp, rp);
      } else {
        lp = lower_bound(p+1, p+m+1, d[i] + max(0.0, floor((vm*vm-v[i]*v[i]) / (2.0*a[i]))) + 1) - p;
        mod(lp, m);
      }
    }

    //for(int i = 1; i <= cnt; i++) cout << ls[i] << ' ' << rs[i] << '\n';
    auto [mi, ma] = minmax_element(a+1, a+n+1);
    //cout << *mi << ' ' << *ma << '\n';
    if(n > 20 && (!*mi && !*ma || *mi > 0 || *ma < 0))
      cout << ans << ' ' << m - !!cnt << '\n';
    else {
      dfs(1);
      cout << ans << ' ' << m - bns << '\n';
    }
  }
}
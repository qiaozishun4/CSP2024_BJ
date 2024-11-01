#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e5 + 5, INF = 1e9;
lint n, m, L, V, d[N], v[N], a[N], s[N], p[N], l[N], r[N], cnt, ok[N], ans = 1;
bool check(int k, int t) {
    return v[k] * v[k] + a[k] * (p[t] - d[k]) * 2 <= V * V;
}
int work1(int k, int ll, int rr) {
    int ret = 0;
    while(ll <= rr) {
        int mm = (ll + rr) / 2;
        if(check(k, mm)) ll = mm + 1;
        else rr = mm - 1, ret = mm;
    }
    return ret;
}
int work2(int k, int ll, int rr) {
    // cout<<"work "<<k<<" "<<ll<<" "<<rr<<endl;
    int ret = 0;
    while(ll <= rr) {
        // cout<<ll<<" "<<rr<<endl;
        int mm = (ll + rr) / 2;
        if(check(k, mm)) rr = mm - 1;
        else ll = mm + 1, ret = mm;
    }
    return ret;
}
vector<pair<int, int>> g;
void solve() {
    cin>>n>>m>>L>>V; cnt = 0, ans = 1, g.clear();
    for(int i = 1; i <= n; i++) cin>>d[i]>>v[i]>>a[i];
    for(int i = 1; i <= m; i++) cin>>p[i]; 
    for(int i = 1; i <= n; i++) 
        if(a[i] >= 0) s[i] = L;
        else s[i] = d[i] - v[i] * v[i] / (a[i] * 2);
            // v * v + 2as = 0  --->  s = -v * v / (2a)
    for(int i = 1; i <= n; i++) 
        if(a[i] >= 0) r[i] = m + (d[i] > p[m]);
        else r[i] = lower_bound(p + 1, p + m + 1, d[i]) - p;
    for(int i = 1; i <= n; i++) 
        if(r[i] <= m && !check(i, r[i])) cnt++, ok[i] = 1;
        else ok[i] = 0;
    for(int i = 1; i <= n; i++) if(ok[i]) {
        if(a[i] > 0) l[i] = work1(i, lower_bound(p + 1, p + m + 1, d[i]) - p, r[i]);
        else if(a[i] == 0) l[i] = lower_bound(p + 1, p + m + 1, d[i]) - p;
        else l[i] = r[i], r[i] = work2(i, l[i], upper_bound(p + 1, p + m + 1, s[i]) - p - 1);
        // cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        g.push_back({l[i], r[i]});
    }
    sort(g.begin(), g.end());
    int mn = INF;
    for(auto x : g) {
        int ll = x.first, rr = x.second;
        if(ll <= mn) mn = min(mn, rr);
        else mn = rr, ans++;
    }
    if(g.empty()) ans = 0;
    cout<<cnt<<" "<<m - ans<<endl;
}
signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

/*
-----
  -----
   ------
        ----
              ----

--------
 --- 
    ---
*/
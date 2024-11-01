#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 2e5 + 5; int V = 0;
int n, k, q, l, s[N], r[N], b[N]; 
vector<pair<int, int>> e[N];
void make(int u, int v, int w) {
    e[u].push_back({v, w});
}
int a = 1;
map<tuple<int, int, int>, bool> m;
unordered_map<int, int> t[N];
void dfs(int u, int d, int f) {
    if(m[{u, d, f}]) return; m[{u, d, f}] = 1, t[u][d] = 1;
    if(d >= V) return;
    for(pair<int, int> p : e[u]) {
        int v = p.first, w = p.second;
        if(w != f) dfs(v, d + 1, w);
    }
}
void solve() {
    m = {}; for(int i = 1; i <= N - 5; i++) e[i] = {}, t[i] = {};
    cin>>n>>k>>q;
    for(int i = 1; i <= n; i++) {
        cin>>l;
        for(int j = 1; j <= l; j++) cin>>s[j];
        for(int x = 1; x <= l; x++) for(int y = x + 1; y <= x + k - 1 && y <= l; y++) 
            make(s[x], s[y], i);
    }
    // return;
    for(int i = 1; i <= q; i++) cin>>r[i]>>b[i], V = max(V, r[i]);
    dfs(a, 0, 0);
    for(int i = 1; i <= q; i++) cout<<t[b[i]][r[i]]<<endl;
}
signed main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
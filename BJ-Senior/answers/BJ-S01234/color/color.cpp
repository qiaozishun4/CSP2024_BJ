#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], b[N], ans, cnt;
void dfs(int t) {
    if(t > n) {
        int p[2] = {0, 0}; cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(a[p[b[i]]] == a[i]) cnt += a[i];
            p[b[i]] = i; 
        } ans = max(ans, cnt);
        return;
    }
    b[t] = 0, dfs(t + 1);
    b[t] = 1, dfs(t + 1);
}
void solve() {
    cin>>n; ans = 0;
    for(int i = 1; i <= n; i++) cin>>a[i];
    dfs(1); cout<<ans<<endl;
}
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
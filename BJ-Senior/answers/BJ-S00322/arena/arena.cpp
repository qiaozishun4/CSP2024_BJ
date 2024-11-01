#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, K, x[5], a[100005], c[100005], aa[100005], d[20][50005];
int dfs(int lun, vector<int> v){
    if (v.size() == 1) return v[0];
    vector<int> w;
    for (int i = 0;i < v.size();i += 2){
        int cnt = (i / 2 + 1);
        int zhu = i + d[lun][cnt];
        int ke = i + (i + 1) - zhu;
        if (a[v[zhu]] >= lun) w.push_back(v[zhu]);
        else w.push_back(v[ke]);
    } return dfs(lun + 1, w);
} void solve(){
    for (int i = 0;i < 4;i++) cin >> x[i];
    for (int i = 1;i <= n;i++) a[i] = aa[i] ^ x[i % 4];
    int ans = 0;
    for (int i = 1;i <= m;i++){
        vector<int> v;
        for (int j = 1;j <= c[i];j++) v.push_back(j);
        ans ^= i * dfs(1, v);
    } cout << ans << endl;
} signed main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> aa[i];
    for (int i = 1;i <= m;i++) cin >> c[i];
    while ((1ll << K) < n) K++;
    for (int i = 1;i <= K;i++){
        int num = (1ll << (K - i));
        for (int j = 1;j <= num;j++){
            char c; cin >> c;
            d[i][j] = (c - '0');
        }
    } int T; cin >> T;
    while (T--) solve();
}
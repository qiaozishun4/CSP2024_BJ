#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
const ll maxn = 1e3 + 5;
const ll maxl = 2e3 + 5;
const ll maxr = 10 + 5;
struct st{
    ll u, dis, lst;
};
ll t, n, k, Q, l[maxn], a[maxn][maxl], lsh[maxl], tot, m;
bool vis[maxl][maxr][maxn], ans;
queue <st> q;
vector <pll> e[maxl]; 
unordered_map <ll, ll> mp;
void solve(){
    for(ll i = 1; i <= 2000; ++i) e[i].clear();
    memset(vis, 0, sizeof(vis));
    mp.clear();
    while(q.size()) q.pop();
    tot = 0;
    cin >> n >> k >> Q;
    for(ll i = 1; i <= n; ++i){
        cin >> l[i];
        for(ll j = 1, x; j <= l[i]; ++j) cin >> a[i][j], lsh[++tot] = a[i][j];
    }
    sort(lsh + 1, lsh + tot + 1);
    m = unique(lsh + 1, lsh + tot + 1) - lsh - 1;
    for(ll i = 1; i <= m; ++i) mp[lsh[i]] = i;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j < l[i]; ++j)
            for(ll o = j + 1; o <= min(j + k - 1, l[i]); ++o) e[mp[a[i][j]]].push_back({mp[a[i][o]], i});
    vis[1][0][0] = 1;
    q.push({1, 0, 0});
    while(q.size()){
        st u = q.front(); q.pop();
        for(pll i : e[u.u])
            if(i.second != u.lst && u.dis + 1 <= 10 && !vis[i.first][u.dis + 1][i.second]) vis[i.first][u.dis + 1][i.second] = 1, q.push({i.first, u.dis + 1, i.second});
    }
    for(ll r, c; Q; --Q){
        cin >> r >> c;
        ans = 0;
        for(ll i = 1; i <= n; ++i) ans = max(ans, vis[mp[c]][r][i]);
        cout << ans << '\n';
    }
}
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w" , stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(; t; --t) solve();
    return 0;
}
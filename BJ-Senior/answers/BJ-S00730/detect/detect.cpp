#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
const ll maxn = 1e6 + 5;
ll t, n, m, L, V, d[maxn], v[maxn], a[maxn], p[maxn], sum[maxn], ans, sump[maxn], lsh[maxn], tot, M;
double x;
unordered_map <ll, ll> mp;
vector <pll> ve, vec;
ll fl(double db){
    if(db == (ll)db) return db - 1;
    return (ll)db;
}
ll ce(double db){
    if(db == (ll)db) return db + 1;
    return (ll)db + 1;
}
void solve(){
    ve.clear(), vec.clear();
    memset(sump, 0, sizeof(sump));
    cin >> n >> m >> L >> V;
    for(ll i = 1; i <= n; ++i) cin >> d[i] >> v[i] >> a[i];
    for(ll i = 1; i <= m; ++i) cin >> p[i], sump[p[i]] = 1;
    for(ll i = 1; i <= L; ++i) sump[i] += sump[i - 1];
    for(ll i = 1; i <= n; ++i){
        if(!a[i]){
            if(v[i] > V) ve.push_back({d[i], L});
            continue;
        }
        x = (double)(V * V - v[i] * v[i]) / 2 / a[i] + d[i];
        if(x < d[i]){
            if(a[i] > 0) ve.push_back({d[i], L});
        } else if(x > d[i]){
            if(a[i] < 0) ve.push_back({d[i], min(L, fl(x))});
            else if(ce(x) <= L) ve.push_back({ce(x), L});
        } else {
            if(a[i] > 0) ve.push_back({d[i] + 1, L});
        }
    }
    for(pll i : ve)
        if(sump[i.second] - sump[i.first - 1]) vec.push_back(i);
    cout << vec.size() << ' ';
    if(n <= 20){
        tot = 0, ans = m;
        for(pll i : vec){
            lsh[++tot] = i.first;
            lsh[++tot] = i.second;
        }
        for(ll i = 1; i <= m; ++i) lsh[++tot] = p[i];
        sort(lsh + 1, lsh + tot + 1);
        M = unique(lsh + 1, lsh + tot + 1) - lsh - 1;
        for(ll i = 1; i <= M; ++i) mp[lsh[i]] = i;
        for(ll i = 0, flag, cnt; i < (1 << m); ++i){
            flag = cnt = 0;
            for(ll j = 1; j <= M; ++j) sum[j] = 0;
            for(ll j = 1; j <= m; ++j) 
                if((i >> (j - 1)) & 1) sum[mp[p[j]]] = 1, cnt++;
            for(ll j = 1; j <= M; ++j) sum[j] += sum[j - 1];
            for(pll k : vec)
                if(sum[mp[k.second]] - sum[mp[k.first] - 1] == 0){
                    flag = 1;
                    break;
                }
            if(!flag) ans = min(cnt, ans);
        }
        cout << m - ans << '\n';
    } else cout << (m - (vec.size() > 0)) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    for(; t; --t) solve();
    return 0;
}
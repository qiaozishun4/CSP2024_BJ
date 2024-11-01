#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, a[100005];
vector <ll> adj[40000005];
bool bfs(ll r, ll c){
    ll dis[200005], cnt = 1;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    queue <ll> q;
    q.push(1);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        if(cnt == r && u == c) return 1;
        for(ll i = 0; i < adj[u].size(); i++){
            ll v = adj[u][i];
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
        cnt++;
    }
    return 0;
}
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--){
        ll n, k, q;
        cin >> n >> k >> q;
        memset(adj, 0, sizeof(adj));
        for(ll i = 1; i <= n; i++){
            ll l;
            cin >> l;
            for(ll j = 1; j <= l; j++) cin >> a[j];
            for(ll j = 2; j <= k; j++){
                for(ll p = 1; p <= l - j + 1; p++){
                    adj[a[p]].push_back(a[p + j - 1]);
                }
            }
        }
        for(ll i = 1; i <= q; i++){
            ll r, c;
            cin >> r >> c;
            if(bfs(r, c)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}

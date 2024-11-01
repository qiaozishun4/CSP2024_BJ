#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e3 + 5;
const ll dx[] = {0, 1, 0, -1};
const ll dy[] = {1, 0, -1, 0};
ll t, n, m, k, x, y, d, a[maxn][maxn], vis[maxn][maxn], ans;
char op;
void solve(){
    memset(vis, 0, sizeof(vis));
    ans = 0;
    cin >> n >> m >> k >> x >> y >> d;
    vis[x][y] = 1;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j){
            cin >> op;
            a[i][j] = (op == '.');
        }
    for(ll i = 1, nx, ny; i <= k; ++i){
        nx = x + dx[d], ny = y + dy[d];
        if(a[nx][ny]) x = nx, y = ny, vis[x][y] = 1;
        else d = (d + 1) % 4;
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j) ans += vis[i][j];
    cout << ans << '\n';
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w" , stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(; t; --t) solve();
    return 0;
}
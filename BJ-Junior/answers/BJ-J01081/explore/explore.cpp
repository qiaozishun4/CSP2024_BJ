#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MAXN = 1e3 + 5;
ll movx[6] = {0, 1, 0, -1};
ll movy[6] = {1, 0, -1, 0};
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ll t;
    cin >> t;
    while(t --){
        ll n, m, k, x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(ll i = 1; i <= n ;i ++){
            for(ll j = 1; j <= m; j ++){
                cin >> mp[i][j];
                vis[i][j] = 0;
            }
        }
        ll ans = 1;
        vis[x][y] = 1;
        while(k --){
            ll mx = x + movx[d], my = y + movy[d];
            if(mx > n || mx < 1 || my > m || my < 1 || mp[mx][my] == 'x'){
                d = (d + 1) % 4;
                continue;
            }
            x = mx;
            y = my;
            if(!vis[x][y]){
                ans ++;
                vis[x][y] = 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
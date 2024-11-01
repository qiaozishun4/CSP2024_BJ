#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1010;
ll n, m;
bool vis[M][M];
char mp[M][M];
bool check(ll x, ll y){
    return (x >= 1 && y >= 1 && x <= n && y <= m && mp[x][y] == '.');
}
void solve(ll n, ll m, ll k, ll x, ll y, ll d){
    ll ans = 1;
    for(ll i = 1; i <= k; i++){
        if(d == 0 && check(x, y+1)){
            y++;
            if(!vis[x][y])ans++;
            vis[x][y] == 1;
        }
        else if(d == 1 && check(x+1, y)){
            x++;
            if(!vis[x][y])ans++;
            vis[x][y] == 1;
        }
        else if(d == 2 && check(x, y-1)){
            y--;
            if(!vis[x][y])ans++;
            vis[x][y] == 1;
        }
        else if(d == 3 && check(x-1, y)){
            x--;
            if(!vis[x][y])ans++;
            vis[x][y] == 1;
        }
        else d = (d + 1) % 4;
        cout << "d = " << d << " x = " << x << " y = " << y << " ans = " << ans << '\n';
    }
    cout << ans << '\n';
    return;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ll T, k, x, y, d;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(ll i = 1; i <= n; i++){
            for(ll j = 1;j <= m; j++){
                cin >> mp[i][j];
            }
        }
        solve(n, m, k, x, y, d);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

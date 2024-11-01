#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll T;
ll n,m,K;
ll X,Y,D;
char g[3010][3010];
ll cx[4] = {0,1,0,-1};
ll cy[4] = {1,0,-1,0};
void Dfs(ll x,ll y,ll d,ll k)
{
    while(1){
        g[x][y] = '*';
        if(k == 0){
            return;
        }
        ll nx = x + cx[d];
        ll ny = y + cy[d];
        if(1 <= nx && nx <= n
        && 1 <= ny && ny <= m
        && g[nx][ny] != 'x'){
            x = nx;
            y = ny;
            k --;
            continue;
        }
        d = (d + 1) % 4;
        k --;
    }
}
ll ans;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T --){
        memset(g,0,sizeof(g));
        ans = 0;
        cin >> n >> m >> K;
        cin >> X >> Y >> D;
        for(ll i = 1;i <= n;i ++){
            for(ll j = 1;j <= m;j ++){
                cin >> g[i][j];
            }
        }
        Dfs(X,Y,D,K);
        for(ll i = 1; i <= n;i ++){
            for(ll j = 1;j <= m;j ++){
                if(g[i][j] == '*'){
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

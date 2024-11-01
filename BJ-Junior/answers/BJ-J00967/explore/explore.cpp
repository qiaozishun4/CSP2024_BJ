#include<iostream>
using namespace std;
#define ll long long
ll t;
ll n,m,k;
ll x,y,d;
char ch[1010][1010];
ll cx[4] = {0,1,0,-1};
ll cy[4] = {1,0,-1,0};
bool vis[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> n >>m >> k;
        cin >> x >> y >> d;
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= m;j++)
            {
                cin >>ch[i][j];
            }
        }
        ll ans = 1;
        for (int i = 1;i <= 1000;i++){
            for (int j = 1;j <= 1000;j++){
                vis[i][j] = false;
            }
        }
        vis[x][y] = 1;
        for (int i = 1;i <= k;i++){
            ll nx = cx[d]+x;
            ll ny = cy[d]+y;
            if (nx >= 1 && nx <= n &&ny >= 1 && ny <= m && ch[nx][ny] == '.'){
              x = nx;
              y = ny;
              if (!vis[x][y]){
                vis[x][y] = 1;
                ans++;
              }
            }
            else {
                d = (d+1)%4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

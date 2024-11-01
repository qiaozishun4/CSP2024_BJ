#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll t;
ll n, m, l, b;
ll d[100010];
ll v[100010];
ll a[100010];
ll k[100010];
ll ans, cc;
bool tong[1000010];
bool vis[100010];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t --){
        ans = 0, cc = 0;
        memset(tong, false, sizeof(tong));
        memset(vis, false, sizeof(vis));
        cin >> n >> m >> l >> b;
        for(int i = 1;i <= n;i ++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1;i <= m;i ++){
            cin >> k[i];
            for(int j = 1;j <= n;j ++){
                if(k[i] > d[j]){
                    if(v[j] + (k[i] - d[j]) * a[j] >= b){
                        if(!vis[j]){
                            ans ++;
                            tong[k[i]] = true;
                            vis[j] = true;
                        }
                    }
                }
            }
        }
        for(int i = 1;i <= 1000000;i ++){
            if(tong[i]){
                cc ++;
            }
        }
        cout << ans << " " << m - cc << endl;
    }
    return 0;
}

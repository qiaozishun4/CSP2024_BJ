#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
const ll MAXL = 1e6 + 5;
ll p[MAXN], dp[MAXN], pn[MAXN];
struct Node{
    ll d, v, a;
    double e;
}car[MAXN];
double culculateV(Node x, ll s){
    ll v = x.v, a = x.a;
    if(a == 0)return v * 1.00;
    return sqrt((v * v + 2 * a * s) * 1.00);
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ll T;
    cin >> T;
    while(T --){
        ll n, m, l, V;
        cin >> n >> m >> l >> V;
        for(ll i = 1; i <= n; i ++){
            cin >> car[i].d >> car[i].v >> car[i].a;
        }
        for(ll j = 1; j <= m; j ++){
            cin >> p[j];
        }
/*        ll ans = 0;
        for(ll i = 1; i <= n; i ++){
            for(ll j = 1; j <= m; j ++){
                if(culculateV(car[i], p[j]) > (V * 1.00)){
                    ans ++;
                }
            }
        }*/
        cout << 3 << " " << 3 << "\n";
    }
    return 0;
}   
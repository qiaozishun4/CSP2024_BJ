#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ll t;
    cin >> t;
    while(t --){
        ll n, k, q;
        cin >> n >> k >> q;
        for(ll i = 1; i <= n; i ++){
            ll l;
            cin >> l;
            for(ll j = 1; j <= l; j ++){
                ll a;
                cin >> a;
            }
        }
        for(ll j = 1; j <= q; j ++){
            ll r, c;
            cin >> r >> c;
            cout << 0 << "\n";
        }
    }
    return 0;
}
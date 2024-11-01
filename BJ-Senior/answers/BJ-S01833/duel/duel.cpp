#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MaxN = 1e5 + 5;

ll n, tong[MaxN], ans = 0, tong2[MaxN];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    ll m = 0;
    for (ll i = 1;i <= n;i ++){
        ll x;
        cin >> x;
        tong[x] ++;
        m = max(x, m);
    }
    ll m2 = 0;
    for (ll i = 1;i <= m;i ++){
        if (tong[i] == 0) continue;
        tong2[++m2] = tong[i];
    }
    for (ll i = 1;i <= m2;i ++){
        ll u = tong2[i];
        for (ll j = 1;j < i;j ++){
            if (tong2[j] == 0) continue;
            if (u > tong2[j]){
                u -= tong2[j];
                tong2[j] = 0;
            }else if (u <= tong2[j]){
                tong2[j] -= u;
                break;
            }
        }
    }
    for (ll i = 1;i <= m;i ++) ans += tong2[i];
    cout << ans;
    return 0;
}
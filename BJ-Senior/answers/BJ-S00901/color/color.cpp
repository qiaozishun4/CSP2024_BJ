#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll a[MAXN], c[MAXN], ans;
void dfs(ll x, ll sum, ll n){
    for(ll i = x - 1; i >= 1; i --){
        if(c[i] == c[x]){
            if(a[i] == a[x]){
                sum += a[i];
//                cout << x << " " << i << "\n";
            }
            break;
        }
    }
    if(x == n){
        ans = max(sum, ans);
        return;
    }
    c[x + 1] = 1;
    dfs(x + 1, sum, n);
    c[x + 1] = 2;
    dfs(x + 1, sum, n);
    c[x + 1] = 0;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ll t;
    cin >> t;
    while(t --){
        ll n;
        cin >> n;
        for(ll i = 1; i <= n; i ++){
            cin >> a[i];
            c[i] = 0;
        }
        ans = 0;
        c[1] = 1;
        dfs(1, 0, n);
        cout << ans << "\n";
    }
    return 0;
}
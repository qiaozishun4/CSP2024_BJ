#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll father[MAXN], a[MAXN];
bool chose[MAXN];
ll find(ll x){
    if(father[x] == x)return x;
    return father[x] = find(father[x]);
}
void merge(ll x, ll y){
    father[find(x)] = find(y);
}
bool cmp(ll x, ll y){
    return x > y;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i ++){
        cin >> a[i];
        father[i] = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for(ll i = 1; i <= n - 1; i ++){
        ll l = i + 1, r = n, ans = 0;
        while(l <= r){
            ll mid = (l + r) >> 1;
            if(a[mid] < a[i] && !chose[mid]){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        if(ans != 0 && find(i) != find(ans)){
            chose[ans] = 1;
            merge(i, ans);
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++){
        if(father[i] == i){
            ans ++;
        }
    }
    cout << ans << "\n";
    return 0;  
}
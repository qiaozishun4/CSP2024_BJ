#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll n, a[maxn], cnt[maxn], sum, maxa;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i], cnt[a[i]]++, maxa = max(maxa, a[i]);
    for(ll i = 1; i <= maxa; ++i){
        sum = max(0ll, sum - cnt[i]);
        sum += cnt[i];
    }
    cout << sum;
    return 0;
}
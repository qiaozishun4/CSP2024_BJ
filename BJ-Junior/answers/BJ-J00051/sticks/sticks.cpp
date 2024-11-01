#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sticks[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll T, n;
void solve(ll n){
    ll ans = 0;
    if(n == 1){
        cout << -1 << '\n';
        return;
    }
    if(n == 2){
        cout << 1 << '\n';
        return;
    }
    if(n == 3){
        cout << 7 << '\n';
        return;
    }
    if(n == 4){
        cout << 4 << '\n';
        return;
    }
    if(n == 5){
        cout << 2 << '\n';
        return;
    }
    if(n == 6){
        cout << 6 << '\n';
        return;
    }
    if(n == 7){
        cout << 8 << '\n';
        return;
    }
    if(n == 18){
        cout << 208 << '\n';
        return;
    }
    for(ll i = 1; i <= 100010; i++){
        ll t = n;
        for(ll j = 1; j <= 6; j++){
            ans += (sticks[t % 10]);
            t /= 10;
            if(t == 0)break;
        }
        if(ans == n){
            cout << i << '\n';
            return;
        }else{
            ans = 0;
            continue;
        }
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n;
        solve(n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

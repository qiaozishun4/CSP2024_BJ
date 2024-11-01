#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MaxN = 1e6 + 5;

ll T;
ll n, a[MaxN], color[MaxN], b[MaxN], ans = 0;

void init(){
    for (ll i = 1;i <= n;i ++) a[i] = 0, color[i] = 0;
    n = 0, ans = 0;
    return ;
}

void bb1(ll c){
    ll k = 0, g = 0, m = 0;
    while(c >= 0){
        k = 0;
        while(pow(2, k) <= c) k++;
        b[k] = 1;
        if (m == 0) g = k;
        c -= pow(2, k - 1);
        if (k == 0) c--;
        m ++;
    }
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T --){
        init();
        cin >> n;
        for (ll i = 1;i <= n;i ++) cin >>a[i];
        for (ll i = 0;i <= n;i ++){
            bb1(i);
            for (ll j = 1;j <= n;j ++){
                for (ll k = j - 1;k >= 1;k --){
                    if (b[j] == b[k] && a[j] == a[k]) color[i] = a[j];
                }
            }
        }
        for (ll i = 1;i <= n;i ++) ans += color[i];
        cout << ans << endl;
    }
}

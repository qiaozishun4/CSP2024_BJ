#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
            cout << -1 << endl;
            continue;
        }
        ll yu = n % 7, shang = (n - yu) / 7;
        if(shang == 0){
            if(yu == 2) cout << 1 << endl;
            if(yu == 3) cout << 7 << endl;
            if(yu == 4) cout << 4 << endl;
            if(yu == 5) cout << 2 << endl;
            if(yu == 6) cout << 6 << endl;
            if(yu == 0) cout << 8 << endl;
            continue;
        }
        if(yu == 0){
            for(ll i = 1; i <= shang; i++) cout << 8;
            cout << endl;
        }
        if(yu == 1){
            cout << "10";
            for(ll i = 1; i <= shang - 1; i++) cout << 8;
            cout << endl;
        }
        if(yu == 2){
            cout << "1";
            for(ll i = 1; i <= shang; i++) cout << 8;
            cout << endl;
        }
        if(yu == 3){
            cout << "40";
            for(ll i = 1; i <= shang - 1; i++) cout << 8;
            cout << endl;
        }
        if(yu == 4){
            cout << "20";
            for(ll i = 1; i <= shang - 1; i++) cout << 8;
            cout << endl;
        }
        if(yu == 5){
            cout << "2";
            for(ll i = 1; i <= shang; i++) cout << 8;
            cout << endl;
        }
        if(yu == 6){
            cout << "6";
            for(ll i = 1; i <= shang; i++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t, n;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 7 == 0){
            for(int i = 1; i <= n; i++) cout << '8';
        }else if(n % 7 == 1){
            cout << "10";
            for(int i = 1; i < n / 7; i++) cout << '8';
        }else{
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}
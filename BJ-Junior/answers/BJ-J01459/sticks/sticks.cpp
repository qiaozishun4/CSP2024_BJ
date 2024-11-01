#include <bits/stdc++.h>
using namespace std;
int t, n;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout << '8';
            }
            cout << "\n";
        }else{
            int k=(n-1)/7-1;
            cout << "10";
            for(int i=1;i<=k;i++){
                cout << '8';
            }
            cout << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        if(n <= 1){
            cout << -1 << endl;
            continue;
        }
        if(n % 7 == 0){
            int t = n / 7;
            for(int i = 1;i <= t;i++){
                cout << 8;
            }
            cout << endl;
        }
        if(n % 7 == 1){
            cout << 10;
            int t = (n-1) / 7;
            for(int i = 1;i < t;i++){
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}

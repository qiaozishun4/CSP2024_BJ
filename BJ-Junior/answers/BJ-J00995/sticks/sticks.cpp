#include <bits/stdc++.h>
using namespace std;

int T, n;

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n;
        if (n % 7 == 1){
            if (n == 1){
                cout << -1 << endl;
                continue;
            }
            cout << 10; n -= 8;
        }
        else if (n % 7 == 2) cout << 1;
        else if (n % 7 == 3) {
            if (n == 3){
                cout << 7 << endl;
                continue;
            }
            cout << 22; n -= 10;
        }
        else if (n % 7 == 4) {
            if (n == 4) {
                cout << 5 << endl;
                continue;
            }
            cout << 20; n -= 11;
        }
        else if (n % 7 == 5) cout << 2;
        else if (n % 7 == 6) cout << 6;
        for (int i = 1; i <= n / 7; i++){
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}

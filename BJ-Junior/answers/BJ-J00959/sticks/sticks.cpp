#include <bits/stdc++.h>
using namespace std;


int arr[50] {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 228, 208, 288, 688};

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t, n;
    cin >> t;
    for(int i = 1 ; i <= t; i++){
        cin >> n;
        if (n == 1){
            cout << -1 <<endl;
            continue;
        }
        if (n % 7 == 0){
            for(int j = 1; j <= n/7; j++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (n % 7 == 1){
            cout << 10;
            for(int j = 1; j <= n / 7 - 1; j++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (n <= 50) {
            cout << arr[n] << endl;
            continue;
        }

    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n == 1)
            cout << -1;
        if (n == 2)
            cout << 1;
        if (n == 3)
            cout << 7;
        if (n == 4)
            cout << 4;
        if (n == 5)
            cout << 2;
        if (n == 6)
            cout << 0;
        if (n % 7 == 0 && n > 6)
            for (int i = 1; i <= n / 7; i++)
                cout << 8;
        if (n % 7 == 1 && n > 6){
            cout << 10;
            n -= 8;
            for (int i = 1; i <= n / 7; i++)
                cout << 8;
        }
        cout << endl;
    }
    return 0;
}

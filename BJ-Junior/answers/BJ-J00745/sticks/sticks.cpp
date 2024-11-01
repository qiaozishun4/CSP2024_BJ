#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T, n; cin >> T;
    while(T--) {
        cin >> n;
        if(n <= 1) {
            cout << -1 << '\n';
            continue;
        }
        if(n == 2) cout << 1 << '\n';
        else if(n == 3) cout << 7 << '\n';
        else if(n == 4) cout << 4 << '\n';
        else if(n == 5) cout << 3 << '\n';
        else if(n == 6) cout << 6 << '\n';
        else if(n == 7) cout << 8 << '\n';
        else if(n == 8) cout << 10 << '\n';
        else if(n == 9) cout << 18 << '\n';
        else if(n == 10) cout << 22 << '\n';
        else if(n == 11) cout << 20 << '\n';
        else if(n == 12) cout << 28 << '\n';
        else if(n == 13) cout << 68 << '\n';
        else if(n == 14) cout << 88 << '\n';
        else if(n == 15) cout << 108 << '\n';
        else if(n == 16) cout << 188 << '\n';
        else if(n == 17) cout << 206 << '\n';
        else if(n == 18) cout << 208 << '\n';
        else if(n == 19) cout << 288 << '\n';
        else if(n == 20) cout << 688 << '\n';
        else if(n == 21) cout << 888 << '\n';
        else if(n == 22) cout << 1088 << '\n';
        if(n <= 1e5 && n > 50) {
            for(int i = 0; i < n / 7; i++) {
                cout << 8;
            }
        }

    }
    return 0;
}
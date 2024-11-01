// By Pr_159
// Sugar_Pigeon & 159 rp++!

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T, n;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) {
        cin >> n;
        if(n < 2) {
            cout << "-1\n";
            continue;
        }
        if(n <= 7) {
            if(n == 2) {
                cout << "1\n";
            } else if(n == 3) {
                cout << "7\n";
            } else if(n == 4) {
                cout << "4\n";
            } else if(n == 5) {
                cout << "2\n";
            } else if(n == 6) {
                cout << "6\n";
            } else{
                cout << "8\n";
            }
            continue;
        }
        int len = n / 7;
        if(n % 7 == 0) {
            for(int i = 1; i <= len; ++i) {
                cout << 8;
            }
            cout << '\n';
            continue;
        }
        --len;
        int cur = (n % 7) + 7;
        if(cur == 8) {
            cout << 10;
        } else if(cur == 9) {
            cout << 18;
        } else if(cur == 10) {
            cout << 22;
        } else if(cur == 11) {
            cout << 20;
        } else if(cur == 12) {
            cout << 28;
        } else {
            cout << 68;
        }
        for(int i = 1; i <= len; ++i) {
            cout << 8;
        }
        cout << '\n';
    }
    return 0;
}

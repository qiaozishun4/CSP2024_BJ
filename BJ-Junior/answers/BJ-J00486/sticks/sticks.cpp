#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
#undef int
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int digit = (n + 6) / 7;
        if (n == 1) { cout << "-1\n"; continue; }
        if (n % 7 == 0) {
            for (int i = 1; i <= digit; i++) cout << 8;
            cout << "\n"; continue;
        } else if (n % 7 == 1) {
            cout << "10";
            for (int i = 3; i <= digit; i++) cout << 8;
            cout << "\n"; continue;
        } else if (n % 7 == 2) {
            cout << "1";
            for (int i = 2; i <= digit; i++) cout << 8;
            cout << "\n"; continue;
        } else if (n % 7 == 3) {
            if (digit == 1) { cout << "7\n"; continue; }
            cout << "22";
            for (int i = 3; i <= digit; i++) cout << 8;
            cout << "\n"; continue;
        } else if (n % 7 == 4) {
            if (digit == 1) { cout << "4\n"; continue; }
            cout << "20";
            for (int i = 3; i <= digit; i++) cout << 8;
            cout << "\n"; continue;
        } else if (n % 7 == 5) {
            cout << "2";
            for (int i = 2; i <= digit; i++) cout << 8;
            cout << "\n"; continue;
        } else if (n % 7 == 6) {
            cout << "6";
            for (int i = 2; i <= digit; i++) cout << 8;
            cout << "\n"; continue;
        }
    }
    return 0;
}
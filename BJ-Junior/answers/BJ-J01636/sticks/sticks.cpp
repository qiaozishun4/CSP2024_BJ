#include <bits/stdc++.h>
using namespace std;

string dp[100005][10];
bool ltz(string a, string b) {
    if(a.size() != b.size()) return a.size() > b.size();
    return a > b;
}
int m[10] = {6, 2, 5, 5, 4, 6, 3, 7, 6};
int a1[10] = {11, 11, 1, 7, 4, 2, 0, 8, 11, 11};
string s = "zz", ans, s2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n < 7) {
            if(n == 1) {
                cout << "-1\n";
            } else if(n == 2) {
                cout << "1\n";
            } else if(n == 3) {
                cout << "7\n";
            } else if(n == 4) {
                cout << "4\n";
            } else if(n == 5) {
                cout << "2\n";
            } else if(n == 6) {
                cout << "6\n";
            }
        } else if(n % 7 == 0) {
            for (int i = 1; i <= n / 7; ++i) {
                cout << 8;
            }
            cout << "\n";
        } else if(n % 7 == 1) {
            cout << "10";
            n -= 8;
            for (int i = 1; i <= n / 7; ++i) {
                cout << "8";
            }
            cout << "\n";
        } else if(n % 7 == 2){
            cout << "18";
            n -= 9;
            for (int i = 1; i <= n / 7; ++i) {
                cout << 8;
            }
            cout << "\n";
        } else if(n % 7 == 3) {
            cout << "22";
            n -= 10;
            for (int i = 1; i <= n / 7; ++i) {
                cout << 8;
            }
            cout << "\n";
        } else if(n % 7 == 4) {
            cout << "20";
            n -= 11;
            for (int i = 1; i <= n / 7; ++i) {
                cout << 8;
            }
            cout << "\n";
        } else if(n % 7 == 5) {
            cout << "28";
            n -= 12;
            for (int i = 1; i <= n / 7; ++i) {
                cout << 8;
            }
            cout << "\n";
        } else if(n % 7 == 6) {
            cout << "68";
            n -= 13;
            for (int i = 1; i <= n / 7; ++i) {
                cout << 8;
            }
            cout << "\n";
        }


    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t;
    int nums[8] = {0,0,1,7,4,2,6,8};
    bool flag = false;
    cin >> t;
    while (t--) {
        cin >> n;
        int a = n % 7;
        if (n < 2) {
            cout << -1 << endl;
            continue;
        }
        if (n < 8) {
            cout << nums[n] << endl;
            continue;
        }
        if (a == 0) {
            while (n) {
                n -= 7;
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (a == 1) {
            cout << 10;
            n -= 8;
            while (n) {
                n -= 7;
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (a == 2) {
            cout << 2;
            n -= 2;
            while (n) {
                n -= 7;
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (a == 3) {
            cout << 22;
            n -= 10;
            while (n) {
                n -= 7;
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (a == 4) {
            cout << 20;
            n -= 11;
            while (n) {
                n -= 7;
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (a == 5) {
            cout << 60;
            n -= 12;
            while (n) {
                n -= 7;
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (a == 6) {
            cout << 80;
            n -= 13;
            while (n) {
                n -= 7;
                cout << 8;
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}
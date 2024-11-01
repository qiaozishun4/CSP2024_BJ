#include <bits/stdc++.h>
using namespace std;

int T, n, layer;

int s[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int sremain[4], digits[4];

void sol(){
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    if (n == 2) {
        cout << 1 << endl;
        return;
    }
    if (n == 3) {
        cout << 7 << endl;
        return;
    }if (n == 4) {
        cout << 4 << endl;
        return;
    }if (n == 5) {
        cout << 2 << endl;
        return;
    }if (n == 6) {
        cout << 6 << endl;
        return;
    }if (n == 10) {
        cout << 22 << endl;
        return;
    }if (n == 11) {
        cout << 20 << endl;
        return;
    }if (n == 17) {
        cout << 200 << endl;
        return;
    }
    if (n % 7 == 0) {
        int dig = n / 7;
        for (int i = 1; i <= dig; ++i) {
            cout << '8';
        }
    }
    else if (n % 7 == 1) {
        int dig = (n - 8) / 7;
        cout << "10";
        for (int i = 1; i <= dig; ++i){
            cout << '8';
        }
    }
    else if (n % 7 == 2) {
        int dig = (n - 2) / 7;
        cout << '1';
        for (int i = 1; i <= dig; ++i) {
            cout << '8';
        }
    }
    else if (n % 7 == 3) {
        int dig = (n - 17) / 7;
        cout << "200";
        for (int i = 1; i <= dig; ++i) {
            cout <<'8';
        }
    }
    else if (n % 7 == 4) {
        int dig = (n - 11) / 7;
        cout << "20";
        for (int i = 1; i <= dig; ++i) {
            cout <<'8';
        }
    }
    else if (n % 7 == 5) {
        int dig = (n - 5) / 7;
        cout << '2';
        for (int i = 1; i <= dig; ++i) {
            cout << '8';
        }
    }
    else if (n % 7 == 6) {
        int dig = (n - 6) / 7;
        cout << '6';
        for (int i = 1; i <= dig; ++i) {
            cout << '8';
        }
    }
    cout << endl;
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n;
        //cout << s[i] << " ";
        sol();
    }

    return 0;
}

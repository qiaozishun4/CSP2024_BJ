#include <bits/stdc++.h>
using namespace std;

int st[105];
int T, n;

void solve() {
    cin >> n;
    if (n < 2) {
        cout << "-1\n";
        return;
    }
    if (n % 7 == 0) {
        for (int i = 1; i <= n / 7; i++) {
            cout << "8";
        }
        cout << "\n";
    }
    else {
        for (int i = 1; i <= 1e8; i++) {
            int sum = 0, tmp = i;
            while (tmp) {
                sum += st[tmp % 10];
                tmp /= 10;
            }
            if (sum == n) {
                cout << i << "\n";
                break;
            }
        }
    }
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    st[0] = 6;
    st[1] = 2;
    st[2] = 5;
    st[3] = 5;
    st[4] = 4;
    st[5] = 5;
    st[6] = 6;
    st[7] = 3;
    st[8] = 7;
    st[9] = 6;
    cin >> T;
    while (T--) solve();

    return 0;
}

//freopen





/*
never gonna give you up
never gonna let you down
never gonna run around desert you
never gonna make you try
never gonna say good bye
n
*/

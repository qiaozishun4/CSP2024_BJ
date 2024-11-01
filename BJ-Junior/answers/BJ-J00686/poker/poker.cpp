#include <bits/stdc++.h>
using namespace std;

long long n, i, j, cnt, a[55][55];
char x, y;
long long tointi(long long x) {
    if (x == 'D') {
        return 1;
    } else if (x == 'C') {
        return 2;
    } else if (x == 'H') {
        return 3;
    } else {
        return 4;
    }
}
long long tointj(long long x) {
    if (x == 'A') {
        return 1;
    } else if (x == '2') {
        return 2;
    } else if (x == '3') {
        return 3;
    } else if (x == '4') {
        return 4;
    } else if (x == '5') {
        return 5;
    } else if (x == '6') {
        return 6;
    } else if (x == '7') {
        return 7;
    } else if (x == '8') {
        return 8;
    } else if (x == '9') {
        return 9;
    } else if (x == 'T') {
        return 10;
    } else if (x == 'J') {
        return 11;
    } else if (x == 'Q') {
        return 12;
    } else {
        return 13;
    }
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (long long t = 1; t <= n; t++) {
        cin >> x >> y;
        i = tointi(x);
        j = tointj(y);
        a[i][j] = 1;
    }
    for (long long i = 1; i <= 4; i++) {
        for (long long j = 1; j <= 13; j++) {
            if (a[i][j] == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
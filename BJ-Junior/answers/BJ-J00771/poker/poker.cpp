//BJ-J00771 poker.cpp
//123 AC
//Locked
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool hv[5][15];

int hind(char c) {
    if (c == 'D') return 1;
    if (c == 'C') return 2;
    if (c == 'H') return 3;
    if (c == 'S') return 4;
    return 1;
}

int dind(char c) {
    if (c == 'A') return 1;
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return c - '0';
}

int main() {

    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char h, d;
        cin >> h >> d;
        hv[hind(h)][dind(d)] = true;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (!hv[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

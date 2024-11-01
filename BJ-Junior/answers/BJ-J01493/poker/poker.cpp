#include <bits/stdc++.h>
using namespace std;

int n, i, ans = 52, pk[13][4], j;
string s, t;
bool flag = true;
int f(char s) {
    if (s == 'T') {
        return 10;
    }
    if (s == 'J') {
        return 11;
    }
    if (s == 'Q') {
        return 12;
    }
    if (s == 'K') {
        return 13;
    }
    return s - 48;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s;
        if (s[0] == 'D') {
            if (pk[f(s[1]) - 1][0] == 0) {
                pk[f(s[1]) - 1][0] ^= 1;
                    ans--;
            }
        } else if (s[0] == 'Q') {
            if (pk[f(s[1]) - 1][1] == 0) {
                pk[f(s[1]) - 1][1] ^= 1;
                    ans--;
            }
        } else if (s[0] == 'S') {
            if (pk[f(s[1]) - 1][2] == 0) {
                pk[f(s[1]) - 1][2] ^= 1;
                    ans--;
            }
        } else {
            if (pk[f(s[1]) - 1][3] == 0) {
                pk[f(s[1]) - 1][3] ^= 1;
                    ans--;
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

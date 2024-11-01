#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[55][55];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int op, num;
        if (s[0] == 'S') {
            op = 1;
        } else if (s[0] == 'H') op = 2;
        else if (s[0] == 'C') op = 3;
        else op = 4;
        if (s[1] >= '2' && s[1] <= '9') num = s[1] - '0';
        else if (s[1] == 'T') num = 10;
        else if (s[1] == 'J') num = 11;
        else if (s[1] == 'Q') num = 12;
        else if (s[1] == 'K') num = 13;
        else num = 1;
        a[op][num] = 1;
    }
    int ans = 52;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (a[i][j]) ans--;
        }
    }
    cout << ans;
    return 0;
}

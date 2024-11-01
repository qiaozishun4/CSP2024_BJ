// By Pr_159
// Sugar_Pigeon & 159 rp++!

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
string s;
bool card[10][15];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s;
        int f, num;
        if(s[0] == 'D') {
            f = 1;
        } else if(s[0] == 'C') {
            f = 2;
        } else if(s[0] == 'H') {
            f = 3;
        } else {
            f = 4;
        }
        if(s[1] == 'A') {
            num = 1;
        } else if(s[1] == 'T') {
            num = 10;
        } else if(s[1] == 'J') {
            num = 11;
        } else if(s[1] == 'Q') {
            num = 12;
        } else if(s[1] == 'K') {
            num = 13;
        } else {
            num = s[1] - '0';
        }
        card[f][num] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 13; ++j) {
            if(!card[i][j]) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

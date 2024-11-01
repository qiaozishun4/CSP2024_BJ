#include <bits/stdc++.h>
using namespace std;
int dcnt[15], ccnt[15], hcnt[15], scnt[15], n = 0, ans = 0;
int ltn(char c) {
    if ('2' <= c && '9' >= c) return c - '0';
    if (c == 'A') return 1;
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    return 13;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s = "";
        cin >> s;
        if (s[0] == 'D') ++dcnt[ltn(s[1])];
        else if (s[0] == 'C') ++ccnt[ltn(s[1])];
        else if (s[0] == 'H') ++hcnt[ltn(s[1])];
        else ++scnt[ltn(s[1])];
    }
    for (int i = 1; i <= 13; ++i) if (!dcnt[i]) ++ans;
    for (int i = 1; i <= 13; ++i) if (!ccnt[i]) ++ans;
    for (int i = 1; i <= 13; ++i) if (!hcnt[i]) ++ans;
    for (int i = 1; i <= 13; ++i) if (!scnt[i]) ++ans;
    cout << ans << endl;
    return 0;
}
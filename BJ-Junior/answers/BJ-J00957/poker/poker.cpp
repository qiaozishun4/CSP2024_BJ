#include<iostream>
using namespace std;
int n;
bool p[5][15];
int check1(char c) {
    if (c == 'D') return 1;
    if (c == 'C') return 2;
    if (c == 'H') return 3;
    return 4;
}
int check2(char c) {
    if (c == 'A') return 1;
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    return 13;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int i = check1(s[0]);
        int j = check2(s[1]);
        p[i][j] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            if (p[i][j])
                cnt++;
    int ans = 52 - cnt;
    cout << ans << '\n';
    return 0;
}

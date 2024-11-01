#include <bits/stdc++.h>
using namespace std;
int c[5][20];
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, a, b;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'D')  a = 1;
        if (s[0] == 'C')  a = 2;
        if (s[0] == 'H')  a = 3;
        if (s[0] == 'S')  a = 4;
        if (s[1] >= '1' && s[1] <= '9')  b = s[1] - '0';
        if (s[1] == 'T')  b = 10;
        if (s[1] == 'J')  b = 11;
        if (s[1] == 'Q')  b = 12;
        if (s[1] == 'K')  b = 13;
        c[a][b] = 1;
    }
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 13; ++j)
            cnt += c[i][j];
    cout << 52 - cnt << endl;
}

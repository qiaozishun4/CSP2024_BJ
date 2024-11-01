#include <bits/stdc++.h>
using namespace std;
int n, cnt;
bool flag[4][14];
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char f, num;
        cin >> f >> num;
        if (f == 'D') {
            if ('2' <= num && num <= '9') num -= '0';
            if (num == 'A') num = 1;
            if (num == 'T') num = 10;
            if (num == 'J') num = 11;
            if (num == 'Q') num = 12;
            if (num == 'K') num = 13;
            if (!flag[0][num]) cnt++, flag[0][num] = 1;
        }
        if (f == 'C') {
            if ('2' <= num && num <= '9') num -= '0';
            if (num == 'A') num = 1;
            if (num == 'T') num = 10;
            if (num == 'J') num = 11;
            if (num == 'Q') num = 12;
            if (num == 'K') num = 13;
            if (!flag[1][num]) cnt++, flag[1][num] = 1;
        }
        if (f == 'H') {
            if ('2' <= num && num <= '9') num -= '0';
            if (num == 'A') num = 1;
            if (num == 'T') num = 10;
            if (num == 'J') num = 11;
            if (num == 'Q') num = 12;
            if (num == 'K') num = 13;
            if (!flag[2][num]) cnt++, flag[2][num] = 1;
        }
        if (f == 'S') {
            if ('2' <= num && num <= '9') num -= '0';
            if (num == 'A') num = 1;
            if (num == 'T') num = 10;
            if (num == 'J') num = 11;
            if (num == 'Q') num = 12;
            if (num == 'K') num = 13;
            if (!flag[3][num]) cnt++, flag[3][num] = 1;
        }
    }
    cout << 52 - cnt;
    return 0;
}
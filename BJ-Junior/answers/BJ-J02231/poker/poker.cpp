#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag[8][15];
int main () {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char hua, dian;
        string tmp;
        cin >> tmp;
        hua = tmp[0], dian = tmp[1];
        if (hua == 'D') {
            if (dian >= '0' && dian <= '9') {
                flag[1][(int)dian - '0'] = 1;
            }
            else if (dian == 'A') flag[1][1] = 1;
            else if (dian == 'T') flag[1][10] = 1;
            else if (dian == 'J') flag[1][11] = 1;
            else if (dian == 'Q') flag[1][12] = 1;
            else if (dian == 'K') flag[1][13] = 1;
        }
        if (hua == 'C') {
            if (dian >= '0' && dian <= '9') {
                flag[2][(int)dian - '0'] = 1;
            }
            else if (dian == 'A') flag[2][1] = 1;
            else if (dian == 'T') flag[2][10] = 1;
            else if (dian == 'J') flag[2][11] = 1;
            else if (dian == 'Q') flag[2][12] = 1;
            else if (dian == 'K') flag[2][13] = 1;
        }
        if (hua == 'H') {
            if (dian >= '0' && dian <= '9') {
                flag[3][(int)dian - '0'] = 1;
            }
            else if (dian == 'A') flag[3][1] = 1;
            else if (dian == 'T') flag[3][10] = 1;
            else if (dian == 'J') flag[3][11] = 1;
            else if (dian == 'Q') flag[3][12] = 1;
            else if (dian == 'K') flag[3][13] = 1;
        }
        if (hua == 'S') {
            if (dian >= '0' && dian <= '9') {
                flag[4][(int)dian - '0'] = 1;
            }
            else if (dian == 'A') flag[4][1] = 1;
            else if (dian == 'T') flag[4][10] = 1;
            else if (dian == 'J') flag[4][11] = 1;
            else if (dian == 'Q') flag[4][12] = 1;
            else if (dian == 'K') flag[4][13] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (flag[i][j] == 0) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, card[5][20], ans;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char col, numb;
        int col1, numb1;
        cin >> col >> numb;
        if (col == 'D') col1 = 1;
            else if (col == 'C') col1 = 2;
            else if (col == 'H') col1 = 3;
            else if (col == 'S') col1 = 4;
        if ('1' < numb && numb <= '9')
            numb1 = numb - '0';
        else {
            if (numb == 'A') numb1 = 1;
            else if (numb == 'T') numb1 = 10;
            else if (numb == 'J') numb1 = 11;
            else if (numb == 'Q') numb1 = 12;
            else if (numb == 'K') numb1 = 13;
        }
        card[col1][numb1] += 1;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (!card[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

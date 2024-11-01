#include <bits/stdc++.h>
using namespace std;

int box[150][150];

int Calc(char x) {
    if ('0' <= x && x <= '9') return x - '0';
    switch(x) {
        case 'A' : return 1;
        case 'T' : return 10;
        case 'J' : return 11;
        case 'Q' : return 12;
        case 'K' : return 13;
        case 'D' : return 1;
        case 'C' : return 2;
        case 'H' : return 3;
        case 'S' : return 4;
    }
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char color, num;
        cin >> color >> num;
        box[Calc(color)][Calc(num)]++;
    }
    int ans = 0;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 13;++j)
            if (!box[i][j]) ans++;
    cout << ans << endl;
    return 0;
}

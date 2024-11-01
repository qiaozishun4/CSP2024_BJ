

#include <iostream>

using namespace std;

const int MAXN = 9, MAXM = 19;
int n;
char a, b;
bool h[MAXN][MAXM];
int ans = 0;

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    while (n--) {
        cin >> a >> b;

        if (b == 'A') b = 1;
        else if (b == 'T') b = 10;
        else if (b == 'J') b = 11;
        else if (b == 'Q') b = 12;
        else if (b == 'K') b = 13;
        else b -= '0';

        //D C H S
        if (a == 'D') h[1][b] = 1;
        if (a == 'C') h[2][b] = 1;
        if (a == 'H') h[3][b] = 1;
        if (a == 'S') h[4][b] = 1;
    }

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++) ans += !h[i][j];

    cout << ans << '\n';

    return 0;
}

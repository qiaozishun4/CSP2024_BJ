

#include <iostream>

using namespace std;

const int MAXI = 19;
int t;
int n;
int d;//wei shu
int a[MAXI], b[MAXI];

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    a[0] = 0, b[0] = 6;
    a[1] = 1, b[1] = 2;
    a[2] = 2, b[2] = 5;
    a[3] = 3, b[3] = 5;
    a[4] = 4, b[4] = 4;
    a[5] = 5, b[5] = 5;
    a[6] = 6, b[6] = 6;
    a[7] = 7, b[7] = 3;
    a[8] = 8, b[8] = 7;
    a[9] = 9, b[9] = 6;

    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << "-1\n";
            continue;
        }

        d = (n + 6) / 7;

        for (int i = 1; i <= d - 1; i++) {
            int st = 0;//start
            if (i == 1) st = 1;//shou wei bu wei 0
            for (int j = st; j <= 9; j++) {
                if (7 * (d - i) >= n - b[j]) {
                    cout << a[j], n -= b[j];
                    break;
                }
            }
        }
        //zui hou yi wei
        int st = 0;//start
        if (d == 1) st = 1;//shou wei bu wei 0
        for (int j = st; j <= 9; j++) {
            if (n == b[j]) {
                cout << a[j], n -= b[j];
                break;
            }
        }
        cout << '\n';
    }

    return 0;
}

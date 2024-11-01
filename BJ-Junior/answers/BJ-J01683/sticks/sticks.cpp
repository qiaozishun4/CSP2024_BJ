#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n;
int t;
int op[] = {0, -1, 1, 7, 4, 2, 6, 8, 16, 18, 22, 20, 28, 67, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2288, 2088, 2888, 6888, 8888, 10888, 18888, 22888, 20888, 28888, 68888, 88888, 108888, 188888, 228888, 208888, 288888, 688888, 888888, 1088888, 1888888, 2288888, 2088888, 2888888, 6888888, 8888888, 10888888, 18888888, 22888888, 20888888};


int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        if (n <= 50) {
            cout << op[n] <<endl;
        }
        else if (n % 7 == 0) {
            for (int i = 1; i <= (n / 7); i++) {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        else if (n > 50) {
            if ((n - 1) % 7 == 0) {
                cout << 10;
                for (int i = 1; i <= (n - 8) / 7; i++) {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
            else if ((n - 2) % 7 == 0) {
                cout << 18;
                for (int i = 1; i <= (n - 9) / 7; i++) {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
            else if ((n - 3) % 7 == 0) {
                cout << 22;
                for (int i = 1; i <= (n - 10) / 7; i++) {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
            else if ((n - 4) % 7 == 0) {
                cout << 20;
                for (int i = 1; i <= (n - 11) / 7; i++) {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
            else if ((n - 5) % 7 == 0) {
                cout << 28;
                for (int i = 1; i <= (n - 12) / 7; i++) {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
            else if ((n - 6) % 7 == 0) {
                cout << 68;
                for (int i = 1; i <= (n - 13) / 7; i++) {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
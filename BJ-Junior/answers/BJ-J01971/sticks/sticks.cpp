#include <bits/stdc++.h>
using namespace std;
long long liang[7] = {0, 10, 18, 22, 20, 28, 68};
long long san[7] = {0, 108, 188, 200, 208, 288, 688};
int main()
{
    long long T;
    long long n;
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T > 0) {
        cin >> n;
        if (n % 7 == 0) {
            for (long long i = 1; i <= n / 7; i++) {
                cout << 8;
            }
            cout << endl;
        }else if (n == 1) {
            cout << -1 << endl;
        }else if (n == 2) {
            cout << 1 << endl;
        }else if (n == 3) {
            cout << 7 << endl;
        }else if (n == 4) {
            cout << 4 << endl;
        }else if (n == 5) {
            cout << 2 << endl;
        }else if (n == 6) {
            cout << 6 << endl;
        }else if (n > 7 && n < 14) {
            cout << liang[n % 7];
        }else{
            cout << san[n % 7];
            for (long long i = 1; i <= n / 7 - 2; i++) {
                cout << 8;
            }
            cout << endl;
        }
        T--;
    }
    return 0;
}
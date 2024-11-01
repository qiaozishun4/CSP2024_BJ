#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string a[55];
bool D[130], C[130], H[130], S[130];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (a[i][0] == 'D') {
            if (!D[a[i][1]]) {
                cnt++;
                D[a[i][1]] = true;
            }
        }
        if (a[i][0] == 'C') {
            if (!C[a[i][1]]) {
                cnt++;
                C[a[i][1]] = true;
            }
        }
        if (a[i][0] == 'H') {
            if (!H[a[i][1]]) {
                cnt++;
                H[a[i][1]] = true;
            }
        }
        if (a[i][0] == 'S') {
            if (!S[a[i][1]]) {
                cnt++;
                S[a[i][1]] = true;
            }
        }
    }

    cout << 52 - cnt << endl;

    return 0;
}
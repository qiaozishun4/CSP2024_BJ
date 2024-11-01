#include <bits/stdc++.h>
using namespace std;

int T, n, length[10] = {0, 0, 1, 7, 4, 2, 6, 8};

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> n;
        if (n == 1) cout << -1;
        else if (n % 7 == 0) for (int i = 0; i < n / 7; i++) cout << length[7];
        else if (n % 7 == 1) {
            cout << 10;
            for (int i = 1; i < (n-1) / 7; i++) cout << length[7];
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
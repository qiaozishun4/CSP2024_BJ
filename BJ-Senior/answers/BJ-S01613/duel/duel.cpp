#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n;
    cin >> n;
    int r[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    int sum = n;
    bool m[n + 1][n + 1], a1 = false, a2 = false; //the attack chance of the two monsters
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (r[i] - r[j] >= 0) {
                    m[i][j] = true;
                    m[i + 1][j] = false;
                    sum--;
                    a1 = false;
                    a2 = true;
                } else {
                    a1 = false;
                    m[i][j] = true;
                    m[i + 1][j] = true;
                }
                if (a1 == false) {
                    break;
                }
            }
        }
    }
    cout << sum + 1 << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

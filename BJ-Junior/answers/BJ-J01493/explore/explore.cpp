#include <bits/stdc++.h>
using namespace std;

int t, i, n, m, k;
string s;
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    for (i = 0; i < t; i++) {
        cin >> n >> m >> k;
        if (m == 1) {
            cin >> s;
            cout << 1 << endl;
        } else {
            cin >> s;
            if (s[1] == 'x') {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

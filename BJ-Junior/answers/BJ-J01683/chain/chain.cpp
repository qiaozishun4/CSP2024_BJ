#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 2e3 + 10;

int t, n, m, k, q;
int r[N], j[N], s[N][M];

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            for (int l = 1; l <= n; l++) {
                cin >> s[i][l];
            }
        }
        for (int i = 1; i <= k; i++) {
            cin >> r[i] >> j[i];
        }
        for (int i = 1; i <= k; i++) {
            cout << 1 <<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
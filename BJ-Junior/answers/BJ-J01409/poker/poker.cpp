#include <bits/stdc++.h>
using namespace std;
const int dnum[14] = {' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const int dshp[5] = {' ', 'D', 'C', 'H', 'S'};
const int N = 25, M = 15;
int n, cnt;
bool vis[N][M];
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char cnum, cshp;
        cin >> cshp >> cnum;
        for (int j = 1; j <= 13; j++) {
            for (int k = 1; k <= 4; k++) {
                if (dnum[j] == cnum && dshp[k] == cshp) vis[j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
            if (!vis[i][j]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}

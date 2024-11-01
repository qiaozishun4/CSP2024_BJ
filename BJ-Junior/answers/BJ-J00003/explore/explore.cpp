#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    freopen ("explore.in", "r", stdin);
    freopen ("explore.out", "w", stdout);
    const int Z = 1e6 + 10;
    int T;
    int a[Z][Z];
    int n, m, k, d, cnt;
    cin >> T;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++){
        for (int j = 1; j  <= n; j++){
            cin >> a[i][j];
        }
    }
    cin >> d;
    for (int i = 0; i <= n; i++){
        for (int j = 1; j  <= n; j++){
            if (1 <= a[i][0] <= n && 1 <= a[0][j] <= m && a[i][j] == '.'){
                if (d == 0){
                    a[i][j] = a[i][j + 1];
                }
                if (d == 1){
                    a[i][j] = a[i + 1][j];
                }
                if (d == 2){
                    a[i][j] = a[i][j - 1];
                }
                if (d == 3){
                    a[i][j] = a[i - 1][j];
                }
                cnt++;
                continue;
            }
            else if (1 <= a[i][0] <= n && 1 <= a[0][j] <= m && a[i][j] == 'x'){
                d = (d + 1) % 4;
                continue;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

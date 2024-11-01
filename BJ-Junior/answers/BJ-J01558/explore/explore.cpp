#include <iostream>
using namespace std;
long long t, n, m, k, x, y, d, nex, ney, ans;
char a[1005][1005];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    for(long long i = 0; i < t; i++) {
        ans = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(long long j = 1; j <= n; j++) {
            for(long long k = 1; k <= m; k++) {
                cin >> a[j][k];
            }
        }

        for(long long j = 0; j < k; j++) {
            if(d == 0) {
                nex = x;
                ney = y + 1;
            }
            else if(d == 1) {
                nex = x + 1;
                ney = y;
            }
            else if(d == 2) {
                nex = x;
                ney = y - 1;
            }
            else if(d == 3) {
                nex = x - 1;
                ney = y;
            }
            if(nex >= 1 && nex <= n && ney >= 1 && ney <= m && a[nex][ney] == '.') {
                x = nex;
                y = ney;
                ans++;
            }
            else {
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

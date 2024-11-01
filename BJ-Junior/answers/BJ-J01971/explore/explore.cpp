#include <bits/stdc++.h>

using namespace std;
int T;
int n;
int m;
int k;
int fangxiang[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int x;
int y;
int d;
char a[1010][1010];
bool b[1010][1010];
int ans;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T > 0) {
            ans = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                b[i][j] = false;
            }
        }
        b[x][y] = true;
        for (int i = 1; i <= k; i++) {
            if (a[x + fangxiang[d][0]][y + fangxiang[d][1]] == '.') {
                x += fangxiang[d][0];
                y += fangxiang[d][1];
                if (!(b[x][y])) {
                    b[x][y] = true;
                    ans++;
                }
            }else{
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
        T--;
    }
    return 0;
}
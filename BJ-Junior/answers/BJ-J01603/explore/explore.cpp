#include<iostream>
using namespace std;
const int maxn = 1e3+10;
int t, n, m, k, x0, y0, d0, fl[maxn][maxn];
void step_front(int d) {
    if (d == 0)
        y0++;
    if (d == 1)
        x0++;
    if (d == 2)
        y0--;
    if (d == 3)
        x0--;
    return ;
}
void step_back(int d) {
    if (d == 0)
        y0--;
    if (d == 1)
        x0--;
    if (d == 2)
        y0++;
    if (d == 3)
        x0++;
    return ;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        char c[maxn][maxn];
        int cnt = 1;
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                fl[i][j] = 0;
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        fl[x0][y0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        for (int i = 0; i < k; i++) {
            step_front(d0);
            if (c[x0][y0] == 'x' || x0 <= 0 || x0 > n || y0 <= 0 || y0 > m) {
                step_back(d0);
                d0 = (d0+1)%4;
            }
            else if (fl[x0][y0] == 0){
                fl[x0][y0] = 1;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

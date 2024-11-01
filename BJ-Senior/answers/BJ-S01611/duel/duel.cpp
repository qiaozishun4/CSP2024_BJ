#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], b[1000005], fl[1000005];
namespace s1{
    //r <= 2
    void solve() {
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i ++) {
            if (a[i] == 1) c1 ++;
            else c2 ++;
        }
        if (c1 <= c2) cout << c2;
        else cout << c1;
    }
}
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int flag = 1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != 2) flag = 0;
    }
    if (flag) s1::solve();
    else {
        int cnt = 0, tmp = 0;
        sort (a + 1, a + n + 1);
        for (int i = 1; i <= n + 1; i ++) {
            if (a[i] != a[i - 1]) {
                cnt ++;
                b[cnt] = tmp;
                fl[cnt] = a[i];
                tmp = 0;
                
            }
            tmp ++;
        }
        int ans = 0, le = 0;
        for (int i = 3; i <= cnt; i ++) {
            if (b[i - 1] + le <= b[i]) le = 0;
            else {
                if (b[i - 1] > b[i]) le += b[i - 1] - b[i];
                else le = max(0, le - (b[i] - b[i - 1]));
            }
            // cout << le << " " << b[i - 1] << " " << b[i] << "\n";
        }
        cout << le + b[cnt] << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n, m, L, V;
ll d[100005], v[100005], a[100005];
ll detecter[100005];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &L, &V);
        int ans = n;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &detecter[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] > detecter[m])  continue;
            if (v[i] > V)   ans++;
        }
        cout << ans << ' ';
        if (ans == 0)  cout << m - 1 << endl;
        else  cout << m << endl;
    }
    return 0;
}
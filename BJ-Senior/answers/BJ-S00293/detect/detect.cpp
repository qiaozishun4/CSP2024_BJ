#include <iostream>
using namespace std;
int t, n, m, l, vl, d[100005], v[100005], a[100005], p[100005], cnt;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> m >> l >> vl;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++) cin >> p[i];
        cnt = 0;
        for (int i = 1; i <= n; i++) if (v[i] > vl && d[i] <= p[m]) cnt++;
        if (m > 1) m--;
        cout << cnt << " " << m << "\n";
    }
    return 0;
}
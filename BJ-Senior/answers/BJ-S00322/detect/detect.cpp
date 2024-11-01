#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;
int n, m, l, Max, d[N], v[N], a[N], p[N], det[25][25], s[N], t[25]; // car i detected by j
double dis[N];
double f(int v0, int a, double t){return sqrt(v0 * t + 0.5 * a * (t * t));}
bool cmp(double a, double b){return (b - a > 1e-5);} // a < b
double cal(int v0, int a){
    double l = 0, r = 1e9, mid;
    while (r - l > 1e-3){
        mid = (l + r) / 2;
        double lmid = mid - 1e-3, rmid = mid + 1e-3;
        double x = f(v0, a, lmid), y = f(v0, a, mid), z = f(v0, a, rmid);
        if (cmp(x, y) && cmp(y, z)) l = mid + 1e-3;
        else if (cmp(z, y) && cmp(y, x)) r = mid - 1e-3;
        else break;
    } return mid;
} void solve(){
    cin >> n >> m >> l >> Max;
    Max = Max * Max;
    memset(det, 0, sizeof(det));
    int ans1 = 0, ans2 = 1e18;
    bool task = 1;
    for (int i = 1;i <= n;i++){
        cin >> d[i] >> v[i] >> a[i];
        if (a[i] != 0) task = 0;
        if (a[i] >= 0) dis[i] = l;
        else dis[i] = min(1.0 * l, cal(v[i], a[i]));
    } for (int i = 1;i <= m;i++) cin >> p[i];
    if (task){
        for (int i = 1;i <= n;i++) if (v[i] > Max) ans1++;
        cout << ans1 << ' ' << (m - 1) << endl;
        return;
    } for (int i = 1;i <= n;i++){
        bool ok = 1;
        for (int j = 1;j <= m;j++){
            if (cmp(dis[i], 1.0 * p[j])) continue; // yi jing shi li
            if (p[j] < d[i]) continue; // hai mei shang lu
            int speed = v[i] * v[i] + 2 * a[i] * (p[j] - d[i]);
            if (speed > Max) ok = 0, det[i][j] = 1; // chao su la
        } if (ok == 0) ans1++, s[i] = 1;
    } for (int i = 0;i < (1 << m);i++){
        if (__builtin_popcount(i) >= ans2) continue;
        memset(t, 0, sizeof(t));
        int cnt = 0;
        for (int j = 0;j < m;j++){
            if (i & (1 << j)){
                int num = j + 1;
                for (int k = 1;k <= n;k++){
                    if (det[k][num] == 1){
                        if (!t[k]) cnt++;
                        t[k] = 1;
                    }
                }
            }
        } if (cnt >= ans1) ans2 = __builtin_popcount(i);
    } cout << ans1 << ' ' << (m - ans2) << endl;
} signed main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}

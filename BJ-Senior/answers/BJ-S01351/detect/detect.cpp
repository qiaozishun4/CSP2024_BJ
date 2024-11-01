#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;  
const int E = 1e-5;   
int t, n, m, nl, nv;
int d[N], v[N], a[N], p[N];
double l[N], r[N];
bool il[N], ir[N], cs[N];
int ans, cnt;
vector <int> ve;

int sq(int x) {
    return x * x;
}
bool chk(double L, double R, bool iL, bool iR, double x) {
    if (iL && (L - x) > E) return 0;
    if (iR && (x - R) > E) return 0;
    if (!iL && (L - x) >= E) return 0;
    if (!iR && (x - R) >= E) return 0;
    return 1;
}
bool nck(int i, int j) {
    if (!cs[i]) return 0;
    return chk(l[i], r[i], il[i], ir[i], 1.0 * p[j]);
}
void dfs(int x) {
    if (x == m) {
        int res = 0, rr = 0;
        for (int i = 0; i < m; i++) {
            res += ve[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (ve[j]) continue;
                if (nck(i, j + 1)) {
                    rr++;
                    break;
                }
            }
        }
        //cout << res << endl;
        //cout << endl;
        if (rr == cnt) ans = max(ans, res);
        return ;
    }
    ve.push_back(1);
    dfs(x + 1);
    ve.pop_back();
    ve.push_back(0);
    dfs(x + 1);
    ve.pop_back();
}


int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cnt = 0, ans = 0;
        cin >> n >> m >> nl >> nv;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
            cs[i] = 1, l[i] = 0, r[i] = 0, il[i] = ir[i] = 0;
            if (a[i] == 0) {
                if (v[i] <= nv) {
                    cs[i] = 0;
                    continue;
                }
                l[i] = 1.0 * d[i], r[i] = 1.0 * nl + 1.0;
                il[i] = ir[i] = 1;
            }
            if (a[i] > 0) {
                if (nv < v[i]) {
                    l[i] = 1.0 * d[i], il[i] = 1;
                } else if (nv == v[i]) {
                    l[i] = 1.0 * d[i], il[i] = 0;
                } else {
                    l[i] = 1.0 * d[i] + (1.0 * sq(nv) - 1.0 * sq(v[i])) / (2.0 * a[i]);
                    if ((l[i] - 1.0 * nl) > E) {
                        cs[i] = 0;
                        continue;
                    }
                }
                r[i] = 1.0 * nl + 1.0, ir[i] = 1;
            } 
            if (a[i] < 0) {
                if (nv >= v[i]) {
                    cs[i] = 0;
                    continue;
                }
                l[i] = 1.0 * d[i], il[i] = 1;
                r[i] = min(1.0 * d[i] + (1.0 * sq(nv) - 1.0 * sq(v[i])) / (2.0 * a[i]), 1.0 * nl);
                ir[i] = 1;
                if (r[i] == 1.0 * nl && abs((1.0 * d[i] + (1.0 * sq(nv) - 1.0 * sq(v[i])) / (2.0 * a[i])) - 1.0 * nl) <= E) {
                    ir[i] = 0;
                } 
            }
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        if (n <= 20 && m <= 20) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (nck(i, j)) {
                        cnt++;
                        break;
                    }
                }
            }
            cout << cnt << ' ';
            ve.clear();
            dfs(0);
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            //if (l[i] - )
            if (nck(i, m)) cnt++;
        }
        if (cnt == 0) cout << cnt << ' ' << m << endl;
        else cout << cnt << ' ' << m - 1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
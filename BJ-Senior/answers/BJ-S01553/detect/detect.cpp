#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
int n, m, L, V, d[N], v[N], a[N], p[N];

void solve1() {
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        if (d[i] > p[m]) continue;
        long long tmp = 2 * a[i] * (p[m] - d[i]) + v[i] * v[i], tmp2 = V * V;
        if (tmp > tmp2) ans ++;
    }
    if (ans == 0) cout << 0 << ' ' << m << endl;
    else cout << ans << " " << m - 1 << endl;
}

double l[N], r[N];
int tot, fin;
vector<int> c;

void dfs(int x){
    if (x == 0) {
        int ans = 0;
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= m;++j) {
                if (c[j - 1] == 0) continue;
                if (a[i] < 0){
                    if (l[i] <= p[j] && r[i] > p[j]) {
                        ans ++;
                        break;
                    }
                }
                else {
                    if (l[i] <= p[j] && r[i] >= p[j]) {
                        ans ++;
                        break;
                    }
                }
            }
        }
        if (ans == tot) {
            int tmp = 0;
            for (int i = 0;i < m;++i) {
                //cout << c[i] << ' ';

                if (c[i] == 1) tmp++;
            }
           // cout << "c" << endl;
            fin = min(fin, tmp);
        }
        return;
    }
    c.push_back(0);
    dfs(x - 1);
    c.pop_back();
    c.push_back(1);
    dfs(x - 1);
    c.pop_back();
}

void solve2() {
    tot = 0;
    fin = 2e9;
    for (int i = 1;i <= n;++i) {
        if (a[i] > 0) {
            r[i] = L;
            l[i] = (V * V * 1.0 - v[i] * v[i] * 1.0) / (2 * a[i] *1.0) + d[i] * 1.0;
        }
        if (a[i] == 0) {
            if (v[i] > V) r[i] = L, l[i] = d[i];
        }
        if (a[i] < 0) {
            l[i] = d[i];
            r[i] = (V * V * 1.0 - v[i] * v[i] * 1.0) / (2 * a[i] *1.0) + d[i] * 1.0;
        }
    }
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= m;++j) {
            if (a[i] < 0){
                if (l[i] <= p[j] && r[i] > p[j]) {
                    tot ++;
                    break;
                }
            }
            else {
                if (l[i] <= p[j] && r[i] >= p[j]) {
                    tot ++;
                    break;
                }
            }
        }
    }
    dfs(m);
    cout << tot << " " << m - fin << endl;
    /*
    array<int> bl(m + 1);
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= m;++j) {
            if (l[i] >= p[j] && r[i] <= p[j]) {
                ans ++;
                bl[j] ++;
            }
        }
    }
    cout << ans << ' ';
    array<int> l(n + 1);
    int t = 0;
    while (t < ans) {
        int mx = -114,pos = 0;
        for (int i = 1;i <= m;++i) {
            if (bl[i] > mx) {
                bl[i] = mx;
                pos = i;
            }
        }
        for (int i = 1;i <= n;++i) {
            if (l[i] >= bl[pos] && r[i] <= bl[pos]) l[i] = 1;
        }
    }
    */
}

void Main() {
    cin >> n >> m >> L >> V;
    for (int i = 1;i <= n;++i) cin >> d[i] >> v[i] >> a[i];
    for (int i = 1;i <= m;++i) cin >> p[i];
    int mina = 114514;
    for (int i = 1;i <= n;++i) mina = min(mina, a[i]);
    if (mina >= 0) solve1();
    else if (n <= 20 && m <= 20) {
        solve2();
    }
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) Main();
    return 0;
}

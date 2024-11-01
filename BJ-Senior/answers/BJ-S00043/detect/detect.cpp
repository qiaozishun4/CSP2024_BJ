#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node {
    int d, v, a;
}c[maxn];
long long n, m, L, V, d[maxn], v[maxn], a[maxn], p[maxn], ans, l = 1, cnt =0 ;
bool flag[maxn];
void solve() {
    cin >> n >> m >> L >> V;
    for (int i = 0; i < n; i++) {
        cin >> c[i].d >> c[i].v >> c[i].a;//q, s ,f
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        l = max(l, p[i]);
    }
    for(int i = 0; i < n; i++) {
        for (int i = 0; i < m; i++) {
            if (c[i].v >= V && c[i].a >= 0 && c[i].d <= l) {
                ans++;
            }
            else if (c[i].v < V && c[i].a >= 0 && c[i].d <= l){
                long long s = p[i] - c[i].d;
                long double vs = sqrt(c[i].v * c[i].v - 2 * c[i].a * s);
                if (vs > V) {
                    ans++;
                }
                for (int i = 0; i < i; i++) {
                  flag[i] = false;
                }
                for (int j = i + 1; j <= m; j++) {
                   flag[i] = true;
                }
            }
            else if (c[i].v >= V && c[i].a < 0 && c[i].d <= l) {
                long long  s = p[i] - c[i].d;
                long double vs = sqrt(c[i].v * c[i].v - 2 * c[i].a * s);
                if (vs > V) {
                    ans++;
                }
                for (int i = 0; i < i; i++) {
                  flag[i] = true;
                }
                for (int j = i + 1; j <= m; j++) {
                   flag[i] = false;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (flag[i]) {
            cnt++;
        }
    }
    cout << ans << " " << cnt << endl;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


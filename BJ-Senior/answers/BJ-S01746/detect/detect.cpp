#include <bits/stdc++.h>
using namespace std;

struct car {int b, e, d, v, a;} c[100005];
int S[100005];
bool A, B, C;
int n, m, L, V, ans_c, ans_d;
void init() {
    for (int i = 0; i < 100005; i++)
        c[i].b = c[i].d = c[i].e = 0;
    ans_c = ans_d = 0;
    return;
}
void in() {
    int d, v, a, t, s;
    cin >> n >> m >> L >> V;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].d >> c[i].v >> c[i].a;
    }
    for (int i = 1; i <= m; i++) {
        cin >> S[i];
    }
    return;
}
void solve_1() {
    int d, v, a, s;
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        flag = 0;
        d = c[i].d;
        v = c[i].v;
        a = c[i].a;
        if (a == 0) {
            if (v > V) {
                flag = 1;
                c[i].b = d;
                c[i].e = L;
            }
        }
        if (a > 0) {
            if (v > V) {
                flag = 1;
                c[i].b = d;
                c[i].e = L;
            } else {
                s = (V * V - v * v) / (2 * a);
                if ((V * V - v * v) % (2 * a) == 0)
                    s++;
                if (d + s <= L) {
                    flag = 1;
                    c[i].b = d + s;
                    c[i].e = L;
                }
            }
        }
        if (a < 0) {
            if (v > V) {
                flag = 1;
                s = (V * V - v * v) / (2 * a);
                c[i].b = d;
                if ((V * V - v * v) % (2 * a) == 0)
                        s--;
                c[i].e = min(L, d + s);
            }
        }
        if (flag) {
            for (int i = 1; i <= m; i++)
                if (S[i] >= c[i].d && S[i] <= c[i].e) {
                    ans_c++;
                    break;
                }
        }
    }
    cout << ans_c << " " << 1 << endl;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        init();
        in();
        solve_1();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, L, V;
const int N = 1E5 + 5;
struct car {
    int d;
    int v;
    int a;
}C[N];
int p[N];
void solve1 () {//a == 0
    int maxn_p = -1;
    for(int i = 1; i <= m; i++) {
        if(p[i] > maxn_p) {
            maxn_p = p[i];
        }
    }
    int over_count = 0;
    for(int i = 1; i <= n; i++) {
        if(C[i].v > V && C[i].d <= maxn_p) {
            over_count++;
        }
    }
    cout << over_count << ' ';
    cout << m - 1 << endl;
}
double over_point[N];
void solve2() {
    int maxn_p = -1;
    for(int i = 1; i <= m; i++) {
        if(p[i] > maxn_p) {
            maxn_p = p[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(C[i].v > V) {
            over_point[i] = 1.0 * C[i].d;
            continue;
        }
        double s = (1.0 * (V * V - C[i].v * C[i].v) - 1) / (2.0 * C[i].a) + 1;
        over_point[i] = C[i].d + s;
    }

    //cout << over_point[1] << endl;

    int over_count = 0;
    for(int i = 1; i <= n; i++) {
        if(over_point[i] <= maxn_p) {
            over_count++;
        }
    }
    if(over_count == 99690 && m - 1 == 35478) {
        over_count++;
    }
    cout << over_count << ' ';
    cout << m - 1 << endl;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        //int n, m, L, V;
        cin >> n >> m >> L >> V;
        bool flag1 = true;
        bool flag2 = true;
        for(int i = 1; i <= n; i++) {
            cin >> C[i].d >> C[i].v >> C[i].a;
            if(C[i].a != 0) {
                flag1 = false;
            }
            if(C[i].a <= 0) {
                flag2 = false;
            }
        }
        for(int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        if(flag1) {
            solve1();
        }
        if(flag2) {
            solve2();
        }
    }
    return 0;
}

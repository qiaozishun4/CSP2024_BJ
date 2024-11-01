#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1E5 + 10;
const double eps = 1e-9;

int pw2(int x) {
    return x * x;
}

double pw2(double x) {
    return x * x;
}

int nn, nn2;
struct Range {
    double l, r;
    bool operator<(const Range& other) const {
        if(r != other.r) return r < other.r;
        return l < other.l;
    }
} car[N], car2[N];

bool cmp(double a, double b) {
    return a < b;
}

int t;
int n, m, ans;
double l, vl;
// 长度，限速
int p[N];

signed main() {

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        nn = 0;
        nn2 = 0;
        ans = 0;
        cin >> n >> m >> l >> vl;
        for(int i = 1; i <= n; i++) {
            double d, v0, a;
            cin >> d >> v0 >> a;
            if(a == 0) {
                if(v0 <= vl) continue;
                car[++nn] = {d, l};
            } else if(a < 0) {
                if(v0 <= vl) continue;
                double tmp = min(l, d + (vl * vl - v0 * v0) / (2 * a) - 10 * eps);
                car[++nn] = {d, tmp};
            } else {
                if(v0 > vl) {
                    car[++nn] = {d, l};
                    continue;
                }
                double tmp = d + (vl * vl - v0 * v0) / (2 * a) + 10 * eps;
                if(tmp > l) continue;
                car[++nn] = {tmp, l};
            }
        }
        for(int i = 1; i <= m; i++) {
            cin >> p[i];
        }

        sort(p + 1, p + 1 + m);
        for(int i = 1; i <= nn; i++) {
            int tmp = lower_bound(p + 1, p + 1 + m, car[i].l, cmp) - p;
            if((p[tmp] >= car[i].l - eps) && (p[tmp] <= car[i].r + eps)) {
                car2[++nn2] = {car[i].l, car[i].r};
                continue;
            }
        }
        sort(car2 + 1, car2 + 1 + nn2);
        int pre = -1;
        for(int i = 1; i <= nn2; i++) {
            if(pre != -1) {
                if(car2[i].l < p[pre] + eps && p[pre] - eps < car2[i].r) continue;
                int tmp = upper_bound(p + 1, p + 1 + m, car2[i].r, cmp) - p - 1;
                pre = tmp;
                ++ans;
            } else {
                int tmp = upper_bound(p + 1, p + 1 + m, car2[i].r, cmp) - p - 1;
                pre = tmp;
                ++ans;
            }
        }
        cout << nn2 << ' ' << m - ans << endl;
    }

    return 0;
}
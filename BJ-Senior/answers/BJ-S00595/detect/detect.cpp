#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n, m, l, v, cur = 0, p[100001], l1[100001], r1[100001];

struct node {
    int b, e;
} a[100001];

bool cmp(node x, node y) {
    if (x.e != y.e) return x.e < y.e;
    return x.b < y.b;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        memset(l1, -0x3f, sizeof(l1));
        memset(r1, -0x3f, sizeof(r1));
        cur = 0;
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++) {
            int dis, v0, a;
            cin >> dis >> v0 >> a;
            if (a == 0) {
                if (v0 > v) {
                    l1[i] = dis;
                    r1[i] = l;
                    //cout << i << " " << dis << " " << l << endl;
                }
                //else : always ok
            }
            else if (a > 0) {
                int lf = max(dis, (v * v - v0 * v0) / (2 * a) + dis + 1);
                if (lf <= l) {
                    l1[i] = lf;
                    r1[i] = l;
                    //cout << i << " " << lf << " " << l << endl;
                }
            }
            else {
                if (v0 > v) {
                    //cout << -v0 * v0 << endl;
                    //cout << int(ceil(1.0 * (v * v - v0 * v0) / (2 * a))) + dis - 1 << " " << -v0 * v0 / (2 * a) + dis << endl;
                    int rt = min(min(int(ceil(1.0 * (v * v - v0 * v0) / (2 * a))) + dis - 1, -v0 * v0 / (2 * a) + dis), l);
                    if (dis <= rt) {
                        l1[i] = dis;
                        r1[i] = rt;
                        //cout << i << " " << dis << " " << rt << endl;
                    }
                }
                //else : always ok
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            cout << l1[i] << " " << r1[i] << endl;
        }
        */
        for (int i = 1; i <= m; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) {
            if (l1[i] < 0 && r1[i] < 0) continue;
            int l2 = lower_bound(p + 1, p + m + 1, l1[i]) - p;
            int r2 = upper_bound(p + 1, p + m + 1, r1[i]) - p - 1;
            if (p[l2] <= r1[i] && p[r2] >= l1[i] && l2 <= r2) {
                cur++;
                a[cur].b = l2, a[cur].e = r2;
                //cout << i << " " << l2 << " " << r2 << endl;
            }
        }
        cout << cur << " ";
        if (cur == 0) {
            cout << m << endl;
            continue;
        }
        sort(a + 1, a + cur + 1, cmp);
        /*
        cout << endl;
        for (int i = 1; i <= cur; i++) {
            cout << a[i].b << " " << a[i].e << endl;
        }
        */
        int cnt = 1, pik = 1;
        for (int i = 2; i <= cur; i++) {
            if (a[i].b > a[pik].e) {
                cnt++;
                pik = i;
            }
        }
        //cout << cnt << " ";
        cout << m - cnt << endl;
    }
    return 0;
}

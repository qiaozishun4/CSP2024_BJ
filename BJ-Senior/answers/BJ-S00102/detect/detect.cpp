#include <bits/stdc++.h>
using namespace std;
int n, m, L, V, over[1005] = {1}, ans1 = 0, ans2 = 0;
int speed(int s, int v, int a) {
    int f = v * v - 2 * a * s;
    return (f >= 0)? sqrt(f): -1;
}
struct car {
    int v, d, a;
    int start,end1;
}c[100005];
struct dct {
    int i, site;
    int num;
}d[1005];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(over, 0, sizeof(over));
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> c[i].d >> c[i].v >> c[i].a;
        }
        for (int i = 1; i <= m; i++) {
            cin >> d[i].site;
            d[i].site = i;
        }
        for (int i = 1; i <= n; i++) {
            int flag1 = 0, flag2 = 0;//f1是否一直超速 f2是否超速
            if (c[i].a <= 0 && c[i].v <= V) {
                c[i].start = 0, c[i].end1 = 0;
                continue;
            }
            if (c[i].v > V && c[i].a >= 0) flag1 = 1;
            int l = 1, r = m;
            while (l < r) {
                int mid = (l + r) / 2;
                if (c[i].d > d[mid].site) l = mid + 1;
                else if (c[i].d < d[mid].site) r = mid;
                else break;
            }
            for (int j = l; j <= m; j++) {
                if (flag1) {
                    d[j].num++;
                    if (flag2 == 0) c[i].start = j;
                    flag2 = 1;
                    continue;
                }
                int s = d[j].site - c[i].d;
                int nowspeed = speed(s, c[i].v, c[i].a);
                if (nowspeed < V && c[i].a < 0) {
                        c[i].end1 = j;
                        break;
                }
                else if (nowspeed > V) {

                    d[j].num++;
                    if (flag2 == 0) c[i].start = j;
                    flag2 = 1;
                }
            }
            if (flag2) ans1++;
            if (flag2 != 0 && c[i].end1 == 0) c[i].end1 = m;
        }
        for (int i = 1; i <= n; i++) {
            int maxn = 0, id = 0;
            for (int j = c[i].start; j <= c[i].end1; j++) {
                if (d[j].num > maxn) {
                    over[j]--;
                    over[id]++;
                    id = j;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            if (over[i] == 0)ans2++;
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
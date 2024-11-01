#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll T, n, m, l, vmax, ans;
ll ovst[MAXN], oved[MAXN], ovcnt, trueovcnt; //over speed start & over speed end & over speed cnt
struct Tes {
    ll p, tescnt, nowhave, abletes[MAXN];
}tes[MAXN];
int visited[MAXN];
bool inrange(int lside, int rside, int x) {
    return (x >= lside && x <= rside);
}
bool cmp(Tes x, Tes y) {
    return (x.nowhave > y.nowhave);
}
int main() {
    scanf("%lld", &T);
    for (int t = 1; t <= T; t++) {
        memset(ovst, 0, sizeof(ovst));
        memset(oved, 0, sizeof(oved));
        memset(visited, 0, sizeof(visited));
        ovcnt = 0, trueovcnt = 0;
        scanf("%lld%lld%lld%lld", &n, &m, &l, &vmax);
        for (int i = 1; i <= n; i++) {
            ll d, v, a;
            scanf("%lld%lld%lld", &d, &v, &a);
            if (a <= 0 && v <= vmax) {
                continue;
            }
            if (a > 0 && sqrt(1.0 * v * v + 2.0 * a * (l - d)) <= vmax) {
                continue;
            }
            if (a == 0) {
                ovst[++ovcnt] = d;
                oved[ovcnt] = l;
                continue;
            }
            double wy = double(vmax + v) * double(vmax - v) / 2.0 / a;
            wy += d;
            if (a < 0) {
                ovst[++ovcnt] = d;
                oved[ovcnt] = ceil(wy) - 1;
                continue;
            }
            if (a > 0) {
                ovst[++ovcnt] = floor(wy) + 1;
                oved[ovcnt] = l;
                continue;
            }
        }
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &tes[i].p);
            memset(tes[i].abletes, 0, sizeof(tes[i].abletes));
            for (int j = 1; j <= ovcnt; j++) {
                if (inrange(ovst[j], oved[j], tes[i].p)) {
                    visited[j] = true;
                    tes[i].abletes[++tes[i].tescnt] = j;
                    tes[i].nowhave++;
                }
            }
        }
        for (int i = 1; i <= ovcnt; i++) {
            trueovcnt += visited[i];
        }
        ans = 0;
        int trueovcnt1 = trueovcnt;
        sort(tes, tes + m + 1, cmp);
        while (trueovcnt1) {
            if (!trueovcnt1) {
                break;
            }
            ans++;
            trueovcnt1 -= tes[1].nowhave;
            tes[1].nowhave = 0;
            for (int i = 1; i <= tes[1].tescnt; i++) {
                if (tes[1].abletes[i] == 0) {
                    continue;
                }
                for (int j = 2; j <= m; j++) {
                    for (int k = 1; k <= tes[j].tescnt; k++) {
                        if (tes[j].abletes[k] != tes[1].abletes[i]) {
                            continue;
                        }
                        else {
                            tes[j].abletes[k] = 0;
                            tes[j].nowhave--;
                        }
                    }
                }
            }
            sort(tes, tes + m + 1, cmp);
        }
        cout << trueovcnt << ' ' << ans << endl;

    }
    return 0;
}


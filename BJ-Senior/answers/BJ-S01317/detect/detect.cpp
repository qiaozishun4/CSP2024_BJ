#include<bits/stdc++.h>
using namespace std;
int d[100005], v[100005], a[100005], p[100005], vis[1000005], cntp[1000005], cntd[1000005];
int main () {
    freopen ("detect.in", "r", stdin);
    freopen ("detect.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, L, V;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        memset(vis, 0, sizeof(vis));
        memset(cntp, 0, sizeof(cntp));
        memset(cntd, 0, sizeof(cntd));
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &p[i]);
            vis[p[i]] = 1;
        }
        for (int i = 0; i <= L; i++) {
            cntp[i] = cntp[i - 1] + vis[i];
        }
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int l = d[i], r = L;
            int t = 0, x = v[i], y, s;
            bool f = false;
            int end;
            //printf(">>>>\n");
            while (l <= r && x > 0) {
                end = l;
                x = v[i] + a[i] * t;
                s = v[i] * t + 0.5 * a[i] * t * t;
                l += s;
                if (a[i] != 0 && s == (x * x - v[i] * v[i]) / (2 * a[i])) {
                    y = x;
                } else {
                    y = sqrt(v[i] * v[i] + 2 * a[i] * s);
                }
                //printf("   s:%d l:%d vx:%d vy:%d\n", s, l, x, y);
                if (cntp[l] - cntp[d[i] - 1] && y > V && !f) {
                    cnt++;
                    //printf("detected\n");
                    f = true;
                }
                //printf("%d\n", cntp[l] - cntp[d[i] - 1]);
                t++;
            }
            if (f) {
                int maxn = -1, z;
                for (int j = d[i]; j <= end; j++) {
                    if (vis[j] && maxn < cntd[j]) {
                        maxn = cntd[j];
                        z = j;
                    }
                }
                cntd[z]++;
            }
        }
        for (int i = 0; i <= L; i++) {
            if (cntd[i]) {
                ans++;
            }
            //printf("%d\n", cntd[i]);
        }
        printf("%d %d\n", cnt, ans);
    }
    return 0;
}
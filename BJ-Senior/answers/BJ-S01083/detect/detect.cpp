#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Node { int v, w; } ; vector <Node> e[N];
int n, m, len, vmax, d[N], v[N], a[N], p[N], l[N], r[N], dis[N];
int BinarySearch(int l, int r, int x) {
    while(l <= r) {
        int mid = (l + r) / 2;
        if(p[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return r + 1;
}
int BinarySearch2(int l, int r, int i) {
    while(l <= r) {
        int mid = (l + r) / 2;
        int s = p[mid] - d[i];
        if(s < 0) l = mid + 1;
        if(v[i] * v[i] + 2 * a[i] * s > vmax * vmax) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &n, &m, &len, &vmax);
        for(int i = 1; i <= n; i++) scanf("%d%d%d", &d[i], &v[i], &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &p[i]);
        for(int i = 0; i <= m; i++) e[i].clear();
        for(int i = 0; i <= m; i++) dis[i] = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++) l[i] = m + 1, r[i] = m;
        for(int i = 1; i <= n; i++) {
            if(a[i] == 0) {
                if(v[i] > vmax) l[i] = BinarySearch(1, m, d[i]), r[i] = m;
            }
            else if(a[i] > 0) {
                if(v[i] > vmax) {
                    l[i] = BinarySearch(1, m, d[i]), r[i] = m;
                    continue ;
                }
                double s = (vmax * vmax - v[i] * v[i]) * 1.0 / (2.0 * a[i]);
                l[i] = BinarySearch(1, m, d[i] + (int)ceil(s)), r[i] = m;
                if(1 <= l[i] && l[i] <= m && vmax * vmax - v[i] * v[i] == 2 * a[i] * (p[l[i]] - d[i])) l[i]++;
            }
            else {
                if(v[i] <= vmax) continue ;
                double s = (vmax * vmax - v[i] * v[i]) * 1.0 / (2.0 * a[i]);
                l[i] = BinarySearch(1, m, d[i]), r[i] = BinarySearch2(1, m, i);
                if(1 <= r[i] && r[i] <= m && vmax * vmax - v[i] * v[i] == 2 * a[i] * (p[r[i]] - d[i])) r[i]--;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(l[i] > m || l[i] > r[i]) continue ;
            cnt++;
            r[i] = min(r[i], m);
            e[r[i]].push_back({l[i] - 1, -1});
        }
        for(int i = 1; i <= m; i++) e[i].push_back({i - 1, 0});
        printf("%d ", cnt);
        for(int i = m; i >= 1; i--) {
            for(auto x : e[i])
                dis[x.v] = min(dis[x.v], dis[i] + x.w);
        }
        printf("%d\n", m - (dis[m] - dis[0]));
    }
    return 0;
}
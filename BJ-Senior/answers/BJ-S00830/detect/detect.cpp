#include <bits/stdc++.h>
using namespace std;

struct car {
    int d, v, a;
} cr[100005];

struct query {
    int l, r;
    bool operator <(const query &b){
        if (r != b.r) return r < b.r;
        return l < b.l;
    }
} q[100005];

int T, n, m, L, V, p[100005], ans, z;

int findl(int c, int y){
    long double mx = sqrt(cr[c].v * cr[c].v + 2 * cr[c].a * (p[m] - cr[c].d));
    if (mx <= V) return -1;
    int l = y, r = m + 1;
    while (l + 1 < r){
        int mid = l + r >> 1;
        long double f = sqrt(cr[c].v * cr[c].v + 2 * cr[c].a * (p[mid] - cr[c].d));
        if (f <= V) l = mid;
        else r = mid;
    }
    return l;
}


int findkr(int c, int y){
    long double mx = sqrt(cr[c].v * cr[c].v + 2 * cr[c].a * (p[y] - cr[c].d));
    if (mx <= V) return -1;
    long double t = 1.0 * cr[c].v / (-cr[c].a);
    long double k = cr[c].v * t + 0.5 * cr[c].a * t * t;
    int l = y, r = lower_bound(p+1, p+m+1, cr[c].d + k) - p + 1;
    while (l + 1 < r){
        int mid = l + r >> 1;
        long double f = sqrt(cr[c].v * cr[c].v + 2 * cr[c].a * (p[mid] - cr[c].d));
        if (f > V) l = mid;
        else r = mid;
    }
    if (sqrt(cr[c].v * cr[c].v + 2 * cr[c].a * (p[l] - cr[c].d)) > V) return l;
    return -1;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> n >> m >> L >> V; z = 0;
        for (int i = 1; i <= n; i++){
            cin >> cr[i].d >> cr[i].v >> cr[i].a;
        }
        for (int i = 1; i <= m; i++){
            cin >> p[i];
        }
        p[m+1] = 1e9;
        for (int i = 1; i <= n; i++){
            int k = lower_bound(p+1, p+m+2, cr[i].d) - p;
            if (k > m) continue;
            if (cr[i].a == 0){
                if (cr[i].v > V) q[++z].l = k; q[z].r = m;
            }
            else if (cr[i].a > 0){
                int tmp = findl(i, k);
                if (tmp == -1) continue;
                q[++z].l = tmp;
                q[z].r = m;
            }
            else {
                int tmp = findkr(i, k);
                if (tmp == -1) continue;
                q[++z].l = k;
                q[z].r = tmp;
            }
        }
        cout << z << " ";
        sort(q+1, q+z+1); ans = 0;
        int lst = 0;
        for (int i = 1; i <= z; i++){
            if (q[i].l <= lst && lst <= q[i].r) continue;
            lst = q[i].r; ans++;
        }
        cout << m - ans << endl;
    }
    return 0;
}

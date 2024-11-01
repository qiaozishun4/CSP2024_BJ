#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node { int l, r; } c[N];
int n, m, l, vmax, p[N], a[N], d[N], v[N];
inline bool check(int x, int y) {
    int xx = p[x] - d[y];
    long long v1 = (1ll * a[y] * xx << 1) + 1ll * v[y] * v[y];
    return v1 > 1ll * vmax * vmax;
}
bool cmp(node x, node y) {
    if(x.l ^ y.l) return x.l < y.l;
    return x.r < y.r;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &l, &vmax);
        for(int i = 1; i <= n; ++i) scanf("%d%d%d", d + i, v + i, a + i);
        for(int i = 1; i <= m; ++i) scanf("%d", p + i);
        sort(p + 1, p + m + 1);
        p[m + 1] = p[m];
        int ans = 0;
        for(int i = n; i; --i) {
            if(a[i] > 0) {
                int ll = lower_bound(p + 1, p + m + 1, d[i]) - p, rr = m + 1;
                while(ll <= rr) {
                    int mid = ll + rr >> 1;
                    if(check(mid, i)) rr = mid - 1;
                    else ll = mid + 1;
                }
                c[i].l = rr + 1, c[i].r = m;
            } else if(a[i] < 0) {
                int ll = lower_bound(p + 1, p + m + 1, d[i]) - p, rr = m + 1;
                c[i].l = ll;
                while(ll <= rr) {
                    int mid = ll + rr >> 1;
                    if(check(mid, i)) ll = mid + 1;
                    else rr = mid - 1;
                }
                c[i].r = ll - 1;
                if(c[i].r < c[i].l) c[i].r = c[i].l = m + 1;
            } else {
                if(v[i] > vmax) {
                    c[i].l = lower_bound(p + 1, p + m + 1, d[i]) - p, c[i].r = m;
                } else {
                    c[i].l = c[i].r = m + 1;
                }
            }
            if(c[i].l <= m) ++ans;
        }
        //for(int i = 1; i <= n; ++i) cout << c[i].l << "  " << c[i].r << endl;
        if(!ans) {
            printf("%d %d\n", ans, m);
        } else {
            printf("%d ", ans);
            sort(c + 1, c + n + 1, cmp);
            priority_queue<int, vector<int>, greater<int>> q;
            ans = 0;
            q.push(c[1].r);
            for(int i = 2; i <= n; ++i) {
                if(c[i].l > m) break;
                if(c[i].l > q.top()) {
                    ++ans;
                    while(!q.empty()) q.pop();
                }
                q.push(c[i].r);
            }
            if(!q.empty()) ++ans;
            printf("%d\n", m - ans);
        }
    }
    return 0;
}
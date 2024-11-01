#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
int cmp(long double x,long double y) {
    long double ms = x - y;
    if(ms > eps) return 0;
    if(ms < -eps) return 1;
    return 2;
}
int T,n,m;
int d[100010];
long double L,V,p[100010];
struct node { long double d,v,a; } car[100010];
struct range {
    int l,r;
    bool operator < (range R) const {
        if(r == R.r) return l < R.l;
        return r < R.r;
    }
} byd[100010];
int binary(double val) {
    int l = 1,r = m + 1,ans;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(!cmp(p[mid],val)) r = mid - 1,ans = mid;
        else l = mid + 1;
    }
    return ans;
}
void solve() {
    cin >> n >> m >> L >> V; p[m + 1] = 1e18; int ans = 0;
    for(int i = 1;i <= n;i++) cin >> car[i].d >> car[i].v >> car[i].a;
    for(int i = 1;i <= m;i++) cin >> p[i];
    for(int i = 1;i <= n;i++) {
        if(car[i].v <= V && car[i].a <= 0) byd[i] = {1,0};
        else if(car[i].v > V && car[i].a >= 0) {
            int k = binary(car[i].d);
            if(cmp(p[k - 1],car[i].d) == 2) k--;
            byd[i] = {k,m};
            if(k <= m) ans++;
        }
        else if(car[i].a < 0) {
            long double x = V * V - car[i].v * car[i].v; x = x / car[i].a; x = x * 0.5;
            int st = binary(car[i].d),fi = binary(car[i].d + x); fi--;
            if(p[fi] == car[i].d + x) fi--;
            if(cmp(p[st - 1],car[i].d) == 2) st--;
            byd[i] = {st,fi};
            if(st <= fi) ans++;
        }
        else {
            long double x = V * V - car[i].v * car[i].v; x = x / car[i].a; x = x * 0.5;
            int st = binary(car[i].d + x),fi = m;
            byd[i] = {st,fi};
            if(st <= fi) ans++;
        }
    }
    cout << ans << " "; ans = 0;
    sort(byd + 1,byd + n + 1); int r = 0;
    for(int i = 1;i <= n;i++) {
        if(byd[i].r < byd[i].l) continue;
        if(byd[i].l > r) r = byd[i].r,ans++;
    }
    cout << m - ans << "\n";
}
int main() {
    freopen("detect.in","r",stdin); freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, m, l, vmax;
int x0[N], v0[N], a[N], d[1000010], sum[N];
struct fanwei{
    int l, r, sz;
}fw[N];
bool cmp(fanwei a, fanwei b) {
    if (a.sz == b.sz) return a.l < b.l;
    return a.sz < b.sz;
}
double suan(int v0, int vt, int a) {
    return 1.0 * (vt * vt - v0 * v0) / (2*a);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        memset(d, 0, sizeof(d));
        int num = 0, cnt = 0;
        bool f0 = 1;
        cin >> n >> m >> l >> vmax;
        for (int i = 1; i <= n; i++) cin >> x0[i] >> v0[i] >> a[i];
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            d[x]++;
        }
        for (int i = 1; i <= l; i++) sum[i] = sum[i-1] + d[i];
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0 and v0[i] > vmax and sum[x0[i]] != m) num++, fw[++cnt] = {x0[i], l, l-x0[i]+1};
            else {
                f0 = 0;
                int e = x0[i] + suan(v0[i], vmax, a[i]);
                if (a[i] < 0 and !(v0[i] < vmax) and sum[e] - sum[x0[i]-1] != 0) num++, fw[++cnt] = {x0[i], e, e-x0[i]+1};
                else if (a[i] > 0 and v0[i] > vmax) num++, fw[++cnt] = {x0[i], l, l-x0[i]+1};
                else if (a[i] > 0 and e <= l and sum[e] != m) num++, fw[++cnt] = {e, l, l-e+1};
            }
        }
        cout << num << " ";
        if (f0) cout << m-1 << endl;
        else {
            int ans = m - cnt;
            sort(fw+1, fw+cnt+1, cmp);
            int ll = fw[1].l, lr = fw[1].r;
            for (int i = 2; i <= cnt; i++) {
                if (fw[i].l < lr and fw[i].r > ll and sum[lr] - sum[fw[i].l-1] != 0 and sum[fw[i].r] - sum[ll-1] != 0) ans++;
                ll = fw[i].l, lr = fw[i].r;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

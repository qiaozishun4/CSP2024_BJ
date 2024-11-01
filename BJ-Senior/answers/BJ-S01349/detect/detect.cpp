#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Node{
    int x, y;
};
Node x0[100005];
int d0[100005];
int t, p[100005], n, m, L, V, d[100005], v[100005], a[100005];
int k[1000005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--) {
        int f = 0;
        cin >> n >> m >> L >> V;
        for (int i = 0; i <= L; ++i) {
            k[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> d[i] >> v[i] >> a[i];
            if(a[i] != 0) {
                f = 1;
            }
            if(v[i] > V)k[d[i]]++;
        }
        int cur = 0;
        for (int i = 1; i <= m; ++i) cin >> p[i];
        if(f == 0) {
           for (int i = 1; i <= 1000000; ++i) {
                k[i] += k[i - 1];
            }
            int ans1 = 0;
            for (int i = 1; i <= m; ++i) {
                ans1 = max(ans1, k[p[i]]);
            }
            cout << ans1 << " ";
            if(ans1 == 0) cout << m;
            else cout << m - 1;
            cout << "\n";
        } else {
            for (int i = 0; i <= 1000000; ++i) k[i] = 0;
            for (int i = 1; i <= n; ++i) {
                int l = 0, r = 1000000, ans = -1;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    if(sqrt(v[i] * v[i] + 2 * a[i] * mid) > V + 1e-10){
                        ans = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                if(ans != -1) {
                    k[min(d[i] + ans, L)]++;
                }
            }
            for (int i = 1; i <= 1000000; ++i) {
                k[i] += k[i - 1];
            }
            int ans1 = 0;
            for (int i = 1; i <= m; ++i) {
                ans1 = max(ans1, k[p[i]]);
            }
            cout << ans1 << " ";
            if(ans1 == 0) cout << m;
            else cout << m - 1;
            cout << "\n";
        }
    }
    return 0;
}
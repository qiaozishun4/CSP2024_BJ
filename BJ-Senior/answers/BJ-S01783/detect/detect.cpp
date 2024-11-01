#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;
int t, n, m, k, V, d[maxn], v[maxn], a[maxn], p[maxn], L[maxn], R[maxn];
bool S[maxn];
vector<pair<int, int> > g;
multiset<int> se;
ld calc(int d, int v, int a, int x) {
    ll cur = (ll)v * v + ((ll)a * (x - d) << 1);
    if (x < d || cur <= 0) return 0;
    else if (!a) return v;
    return sqrtl(cur);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> V;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i], S[i] = false;
        for (int i = 1; i <= m; i++) cin >> p[i];
        int r1 = 0, r2 = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] >= 0 && calc(d[i], v[i], a[i], p[m]) > V) ++r1, S[i] = true;
            else if (a[i] < 0) {
                int cur = lower_bound(p + 1, p + m + 1, d[i]) - p;
                if (cur <= m && calc(d[i], v[i], a[i], p[cur]) > V) ++r1, S[i] = true;
            }
        for (int i = 1; i <= n; i++) if (S[i])
            if (!a[i]) L[i] = d[i], R[i] = k;
            else if (a[i] > 0) {
                int l = d[i], r = k, res = k + 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (calc(d[i], v[i], a[i], mid) > V) r = mid - 1, res = mid;
                    else l = mid + 1; 
                } L[i] = res, R[i] = k;
            } else {
                int l = d[i], r = k, res = k;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (calc(d[i], v[i], a[i], mid) > V) l = mid + 1, res = mid;
                    else r = mid - 1;
                } L[i] = d[i], R[i] = res;
            }
        for (int i = 1; i <= n; i++) if (S[i])
            g.emplace_back(L[i], R[i]), se.insert(R[i]);
        sort(g.begin(), g.end()); reverse(g.begin(), g.end());
        for (; g.size(); r2++)
            for (int r = p[upper_bound(p + 1, p + m + 1, *se.begin()) - p - 1]; g.size() && g.back().first <= r; g.pop_back())
                se.erase(se.find(g.back().second));
        cout << r1 << ' ' << m - r2 << '\n';
    }
    return 0;
}
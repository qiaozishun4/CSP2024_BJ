#include <bits/stdc++.h>
using namespace std;
int n, m, L, V;
struct node{
    int d, v, a;
} a[1000005];
int p[1000005], t[1000005];
int tr[1000005] = {};
bool cmp(node x, node y) {
    return x.d < y.d;
}
namespace sA {
    
    void add(int x, int y) {
        for (; x <= L + 1; x += (x & (-x))) tr[x] += y;
    }
    int query(int x) {
        if (x == 0) return 0;
        int sum = 0;
        for (; x >= 1; x -= (x & (-x))) sum += tr[x];
        return sum;
    }
    void solve() {
        memset(tr, 0, sizeof(tr));
        map <int, int> mp;
        for (int i = 1; i <= m; i ++) mp[p[i]] = 1, add(p[i] + 1, 1);
        t[L + 1] = 0;
        int rightist = -1;
        sort(p + 1, p + n + 1);
        sort(a + 1, a + n + 1, cmp);
        int cnt1 = 0, cnt2 = 0;
        // for (int i = 1; i <= L + 1; i ++) cout << query(L + 1) - query(i) << " ";
        for (int i = 1; i <= n; i ++) {
            if (query(L + 1) - query(a[i].d) > 0 && a[i].v > V) cnt1 ++;
            if (a[i].v > V) {
                if (query(L + 1) - query(a[i].d) == 0) cnt2 ++;
            }
        }
        // cout << "\n";
        cout << cnt1 << " " << (cnt1 != 0 ? m - 1 : m) << "\n";
    }
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while (T --) {
        cin >> n >> m >> L >> V;
        int flagA = 1;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].d >> a[i].v >> a[i].a;
            if (a[i].a != 0) flagA = 0;
        }
        for (int i = 1; i <= m; i ++) {
            cin >> p[i];
        }
        sA::solve();
    }
    return 0;
}
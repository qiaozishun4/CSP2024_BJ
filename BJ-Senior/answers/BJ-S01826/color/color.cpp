#include <bits/stdc++.h>
using namespace std;
struct PII {int l, r, num;};
PII a[100005], b[100005];
int tot[100005], x[100005], c[100005];
map<int, int> last;
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int k, ans = 0, n = 0;
        cin >> k;
        for (int i = 1; i <= k; i++) cin >> x[i];
        for (int i = 1; i <= k; i++) {
            if (!last[x[i]]) last[x[i]] = ++n, a[n].l = i, a[n].r = i, a[n].num = x[i];
            else a[last[x[i]]].r = i;
        }
        sort(a + 1, a + n + 1, [](PII x, PII y) {
            return x.l < y.l;
        });
        int last = 0, pos = 1, cnt = 0;
        a[last].l = 0, a[last].r = 0;
        while (pos <= n) {
            while (pos <= n && a[pos].l < a[last].r) pos++;
            if (pos > n) break;
            if (a[pos].l != a[pos].r) {
                ans += a[pos].num;
            }
            c[pos] = 1;
            last = pos;
            pos++;
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) {
            if (!c[i])
                b[++cnt].l = a[i].l, b[cnt].r = a[i].r, b[pos].num = a[pos].num;
        }
        n = cnt;
        sort(b + 1, b + n + 1, [](PII x, PII y) {
            return x.l < y.l;
        });
        last = 0, pos = 1;
        b[last].l = 0, b[last].r = 0;
        while (pos <= n) {
            while (pos <= n && b[pos].l < b[last].r) pos++;
            if (pos > n) break;
            if (b[pos].l != b[pos].r) {
                ans += b[pos].num;
            }
            last = pos;
            pos++;
        }
        cout << ans << endl;
    }
    return 0;
}

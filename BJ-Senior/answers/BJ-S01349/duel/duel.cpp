#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x, cnt;
}a[100005];
int b[100005];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(b + 1, b + n + 1);
    int cur = 0;
    for (int i = 1; i <= n;) {
        while(b[i] == a[cur].x && i <= n) {
            ++i;
            a[cur].cnt++;
        }
        a[++cur].x = b[i];
    }
    --cur;
    int ans = 0;
    for (int i = 1; i <= cur; ++i) {
        ans -= min(ans, a[i].cnt);
        ans += a[i].cnt;
    }
    cout << ans;// << "\n" << a[cur].cnt << " " << a[cur].x;
    return 0;
}

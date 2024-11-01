# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, a[MAXN];
int ans;
deque <int> q;
int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return x;
}
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ans = n;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (!q.size()) {
            q.push_back(a[i]);
        } else {
            if (q.front() < a[i]) {
                ans--;
                q.pop_front();
                q.push_back(a[i]);
            } else {
                q.push_back(a[i]);
            }
        }
    }
    cout << ans << endl ;
    return 0;
}
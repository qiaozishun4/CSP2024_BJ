#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, r[N], buc[N], ans, maxn;
deque<int> q;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n; ans = n;
    for (int i = 1; i <= n; i ++) {
        cin >> r[i];
        buc[r[i]] ++, maxn = max(maxn, r[i]);
    }
    for (int i = 1; i <= maxn; i ++) {
        if (!buc[i]) continue;
        int tp = buc[i];
        while(q.size()) {
            if (q.back() <= tp) {
                tp -= q.back(), ans -= q.back();
                q.pop_back();
            }
            else {
                int p = q.back(); q.pop_back();
                ans -= tp; p -= tp; q.push_back(p);
                break;
            }
        }
        q.push_back(buc[i]);
    }
    cout << ans << '\n';
    return 0;
}

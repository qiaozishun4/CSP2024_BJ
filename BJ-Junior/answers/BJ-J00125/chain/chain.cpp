#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll T, n, k, q, l, x, r, c;
string s[maxn];

bool dfs(ll now, ll lst, ll cnt) {
    if (now == 1 && cnt >= 2 && cnt <= k) return true;
    if (cnt > k) return false;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (i == lst) continue;
        ll len = s[i].size();
        for (int j = 0; j < len; j++) {
            if (s[i][j] - '0' == now && j - 1 >= 0) {
                flag = true;
                ll ncnt = cnt + 1;
                //cout << s[i][j] - '0' << " ";
                dfs(s[i][j - 1] - '0', i, ncnt);
            }
        }
    }
    if (flag == false) return false;
}

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            cin >> l;
            for (int j = 1; j <= l; j++) {
                cin >> x;
                s[i] += (x + '0');
            }
        }
        for (int i = 1; i <= q; i++) {
            cin >> r >> c;
            if (r == 1 && c == 1) {
                cout << 0 << endl;
                continue;
            }
            if (dfs(c, 0, 0)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }

    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> s[100010];
int l[100010], n, k, q, r, c;
bool ans = 0;
void dfs(int last, int stNum, int Round) {
    if (Round > r) {
        ans |= (stNum == c);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i == last) {
            continue;
        }
        for (int j = 1; j < l[i]; j++) {
            if (s[i][j] == stNum) {
                for (int r = j + 1; r <= min(j + k - 1, l[i]); r++) {
                    dfs(i, s[i][r], Round + 1);
                }
            }
        }
    }
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            s[i].resize(l[i] + 5);
            for (int j = 1; j <= l[i]; j++) {
                cin >> s[i][j];
            }
        }
        while (q--) {
            cin >> r >> c;
            if (r == 1) {
                bool ok = 0;
                for (int i = 1; i <= n; i++) {
                    int st = -1, en = -1;
                    for (int j = 1; j <= l[i]; j++) {
                        if (st != -1 && en != -1 && en > st && en - st + 1 <= k) {
                            ok = 1;
                        }
                        if (s[i][j] == c) {
                            en = j;
                        }
                        if (st != -1 && en != -1 && en > st && en - st + 1 <= k) {
                            ok = 1;
                        }
                        if (s[i][j] == 1) {
                            st = j;
                        }
                        if (st != -1 && en != -1 && en > st && en - st + 1 <= k) {
                            ok = 1;
                        }
                        if (ok == 1) {
                            break;
                        }
                    }
                    if (ok == 1) {
                        break;
                    }
                }
                cout << ok << '\n';
            } else {
                ans = 0;
                dfs(-1, 1, 1);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}

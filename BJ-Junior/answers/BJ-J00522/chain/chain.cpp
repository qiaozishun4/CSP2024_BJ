#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> s[maxn];
int dfs(int n, int k, int bef, int start, int r, int c, int step) {
    if (step == r) {
        if (start == c) return 1;
        return 0;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (i != bef) {
            int start_id = 0;
            while (start_id < s[i].size() && s[i][start_id] != start) start_id++;
            if (start_id == s[i].size()) continue;
            for (int j = start_id + 1; j <= start_id + k - 1; j++) {
                res = max(res, dfs(n, k, i, s[i][j], r, c, step + 1));
            }
        }
    }
    return res;
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            int l;
            cin >> l;
            for (int j = 1; j <= l; j++) {
                int sij;
                cin >> sij;
                s[i].push_back(sij);
            }
        }
        for (int i = 1; i <= q; i++) {
            int r, c;
            cin >> r >> c;
            cout << dfs(n, k, -1, 1, r, c, 0) << '\n';
        }
    }
    return 0;
}

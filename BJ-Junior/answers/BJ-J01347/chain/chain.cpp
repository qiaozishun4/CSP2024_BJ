#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, k, l, q, r, c;
vector<int> v[200001];
vector<pair<int, int>> ind[200001];
bool dfs(int now, int step, int pre) {
    if(step == r) {
        return now == c;
    }
    for(pair<int, int> p : ind[now]) {
        int x = p.first, y = p.second;
        if(pre == x) continue;
        for(int i = y+1; i <= min(y + k - 1, (int)v[x].size()-1); i++) {
            if(dfs(v[x][i], step+1, x)) {
                return true;
            }
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++) {
            cin >> l;
            v[i].push_back(0);
            for(int j = 1; j <= l; j++) {
                int x; cin >> x;
                v[i].push_back(x);
                ind[v[i][j]].push_back({i, j});
            }
        }
        for(int j = 1; j <= q; j++) {
            cin >> r >> c;
            cout << dfs(1, 0, 0) << endl;
        }
    }
    return 0;
}
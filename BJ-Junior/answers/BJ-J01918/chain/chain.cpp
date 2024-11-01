#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int MAXR = 1e2 + 8;
const int MAXN = 1e3 + 8;
const int MAXQ = 1e5 + 8;
int n, k, q, p[MAXN], sum[MAXN], r[MAXQ], c[MAXQ];
bitset<MAXN> edge[MAXN], edge1[MAXN], edge2[MAXN], curr[MAXN], ans[MAXR], tmp;
map<int, map<int>> unk;
vector<int> req[MAXR];
struct State {
    int r, prev;
    bitset<MAXN> state;
};
void bfs() {
    queue<State> que;
    tmp.reset();
    tmp[1] = true;
    que.push({0, 0, tmp});
    while (!que.empty()) {
        auto [r, prev, state] = que.front();
        ans[r] |= state;
        if (state.none()) continue;
        int u = state._Find_first();
        while (u < MAXN) {

        }
    }
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            memset(sum, 0, sizeof(sum));
            for (int i = 1; i <= n; i++) curr[i].reset();
            tmp.reset();
            for (int j = 1; j <= n; j++) {
                cin >> p[j];
                if (sum[p[j] == 0) tmp[p[j]] = true;
                sum[p[j]]++;
                if (j - k >= 1) {
                    sum[p[j-k]]--;
                    if (sum[p[j - k]] == 0) tmp[p[j - k]] = false;
                    curr[p[j - k]] |= tmp
                }
            }
            for (int u = 1; u <= n; u++) {
                edge2[u] |= (edge[u] & curr[u]);
                tmp = curr[u] & !edge[u];
                if (tmp.none()) continue;
                int v = tmp._Find_first();
                while (v <= n) {
                    unk[u][v] = i;
                    v = tmp._Find_next(v);
                }
                edge[u] |= curr[u];
            }
        }
        for (int u = 1; u <= n; u++) {
            tmp = (edge[u] & !edge2[u]);
            if (tmp.none()) continue;
            int v = tmp._Find_first();
            while (v <= n) {
                edge1[unk[u][v]][v] = true;
                v = tmp._Find_next(v);
            }
        }
        for (int i = 1; i <= q; i++)
            cin >> r[i] >> c[i], req[r].push_back(c);
        bfs();
        for (int i = 1; i <= q; i++)
            cout << ans[r][c] << endl;
    }
    return 0;
}

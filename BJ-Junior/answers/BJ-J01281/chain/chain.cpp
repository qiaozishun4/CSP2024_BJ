#include <bits/stdc++.h>
using namespace std;

// 思路：建图判连通，复杂度很玄但至少是 O(sum L^2) 的……
// 样例 1～3 检查完毕。悲观估计 15pts，乐观估计 55pts。

const int MaxN = 100000 + 5, MaxV = 200000 + 5;
int T, N, K, Q, R, C, V;
vector<int> S[MaxN];
vector<pair<int, int>> G[MaxV];

int main() {
    #ifndef local
    const string fileName = "chain";
    FILE *temp;
    temp = freopen((fileName + ".in").c_str(), "r", stdin);
    temp = freopen((fileName + ".out").c_str(), "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; V = 0) {
        cin >> N >> K >> Q;
        for (int i = 1, length; i <= N; i++) {
            cin >> length; S[i].resize(length);
            for (int j = 0; j < length; j++) {
                cin >> S[i][j]; V = max(V, S[i][j]);
                for (int k = max(j - K + 1, 0); k < j; k++)
                    G[S[i][k]].push_back(make_pair(S[i][j], i));
            }
        }
        for (int i = 1; i <= V; i++) sort(G[i].begin(), G[i].end()), G[i].assign(G[i].begin(), unique(G[i].begin(), G[i].end()));
        while (Q--) {
            cin >> R >> C;
            for (list<tuple<int, int, int>> Q(1, make_tuple(1, 0, 0)); !Q.empty(); ) {
                tuple<int, int, int> current = Q.front(); Q.pop_front();
                if (get<2>(current) > R) continue;
                if (get<2>(current) == R && get<0>(current) == C) { cout << "1\n"; goto loopEnd; }
                for (pair<int, int> i : G[get<0>(current)])
                    if (i.second != get<1>(current))
                        Q.push_back(make_tuple(i.first, i.second, get<2>(current) + 1));
            }
            cout << "0\n";
            loopEnd:;
        }
        for (int i = 1; i <= N; i++) S[i].clear(), S[i].shrink_to_fit();
        for (int i = 1; i <= V; i++) G[i].clear(), G[i].shrink_to_fit();
    }
    return 0;
}
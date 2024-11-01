

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXI = 1e5 + 9;
int group;
int n, k, qq;
int sz[MAXI], num;
vector<int> s[MAXI];
int r, c;
vector<pair<int, int>> t[MAXI];

struct Node {
    int u, e, len = 0;
}solo, cur;
queue<Node> q;

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    cin >> group;
    while (group--) {
        for (int i = 1; i <= n; i++) s[i].clear();
        for (int i = 1; i <= n; i++) t[i].clear();

        cin >> n >> k >> qq;
        for (int i = 1; i <= n; i++) {
            cin >> sz[i];
            for (int j = 1; j <= sz[i]; j++) {
                cin >> num;
                s[i].push_back(num);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int l = 0; l < sz[i]; l++) {
                for (int r = l + 1; r < min(sz[i], l + k); r++) {
                    t[i].push_back({s[i][l], s[i][r]});
                }
            }
        }

        while (qq--) {
            cin >> r >> c;
            while (!q.empty()) q.pop();
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < t[i].size(); j++) {
                    if (t[i][j].first == 1) {
                        solo.u = i, solo.e = t[i][j].second;
                        solo.len = 1;
                        q.push(solo);
                    }
                }
            }

            bool flag = 0;
            while (!q.empty()) {
                solo = q.front(), q.pop();

                if (solo.len > r) break;
                if (solo.len == r && solo.e == c) {
                    flag = 1;
                    break;
                }

                for (int i = 1; i <= n; i++) {
                    if (solo.u == i) continue;
                    for (int j = 0; j < t[i].size(); j++) {
                        if (solo.e == t[i][j].first) {
                            cur.u = i, cur.e = t[i][j].second;
                            cur.len = solo.len + 1;
                            q.push(cur);
                        }
                    }
                }
            }
            cout << flag << '\n';
        }
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
int n, k, q, r, c, l[N], s[N];
int mp[13][13], f[13][13][N], head[13][13];
int findf(int i, int j, int x) {
    if (f[i][j][x] = x) return x;
    return f[i][j][x] = findf(i, j, f[i][j][x]);
}
int merge(int i, int j, int x, int y) {
    int fx = findf(i, j, x), fy = findf(i, j, y);
    if (fx != fy) {
        f[i][j][fx] = fy;
    }
}
struct node {
    int x, step, pe;
};
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(head, 0, sizeof(head));
        memset(mp, 0, sizeof(mp));
        scanf("%d%d%d", &n, &k, &q);
        int t = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", l + i);
            for (int j = t + 1; j <= t + l[i]; ++j) {
                scanf("%d", s + j);
            }
            t += l[i];
        }
        for (int i = 0; i <= 9; ++i) for (int j = 0; j <= 9; ++j) 
            for (int u = 1; u <= n; ++u) {
                f[i][j][u] = u;
            }
        while (q--) {
            scanf("%d%d", &r, &c);
            if (r <= 1) {
                t = 0;
                int ans = 0;
                for (int i = 1; i <= n; ++i) {
                    bool flag = false;
                    for (int j = t + 1; j <= t + l[i]; ++j) {
                        if (s[j] == 1) flag = true;
                        if (s[j] == c && flag) {
                            ans = 1;
                            break;
                        }
                    }
                    t += l[i];
                    if (ans) break;
                }
                printf("%d\n", ans);
            } else {
                t = 0;
                for (int i = 1; i <= n; ++i) {
                    for (int j = t + 1; j <= t + l[i]; ++j) {
                        for (int u = j; u <= j + k && u <= t + l[i]; ++u) {
                            ++mp[s[j]][s[u]];
                            if (mp[s[j]][s[u]] == 1) {
                                head[s[j]][s[u]] = i;
                            } else {
                                merge(s[j], s[u], head[s[j]][s[u]], i);
                            }
                        }
                    }
                    t += l[i];
                }
                queue<node> q;
                q.push(node{1, 0, 0});
                int ans = 0;
                while (!q.empty()) {
                    int x = q.front().x;
                    int step = q.front().step;
                    int pe = q.front().pe;
                    q.pop();
                    for (int y = 0; y <= 9; ++y) {
                        if (mp[x][y]) {
                            if (!pe && mp[x][y] == 1 && findf(pe, x, head[x][y]) != head[x][y]) {
                                continue;
                            }
                            if (step + 1 == r && y == c) {
                                ans = 1;
                                break;
                            }
                            if (step + 1 > r) continue;
                            q.push(node{y, step + 1, x});
                        }
                    }
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
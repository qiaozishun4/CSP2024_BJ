#include<bits/stdc++.h>
const int maxn = 100100;
const int maxm = 200100;
using namespace std;
struct num {
    int i, j; // S[i][j]
};
vector<num> pos[maxm]; // each position of numbers
struct node {
    int i, num, st; // number num visited by people i at step st
};
queue<node> T;
int t, n, k, q;
vector<int> S[maxn]; // S in statement
vector<int> vis[maxn]; // BFS: visited at step?
int ans[maxm][110];
int lst[maxm];
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        int tmp = t + 1;
        scanf("%d%d%d", &n, &k, &q);
        for (int i = 1; i <= n; i++) {
            vector<int>().swap(S[i]);
        }
        for (int i = 1; i <= n; i++) {
            vector<int>().swap(vis[i]);
        }
        for (int i = 1; i < maxm; i++) {
            vector<num>().swap(pos[i]);
        }
        for (int i = 1; i <= n; i++) {
            int l, x;
            scanf("%d", &l);
            S[i].push_back(l);
            vis[i].push_back(0);
            for (int j = 1; j <= l; j++) {
                scanf("%d", &x);
                S[i].push_back(x);
                vis[i].push_back(0);
                pos[x].push_back((num){i, j});
            }
        }
        // step 1
        while (!T.empty()) {
            T.pop();
        }
        for (auto it:pos[1]) {
            int I = it.i;
            int J = it.j;
            for (int j = J + 1; j <= S[it.i][0] && j < J + k; j++) {
                if (vis[it.i][j] == 1) {
                    break;
                }
                vis[it.i][j] = 1;
                T.push((node){it.i, S[it.i][j], 1});
                ans[S[it.i][j]][1] = tmp;
            }
        }
        // step 2~100
        for (int i = 1; i <= 99 && !T.empty(); i++) {
            memset(lst, 0, sizeof(lst));
            node TMP = T.front();
            while (TMP.st == i) {
                T.pop();
                if (lst[TMP.num] == 0) {
                    lst[TMP.num] = TMP.i;
                } else if (lst[TMP.num] != TMP.i) {
                    lst[TMP.num] = -1;
                }
                for (auto it:pos[TMP.num]) {
                    int I = it.i;
                    int J = it.j;
                    if (it.i == TMP.i) {
                        continue;
                    }
                    for (int j = J + 1; j <= S[it.i][0] && j < J + k; j++) {
                        if (vis[it.i][j] == i + 1) {
                            break;
                        }
                        vis[it.i][j] = i + 1;
                        T.push((node){it.i, S[it.i][j], i + 1});
                        ans[S[it.i][j]][i + 1] = tmp;
                    }
                }
                if (T.empty()) {
                    break;
                }
                TMP = T.front();
            }
        }

        // get ans
        for (int i = 1; i <= q; i++) {
            int r, c;
            scanf("%d%d", &r, &c);
            if (ans[c][r] == tmp) {
                printf("1\n");
            } else{
                printf("0\n");
            }
        }
    }
    return 0;
}
